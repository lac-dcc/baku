#execution: python3 run_csmith_perf.py <numero de programas> --output_dir csmith_programs --perf_results_dir perf_results --compiler gcc -f O2

import subprocess
import csv
import os
import argparse

#perf events list
perf_events = """cpu-cycles
instructions
cache-references
cache-misses
branch-instructions
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
iTLB-load-misses"""

#generate CSmith programs 
def generate_csmith_program(output_file):
    try:
        subprocess.run(["csmith", "-o", output_file], check=True)
        return True
    except subprocess.CalledProcessError:
        print(f"Could't generate the program. Erro: {output_file}")
        return False

#compile the programns with gcc
def compile_program(source_file, binary_file, compiler, flags):
    try:
        subprocess.run([compiler, "-w"] + flags + ["-o", binary_file, source_file], check=True)
        return True
    except subprocess.CalledProcessError:
        print(f"Could't compile the program. Erro: {source_file}")
        return False

#measure perf performance stats
def measure_performance(binary_file, events_list):
    try:
        perf_command = ["perf", "stat", "-o", "temp.txt", "-x,"]
        perf_command += ["-e", ",".join(events_list), binary_file]
        subprocess.run(perf_command, stdout=subprocess.PIPE, stderr=subprocess.PIPE, timeout=5)
        with open("temp.txt", "r") as perf_result:
            perf_output = perf_result.read().strip()
            perf_data = [binary_file]
            for line in perf_output.split("\n")[1:]:
                if line.strip():
                    perf_data.append(line.split(",")[0].strip())
            return perf_data
    except subprocess.TimeoutExpired:
        print(f"Program exceded time limit: {binary_file}")
        return None
    except subprocess.CalledProcessError:
        print(f"Could't get the program performance. Erro: {binary_file}")
        return None
    finally:
        if os.path.exists("temp.txt"):
            os.remove("temp.txt")

#save code in csv
def save_code_to_csv(csv_writer, program_name, program_path):
    try:
        with open(program_path, "r") as code_file:
            code_content = code_file.read()
            csv_writer.writerow([program_name, code_content])
    except Exception as e:
        print(f"Erro ao salvar o código do programa {program_name}: {e}")

def main(num_programs, output_dir, perf_results_dir, compiler, flags):
    os.makedirs(output_dir, exist_ok=True)
    os.makedirs(perf_results_dir, exist_ok=True)

    events_list = perf_events.strip().split("\n")

    #read CSV to save the perf stats
    with open(os.path.join(perf_results_dir, "results.csv"), "w", newline="") as perf_csvfile:
        perf_csv_writer = csv.writer(perf_csvfile, delimiter=",")
        perf_csv_writer.writerow(["Program"] + events_list)

        #read CSV with the main code
        with open(os.path.join(perf_results_dir, "source_codes.csv"), "w", newline="") as code_csvfile:
            code_csv_writer = csv.writer(code_csvfile, delimiter=",")
            code_csv_writer.writerow(["Program", "Source Code"])

            for i in range(1, num_programs + 1):
                print(f"Processing program {i}...")

                #Program generation
                c_file = os.path.join(output_dir, f"program_{i}.c")
                if not generate_csmith_program(c_file):
                    continue

                #Save the code in CSV
                save_code_to_csv(code_csv_writer, f"program_{i}.c", c_file)

                #Compile the program
                binary_file = os.path.join(output_dir, f"program_{i}.out")
                if not compile_program(c_file, binary_file, compiler, flags):
                    continue

                #Measure the perf performance
                perf_data = measure_performance(binary_file, events_list)
                if perf_data:
                    perf_csv_writer.writerow(perf_data)

    print(f"Done! Results uploaded to {os.path.join(perf_results_dir, 'results.csv')}")
    print(f"Code uploaded to {os.path.join(perf_results_dir, 'source_codes.csv')}")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Generate programs with CSmith and measure performance on perf.")
    parser.add_argument("num_programs", type=int, help="Programs amount to be generated.")
    parser.add_argument("--output_dir", default="csmith_programs", help="Directory to upload the programs generated.")
    parser.add_argument("--perf_results_dir", default="perf_results", help="Directory to upload the perf results.")
    parser.add_argument("--compiler", default="gcc", help="Compiler in use (such as, gcc or clang).")
    parser.add_argument("-f", "--flags", nargs="*", help="Compilation flags.")
    args = parser.parse_args()

    flags = [f"-{flag}" for flag in args.flags] if args.flags else []
    main(args.num_programs, args.output_dir, args.perf_results_dir, args.compiler, flags)