import subprocess
import csv
import argparse
import os
import sys

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

def check_perf_permissions():
    try:
        subprocess.run(["perf", "stat", "true"], 
                      check=True, 
                      stdout=subprocess.PIPE, 
                      stderr=subprocess.PIPE)
    except subprocess.CalledProcessError:
        print("Error: Permission issues with perf. Please run:")
        print("  sudo sh -c 'echo -1 > /proc/sys/kernel/perf_event_paranoid'")
        print("Or for permanent solution:")
        print("  echo 'kernel.perf_event_paranoid = -1' | sudo tee -a /etc/sysctl.conf")
        print("  sudo sysctl -p")
        sys.exit(1)

def run_perf_stat(programs_dir, compiler, flags):
    os.makedirs('results', exist_ok=True)
    os.makedirs('bin', exist_ok=True)
    
    events_list = perf_events.strip().split('\n')
    
    with open('results/results.csv', 'w', newline='') as csvfile:
        csv_writer = csv.writer(csvfile, delimiter=',')
        csv_writer.writerow(["Program"] + events_list)
        
        if not os.path.isdir(programs_dir):
            print(f"Error: Directory '{programs_dir}' does not exist")
            return
            
        for program in os.listdir(programs_dir):
            source_path = os.path.join(programs_dir, program)
            executable_path = os.path.join("bin", f"{program}.out")
            
            # Compile
            try:
                print(f'Compiling {program}')
                subprocess.run([compiler] + flags + ["-o", executable_path, source_path],
                              check=True)
            except subprocess.CalledProcessError as e:
                print(f"Failed to compile {program}: {e}")
                continue
                
            # Run perf
            if os.path.exists(executable_path):
                try:
                    print(f'Running {program}')
                    perf_cmd = [
                        "perf", "stat",
                        "-o", "temp.txt",
                        "-x,",
                        "-e", ','.join(events_list),
                        executable_path
                    ]
                    subprocess.run(perf_cmd, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
                    
                    # Process results
                    with open('temp.txt', 'r') as perf_result:
                        perf_output = perf_result.read().strip()
                        row = [program]
                        for line in perf_output.split('\n'):
                            if line.strip() and not line.startswith('#'):
                                parts = line.split(',')
                                if parts:  # Take the first column (event count)
                                    row.append(parts[0].strip())
                        csv_writer.writerow(row)
                        
                except subprocess.CalledProcessError as e:
                    print(f"Failed to run perf on {program}: {e}")
                finally:
                    if os.path.exists('temp.txt'):
                        os.remove('temp.txt')

if __name__ == "__main__":
    check_perf_permissions()
    
    parser = argparse.ArgumentParser(description='Run perf stat over a set of programs.')
    parser.add_argument('programs_dir', help='Path to the set of programs.')
    parser.add_argument('compiler', help='Compiler name or path.')
    parser.add_argument('-f', '--flags', nargs='*', help='Compiler Flags')
    args = parser.parse_args()
    
    flags = [f'-{flag}' for flag in args.flags] if args.flags else []
    run_perf_stat(args.programs_dir, args.compiler, flags)