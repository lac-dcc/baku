import os
import argparse
import subprocess
import csv
from scipy import stats
import numpy as np


OUTPUT_DIR = "../../code/benchgen/texts/"

perf_events = """
cpu-cycles
instructions
cache-references
cache-misses
"""

def parse_perf_output(output_lines: list, expected_events: list) -> dict:
    """
    Analisa as linhas de saída do perf stat (formato -x,) e extrai os valores dos eventos.
    """
    parsed_values = {}
    for line in output_lines:
        parts = line.split(',')
        if len(parts) >= 3:
            # CORREÇÃO: Remove o sufixo (:u, :k, etc.) do nome do evento
            event_name_from_perf = parts[2].strip().split(':')[0]
            
            # O valor do contador é o primeiro campo, remove vírgulas de milhares
            counter_value = parts[0].strip().replace(',', '')
            
            # Confere se o evento está na lista dos que estamos esperando
            if event_name_from_perf in expected_events:
                parsed_values[event_name_from_perf] = counter_value
    return parsed_values


def runPerf(executable_path: str) -> dict:
    events_list = perf_events.strip().split('\n')
    perf_command = ["perf", "stat", "-x,"]
    perf_command += ["-e", ','.join(events_list), executable_path]
    result = subprocess.run(perf_command, capture_output=True, check=False, text=True)
    perf_output_lines = result.stderr.strip().split('\n')
    collected_data = parse_perf_output(perf_output_lines, perf_events)
    return collected_data

def analysePerf(executable_path: str, csv_path:str='perf_data.csv', runs:int=30, confidence:float=0.95):

    all_runs_data_raw = {event: [] for event in perf_events.strip().split('\n')}
    program_name = os.path.basename(executable_path)

    # warmup:
    warmup_runs = max(2, int(runs*0.1))
    for _ in range(warmup_runs):
        runPerf(executable_path)

    # real measure:
    successful_runs_count = 0
    for i in range(runs):
        results = runPerf(executable_path)
        if results:
            successful_runs_count += 1
            for event, value_str in results.items():
                try:
                    # Converte o valor para float para cálculos numéricos.
                    # Assegura que o evento está na nossa lista esperada
                    if event in all_runs_data_raw:
                        all_runs_data_raw[event].append(float(value_str))
                    else:
                        print(f"\n  Aviso: Evento '{event}' não esperado na lista de medição para '{program_name}'. Ignorando.")
                except (ValueError, KeyError):
                    print(f"\n  Aviso: Valor não numérico '{value_str}' para '{event}' na Medição {i+1}. Ignorando na análise.")
        else:
            print(f"\n  Aviso: Falha na Medição {i+1} de '{program_name}'. Dados desta medição não incluídos na análise.")
    print(f"\n  {successful_runs_count} de {runs} medições concluídas com sucesso para '{program_name}'.")

    # 3. Calcular as estatísticas consolidadas
    consolidated_stats = {'Program': program_name}
    
    for event, data_points in all_runs_data_raw.items():
        if not data_points:
            # Se não houver dados para o evento, preenche com 'N/A'
            print(f"Aviso: Nenhum dado válido coletado para o evento '{event}' em '{program_name}'.")
            consolidated_stats[f'{event}_mean'] = 'N/A'
            consolidated_stats[f'{event}_std_dev'] = 'N/A'
            consolidated_stats[f'{event}_ic_low'] = 'N/A'
            consolidated_stats[f'{event}_ic_high'] = 'N/A'
            continue

        data_array = np.array(data_points)
        mean_val = np.mean(data_array)
        std_dev = np.std(data_array) 

        consolidated_stats[f'{event}_mean'] = mean_val
        consolidated_stats[f'{event}_std_dev'] = std_dev

        # Calcula o Intervalo de Confiança (IC)
        if len(data_points) >= 2: # Pelo menos 2 pontos para calcular erro padrão e IC
            try:
                confidence_interval = stats.t.interval(
                    confidence,
                    len(data_points) - 1,  # Graus de liberdade
                    loc=mean_val,
                    scale=stats.sem(data_array) # Erro padrão da média
                )
                consolidated_stats[f'{event}_ic_low'] = confidence_interval[0]
                consolidated_stats[f'{event}_ic_high'] = confidence_interval[1]
            except Exception as e:
                print(f"Erro ao calcular IC para '{event}' em '{program_name}': {e}. Definindo como 'ERROR'.")
                consolidated_stats[f'{event}_ic_low'] = 'ERROR'
                consolidated_stats[f'{event}_ic_high'] = 'ERROR'
        else:
            print(f"Aviso: Poucos pontos de dados ({len(data_points)}) para calcular IC para '{event}' em '{program_name}'. Definindo como 'N/A'.")
            consolidated_stats[f'{event}_ic_low'] = 'N/A'
            consolidated_stats[f'{event}_ic_high'] = 'N/A'

    # 4. Escrever no CSV Final
    # Determina se o cabeçalho precisa ser escrito
    write_header = not os.path.exists(csv_path) or os.stat(csv_path).st_size == 0

    # Construir o cabeçalho dinamicamente com base nos eventos e suas estatísticas
    header = ['Program']
    for event in perf_events.strip().split('\n'):
        header.extend([f'{event}_mean', f'{event}_std_dev', f'{event}_ic_low', f'{event}_ic_high'])

    with open(csv_path, 'a', newline='') as f: # Abre em modo 'append'
        csv_writer = csv.DictWriter(f, fieldnames=header)
        if write_header:
            csv_writer.writeheader()
        csv_writer.writerow(consolidated_stats)
    
    print(f"Estatísticas de '{program_name}' salvas em '{csv_path}'.")

def mergeAndPerf(programs: list, csvpath: str='perf_data.csv'):
    for program_path in programs:
        #Execute make in the directory
        subprocess.run(["make", "-C", program_path], check=True)
        executable = program_path.split('/')[-1]
        executable_path = os.path.join(program_path, executable)
        analysePerf(executable_path)
        
        # Merge all source files into a single file
        output_name = program_path.split('/')[-1]
        output_path = f"{OUTPUT_DIR}{output_name}.txt"
        with open(output_path, 'w', encoding='utf-8') as outfile:
            srcdir = os.path.join(program_path, 'src')
            for filename in sorted(os.listdir(srcdir)):
                if filename.endswith(".c") or filename.endswith(".h"):
                    file_path = os.path.join(srcdir, filename)
                    with open(file_path, 'r', encoding='utf-8') as infile:
                        outfile.write(f'```{filename}\n')
                        outfile.write(infile.read() + '\n')
                        outfile.write('```\n')

def main():
    parser = argparse.ArgumentParser(description="Compile, merge all source files and extract perf data given a list of programs")
    parser.add_argument("input_file", help="Text file containing the list of programs paths to be compiled and merged")
    args = parser.parse_args()
    programs : str = []

    with open(args.input_file, 'r') as f:
        for line in f:
            programs.append(line.strip())

    mergeAndPerf(programs)

if __name__ == "__main__":
    main()
