import os
import argparse
import subprocess
import csv

perf_events = """
cpu-cycles
instructions
cache-references
cache-misses
branch-instructions
"""

"""
branch-misses
page-faults
branch-loads
branch-load-misses
L1-dcache-loads
L1-dcache-load-misses
L1-dcache-stores
L1-dcache-store-misses
L1-dcache-prefetches
L1-dcache-prefetch-misses
L1-icache-loads
L1-icache-load-misses
L1-icache-prefetches
L1-icache-prefetch-misses
LLC-loads
LLC-load-misses
LLC-stores
LLC-store-misses
LLC-prefetch-misses
dTLB-loads
dTLB-load-misses
dTLB-stores
dTLB-store-misses
dTLB-prefetches
dTLB-prefetch-misses
iTLB-loads
iTLB-load-misses
"""

def runPerf(executable_path):
    events_list = perf_events.strip().split('\n')
    results_path = 'perf_results.csv'

    write_header = not os.path.exists(results_path) or os.stat(results_path).st_size == 0

    with open(results_path, 'a', newline='') as f:
        csv_writer = csv.writer(f, delimiter=',')
        if write_header:
            csv_writer.writerow(["Program"] + events_list)
        
        if os.path.exists(executable_path):
            perf_command = ["perf", "stat", "-o", "temp.txt", "-x,"]
            perf_command += ["-e", ','.join(events_list), executable_path]
            subprocess.run(perf_command, stdout=subprocess.PIPE)

            with open('temp.txt', 'r') as perf_result:
                perf_output = perf_result.read().strip()
                program = os.path.basename(executable_path)
                perf_result_row = [program]
                for line in perf_output.split('\n')[1:]:
                    if line.strip():
                        perf_result_row.append(line.split(',')[0].strip())
                csv_writer.writerow(perf_result_row)

            os.remove('temp.txt')
        else:
            print(f"Executable {executable_path} not found")

def mergeAndPerf(programs):
    for program_path in programs:
        #Execute make in the directory
        # subprocess.run(["make", "-C", program_path], check=True)
        executable = "myprogram"
        executable_path = os.path.join(program_path, executable)
        runPerf(executable_path)
        """
        output_name = program_path.split('/')[-1]
        output_path = f"code/benchgen/results/code/{output_name}.txt"
        with open(output_path, 'w', encoding='utf-8') as outfile:
            srcdir = os.path.join(program_path, 'src')
            for filename in sorted(os.listdir(srcdir)):
                if filename.endswith(".c") or filename.endswith(".h"):
                    file_path = os.path.join(srcdir, filename)
                    with open(file_path, 'r', encoding='utf-8') as infile:
                        outfile.write(f'```{filename}\n')
                        outfile.write(infile.read() + '\n')
                        outfile.write('```\n')"""

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Compile, merge all source files and extract perf data given a list of programs")
    parser.add_argument("input_file", help="Text file containing the list of programs paths to be compiled and merged")
    args = parser.parse_args()
    programs : str = []
    with open(args.input_file, 'r') as f:
        for line in f:
            programs.append(line.strip())
    # runPerf(programs)
    mergeAndPerf(programs)