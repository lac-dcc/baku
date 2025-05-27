import sys
import os
import time
import subprocess
import shutil
import pandas as pd
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
    with open(file_path, "r", encoding="utf-8", errors="replace") as f:
        content = f.read()
    return "int main" in content or "void main" in content


def get_compilable_code(folder, file):
    path = os.path.join(folder, file)

    with open(path, "r", encoding="latin1") as file_read:
        file_content = file_read.read()

    main_template = """
        int main() {
            printf("%d", f(7));
            return 0;
        }
        """

    code = "#include<stdio.h>\n" + file_content + main_template

    with open(path, "w", encoding="latin1") as file_write:
        file_write.write(code)


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

def compilation(compiler, version, optimizer, folder, file, compiler_path,chain_type):
    completition = ''

    if(chain_type):
        completition='chain'
    else:
        completition='singles'

    compilation_df = DataLoader(f'{compiler_path}compilation_{completition}.csv')
    
    if not os.path.isfile(folder+'/'+file):
        print(f"File '{file}' not found.")
        sys.exit(1)

    if not has_main_function(folder+'/'+file):
        get_compilable_code(folder, file)
    
    output = file.replace(".c", f".{version}.out")

    try:
        bin_array = []
        time_array = []
        
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

        if(chain_type):
            row = [folder.split('/')[5], file, f"{compiler}",f"{version}", optimizer, min_bin, max_bin, mean,time_spent]
            compilation_df.new_row(row)
            compilation_df.save()
        else:
            row = [file.split('.')[0], f"{compiler}",f"{version}", optimizer, min_bin, max_bin, mean,time_spent]
            compilation_df.new_row(row)
            compilation_df.save()

        return True
    except Exception as e:
        print(f"Unexpected error: {e}")
        sys.exit(1)

def main():
    if len(sys.argv) < 6:
        print("Usage: python chain_code_compiler.py <file_folder> <data_path> <string chain_or_single> <model_name> <size> ")
        sys.exit(1)

    file_folder = sys.argv[1]
    compiler_path = sys.argv[2]
    chain = sys.argv[3]
    model_name = sys.argv[4]
    size = sys.argv[5]

    chain_type = True

    if "single" in chain:
        chain_type = False

    if not os.path.isdir(file_folder):
        print(f"Folder '{file_folder}' not found.")
        sys.exit(1)

    COMPILERS = {
        "gcc": ["14"]
    }

    OPT_FLAGS = ["-O0", "-O1", "-O2", "-O3", "-Os", "-Ofast"]

    run = 0
    total = 0

    
    for folder, _, files in os.walk(file_folder):
        files.sort()
        if not os.path.exists(folder+"/output"):
            os.makedirs(folder+"/output")
        elif os.path.exists(folder+"/output"):
            shutil.rmtree(folder+"/output")
            os.makedirs(folder+"/output")
        for file in files:
            total = total + 1
            compiled = False
            
            for opt in OPT_FLAGS:
                if not file.endswith(".c"):
                    continue
                print(f"File:{file} - Compiler: {'gcc-14'} - Opt: {opt}")
                compiled = compilation('gcc', '14', opt, folder, file, compiler_path,chain_type)
            if compiled: 
                run = run + 1


    if chain_type:
        cm = pd.read_csv("../../data/TimeCodeExperiment/compiled_chain_models.csv")
        data = pd.DataFrame({
            'model': [model_name],
            'size': [size],
            'compiled': [run],
            'total': [total],
            'proportion_compiled': [0 if total == 0 else run / total]
        })
        cm = pd.concat([cm, data], ignore_index=True)
        cm.to_csv("../../data/TimeCodeExperiment/compiled_chain_models.csv", index=False)
        print(cm)

    else:
        cm = pd.read_csv("../../data/TimeCodeExperiment/compiled_single_models.csv")
        data = pd.DataFrame({
            'model': [model_name],
            'size': [size],
            'compiled': [run],
            'total': [total],
            'proportion_compiled': [0 if total == 0 else run / total]
        })
        cm = pd.concat([cm, data], ignore_index=True)
        cm.to_csv("../../data/TimeCodeExperiment/compiled_single_models.csv", index=False)
        print(cm)



if __name__ == "__main__":
    main()