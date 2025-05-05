import subprocess
import csv
import argparse
import os
import re

def natural_key(s):
    # Divide a string em partes numéricas e não numéricas
    return [int(text) if text.isdigit() else text.lower() for text in re.split(r'(\d+)', s)]



perf_events = """cpu-cycles
instructions
cache-references
cache-misses
branch-instructions
"""

"""
Eventos adicionais (comentados)
"""

def run_perf_on_out_files(program, runtimes):
    os.makedirs('results', exist_ok=True)
    events_list = perf_events.strip().split('\n')
    program_name = os.path.basename(program)
    results_csv = os.path.join('results', f'{program_name}.csv')

    write_header = not os.path.exists(results_csv) or os.stat(results_csv).st_size == 0

    with open(results_csv, 'w', newline='') as csvfile:
        csv_writer = csv.writer(csvfile, delimiter=',')
        csv_writer.writerow(["Program"] + events_list)
        
        executable_path = program
        print(f'Running perf on {program_name}')
        perf_command = [
            "perf", "stat", "-o", "temp.txt", "-x,",
            "-e", ','.join(events_list), executable_path
        ]
        for i in range (int(runtimes)):
            print(f"Running iteration {i + 1} of {runtimes}")
            subprocess.run(perf_command, stdout=subprocess.PIPE)
            if os.path.exists("temp.txt"):
                with open("temp.txt", 'r') as perf_result:
                    perf_output = perf_result.read().strip()
                    perf_result_row = [program_name]
                    for line in perf_output.split('\n')[1:]:
                        if line.strip():
                            perf_result_row.append(line.split(',')[0].strip())
                    csv_writer.writerow(perf_result_row)
                os.remove("temp.txt")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Run perf on all .out executables in a directory.")
    parser.add_argument("program_path", help="Path to the directory containing .out executables")
    parser.add_argument("runtimes", help="Number of times to run the program")
    args = parser.parse_args()

    run_perf_on_out_files(args.program_path, args.runtimes)
