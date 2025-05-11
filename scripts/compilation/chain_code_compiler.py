import sys
import os
import time
import subprocess
sys.path.append("../classes")
from data_loader import DataLoader

# TODO: 1. Test diff versions  3. Test clang vs gcc 

def get_binary_size(file_path):
    if not os.path.exists(file_path):
        return 0
    try:
        result = subprocess.run(['size', file_path], capture_output=True, text=True, check=True)
        lines = result.stdout.splitlines()
        
        if len(lines) < 2:
            return 0
        
        parts = lines[1].split()

        return int(parts[0])
    
    except subprocess.CalledProcessError as e:
        print(f"Erro ao executar o comando 'size': {e.stderr}")
        return 0
    except Exception as e:
        print(f"Erro inesperado: {e}")
        return 0

def has_main_function(file_path):
    with open(file_path, "r") as f:
        content = f.read()
    return "int main" in content or "void main" in content

def get_compilable_code(folder,file):
    file_read = open(folder+'/'+file, "r+")
    file_content = file_read.read()
    file_read.close()

    main_template = """
    void main(){
        printf("%d",f(7));
    }
    """

    code= "#include<stdio.h> \n"+file_content+main_template

    file_write = open(folder+'/'+file, "w")
    file_write.write(code)
    file_write.close()

def get_available_gcc_versions():
    versions = []
    try:
       
        result = subprocess.run(["compgen", "-c", "gcc-"], capture_output=True, text=True, shell=True)
        if result.returncode == 0:
            versions = [v for v in result.stdout.split() if v.startswith('gcc-') and v[4].isdigit()]
        
        
        result = subprocess.run(["gcc", "--version"], capture_output=True, text=True)
        if result.returncode == 0:
            versions.append("gcc")  
    except Exception as e:
        print(f"Erro: {e}")
    
    return sorted(list(set(versions)))

def compilation(compiler, version, optimizer, folder, file, compiler_path):
    compilation_df = DataLoader(compiler_path)
    
    if not os.path.isfile(folder+'/'+file):
        print(f"File '{file}' not found.")
        sys.exit(1)

    if not has_main_function(folder+'/'+file):
        get_compilable_code(folder, file)
    
    output = file.replace(".c", f".{version}.out")

    try:
        bin_array = []
        time_array = []
        for _ in range(10):
            cmd = [compiler] if version == "default" else [f"{compiler}-{version}"]
            cmd.extend([optimizer, folder+'/'+file, "-o", folder+'/output/'+output])
            
            begin_time = time.time()
            result = subprocess.run(cmd, capture_output=True, text=True)
            end_time = time.time()

            time_array.append(abs(end_time - begin_time))

            if result.returncode != 0:
                print(f"Error compiling '{file}' with {compiler} {version}:")
                print(result.stderr)
                return False
            else:
                print(f"Compiled '{file}' to '{output}' -> {compiler}-{version} {optimizer}")
                bin_size = get_binary_size(folder+'/output/'+output)
                bin_array.append(bin_size)
                print(f"Binary Size: {bin_size}")
        
        min_bin = min(bin_array)
        max_bin = max(bin_array)
        mean = sum(bin_array) / len(bin_array)
        time_spent = sum(time_array)

        row = [folder.split('/')[5], file, f"{compiler}",f"{version}", optimizer, min_bin, max_bin, mean,time_spent]
        compilation_df.new_row(row)
        compilation_df.save()

        return True
    except Exception as e:
        print(f"Unexpected error: {e}")
        sys.exit(1)

def main():
    if len(sys.argv) < 5:
        print("Usage: python chain_code_compiler.py <file_folder> <compilation_csv_path> <model_name> <size>")
        sys.exit(1)

    file_folder = sys.argv[1]
    compiler_path = sys.argv[2]
    model_name = sys.argv[3]
    size = sys.argv[4]

    if not os.path.isdir(file_folder):
        print(f"Folder '{file_folder}' not found.")
        sys.exit(1)

    COMPILERS = {
        "gcc": ["9", "10", "11", "12"]
    }

    OPT_FLAGS = ["-O0", "-O1", "-O2", "-O3", "-Os", "-Ofast"]

    run = 0
    total = 0

    for folder, _, files in os.walk(file_folder):
        files.sort()
        if not os.path.exists(folder+"/output"):
            os.makedirs(folder+"/output")
            for file in files:
                total = total + 1
                compiled = False
                for compiler, versions in COMPILERS.items():
                    for version in versions:
                        for opt in OPT_FLAGS:
                            print(f"File:{file} - Compiler: {compiler}-{version} - Opt: {opt}")
                            result = compilation(compiler, version, opt, folder, file, compiler_path)
                            compiled = compiled or result
                if compiled: 
                    run = run + 1

    cm = DataLoader("../../data/TimeCodeExperiment/compiled_models.csv")
    cm.new_row([model_name,size,run, total, run/total])
    cm.save()


if __name__ == "__main__":
    main()