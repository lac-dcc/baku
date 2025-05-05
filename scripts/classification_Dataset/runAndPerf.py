import subprocess
import csv
import argparse
import os
import sys
import signal
from contextlib import contextmanager

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
L1-icache-load-misses
LLC-loads
LLC-stores
LLC-store-misses
dTLB-loads
dTLB-store-misses"""

COMPILATION_TIMEOUT = 30    
EXECUTION_TIMEOUT = 10       
PERF_TIMEOUT = 10           

class TimeoutException(Exception):
    pass

@contextmanager
def time_limit(seconds):
    def signal_handler(signum, frame):
        raise TimeoutException("Timed out!")
    signal.signal(signal.SIGALRM, signal_handler)
    signal.alarm(seconds)
    try:
        yield
    finally:
        signal.alarm(0)


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

def run_perf_stat(folder_with_classes, compiler, flags):

    os.makedirs('results', exist_ok=True)
    os.makedirs('bin', exist_ok=True)

    
    events_list = perf_events.strip().split('\n')

    for class_name in os.listdir(folder_with_classes):
        print(f"Actual Class: {class_name}")
        class_dir = f'{folder_with_classes}{class_name}'

        with open(f'results/results_{class_name}.csv', 'w', newline='') as csvfile:
            csv_writer = csv.writer(csvfile, delimiter=',')
            csv_writer.writerow(["Class","Program","Entry"] + events_list)
            
            if not os.path.isdir(class_dir):
                print(f"Error: Directory '{class_dir}' does not exist")
                return
            
            programs_dir = f'{class_dir}/sample'
            entrys_dir = f'{class_dir}/info'
                
            for program in os.listdir(programs_dir):
                source_path = os.path.join(programs_dir, program)
                executable_path = os.path.join("bin", f"{program}.out")
                
                # Compile
                try:
                    print(f'\t Compiling {program}')
                    subprocess.run([compiler] + flags + ["-o", executable_path, source_path],
                                check=True)
                except subprocess.CalledProcessError as e:
                    print(f"\t Failed to compile {program}: {e}")
                    continue
                    
                # Run perf
                if os.path.exists(executable_path):
                    try:
                        print(f'\t Running {program}')
                        for entry in os.listdir(entrys_dir):
                            source_entry_path = os.path.join(entrys_dir, entry)
                            
                            with open(source_entry_path, 'r') as input_file:
                                perf_cmd = [
                                    "perf", "stat",
                                    "-o", "temp.txt",
                                    "-x,",
                                    "-e", ','.join(events_list),
                                    executable_path
                                ]
                                
                                print("\t\t Running:", f" {program} < {entry}")
                                
                                try:
                                    with time_limit(EXECUTION_TIMEOUT):
                                        subprocess.run(perf_cmd, stdin=input_file, check=True,
                                                    stdout=subprocess.PIPE, stderr=subprocess.PIPE, 
                                                    timeout=PERF_TIMEOUT)
                                        
                                except (subprocess.TimeoutExpired, TimeoutException) as e:
                                    print(f"\t\t Timeout running {program} with {entry}")
                                    continue
                                except subprocess.CalledProcessError as e:
                                    print(f"\t\t Error running {program} with {entry}")
                                    continue
                                
                                # Processa resultados apenas se chegou até aqui
                                with open('temp.txt', 'r') as perf_result:
                                    perf_output = perf_result.read().strip()
                                    row = [class_name, program, entry]
                                    for line in perf_output.split('\n'):
                                        if line.strip() and not line.startswith('#'):
                                            parts = line.split(',')
                                            if parts:
                                                row.append(parts[0].strip())
                                    csv_writer.writerow(row)
                                
                                print(f"\t\t !Runing with {entry} completed!")
                                
                    except Exception as e:
                        print(f"Critical error with {program}: {e}")
                    finally:
                        if os.path.exists('temp.txt'):
                            os.remove('temp.txt')
                        subprocess.run(["pkill", "-f", executable_path], 
                                    stdout=subprocess.DEVNULL, 
                                    stderr=subprocess.DEVNULL)

if __name__ == "__main__":
    check_perf_permissions()
    
    parser = argparse.ArgumentParser(description='Run perf stat over a set of programs.')
    parser.add_argument('folder_with_classes', help='Path to the set of  the class.')
    parser.add_argument('compiler', help='Compiler name or path.')
    parser.add_argument('-f', '--flags', nargs='*', help='Compiler Flags')
    args = parser.parse_args()
    
    flags = [f'-{flag}' for flag in args.flags] if args.flags else []
    run_perf_stat(args.folder_with_classes, args.compiler, flags)