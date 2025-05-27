import os
import subprocess
import argparse
import time
import csv

def get_binary_size(file_path):
        if not os.path.exists(file_path):
            return 0
        result = subprocess.run(['size', file_path], capture_output=True, text=True, check=True)
        lines = result.stdout.splitlines()
        
        if len(lines) < 2:
            return 0
        
        parts = lines[1].split()
        return int(parts[0])

def verify_regression(binary_dir: str, binary_file: str) -> bool:
    # Verifica se o diretório existe
    if not os.path.exists(binary_dir):
        print(f"Directory {binary_dir} does not exist.")    
        return False
    
    optmization_flags = ['-O0', '-O1', '-O2', '-O3', '-Os', '-Ofast']
    binary_sizes = {}
    for opt_flag in optmization_flags:
        binary_path = os.path.join(binary_dir, f"{binary_file}{opt_flag}.out")
        size = get_binary_size(binary_path)
        binary_sizes[opt_flag] = size
        print(f"Binary size for {opt_flag}: {size} bytes")
        
    for opt_flag in optmization_flags:
        if opt_flag != '-Os' and int(binary_sizes['-Os']) - int(binary_sizes[opt_flag]) > 32:
            return True
    # Check for regression
    return False

def compile_each_c_file(directory):

    start_time = time.time()
    
    opt_flags = ["-O0", "-O1", "-O2", "-O3", "-Os", "-Ofast"]

    if not os.path.isdir(directory):
        print(f"Erro: o diretório '{directory}' não existe.")
        return

    c_files = []
    for root, _, files in os.walk(directory):
        for f in files:
            if f.endswith(".c"):
                c_files.append(os.path.join(root, f))
    if not c_files:
        print("Nenhum arquivo .c encontrado no diretório.")
        return
    
    successfulCompiles = 0
    totalTries = 0
    regressions = 0;

    for c_file in c_files:
        compiled = False
        totalTries += 1
        output_name = os.path.splitext(os.path.basename(c_file))[0]

        for opt_flag in opt_flags:
            source_path = c_file  # <-- Aqui é o caminho já completo
            output_path = os.path.join(directory, output_name + opt_flag + ".out")

            compile_cmd = ["gcc-13", opt_flag, source_path, "-fsanitize=address", "-o", output_path]

            print(f"Compilando {c_file} com {opt_flag} -> {output_name}")
            result = subprocess.run(compile_cmd)

            if result.returncode == 0:
                if compiled == False:
                    compiled = True
                    successfulCompiles += 1
                print(f"✓ {output_name} ({opt_flag}) compilado com sucesso.")
            else:
                print(f"✗ Erro ao compilar {c_file} com {opt_flag}.")
            
        if verify_regression(directory, output_name) and compiled:
            regressions += 1

    print(f'Programas compilados: {successfulCompiles}/{totalTries}')
    end_time = time.time()
    elapsed_time = end_time - start_time

    return totalTries, successfulCompiles, elapsed_time, regressions

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Compile C files with various optimization flags and verify regressions.")
    parser.add_argument("directory", type=str, help="Directory containing C files to compile.")
    parser.add_argument("model", type=str, help="Model name.")
    parser.add_argument("size", type=str, help="Model size.")
    parser.add_argument("type", type=str, help="Type of generation (e.g chain or single).")
    args = parser.parse_args()

    if not os.path.exists(args.directory):
        print(f"Directory {args.directory} does not exist.")
        exit(1)

    total_tries, successful_compiles, elapsed_time, regressions = compile_each_c_file(args.directory)

    output_csv_path = os.path.join("" , f"compilation_results{args.type}.csv")

    with open(output_csv_path, mode='a', newline='') as csv_file:
        file_is_empty = os.stat(output_csv_path).st_size == 0
        csv_writer = csv.writer(csv_file)
        if file_is_empty:
            csv_writer.writerow(['model', 'size', 'compiled', 'total', 'proportion', 'regressions', 'time'])
        csv_writer.writerow([args.model, args.size, successful_compiles, total_tries, successful_compiles / total_tries, regressions, elapsed_time])

    print(f"Results saved to {output_csv_path}")

    print(f"\nCompilation Summary for {args.model} ({args.size}):")
    print(f"\nTotal tries: {total_tries}")
    print(f"Successful compiles: {successful_compiles}")
    print(f"Elapsed time: {elapsed_time:.2f} seconds")
    print(f"Regressions found: {regressions}")

