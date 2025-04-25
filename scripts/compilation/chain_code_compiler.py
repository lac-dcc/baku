import sys
import os
import subprocess
from pathlib import Path
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

def compilation(compiler, version, optimizer, folder, file):
    compilation_df = DataLoader('../../data/Time&Code/compilation.csv')
    
    if not os.path.isfile(folder+'/'+file):
        print(f"File '{file}' not found.")
        sys.exit(1)

    if not has_main_function(folder+'/'+file):
        get_compilable_code(folder, file)
    
    output = file.replace(".c", f".{version}.out")

    try:
        bin_array = []
        for _ in range(10):
            cmd = [compiler] if version == "default" else [f"{compiler}-{version}"]
            cmd.extend([optimizer, folder+'/'+file, "-o", folder+'/output/'+output])
            
            result = subprocess.run(cmd, capture_output=True, text=True)

            if result.returncode != 0:
                print(f"Error compiling '{file}' with {compiler} {version}:")
                print(result.stderr)
                #TODO: write the compilation errors
                return
            else:
                print(f"Compiled '{file}' to '{output}' -> {compiler}-{version} {optimizer}")
                bin_size = get_binary_size(folder+'/output/'+output)
                bin_array.append(bin_size)
                print(f"Binary Size: {bin_size}")
        
        min_bin = min(bin_array)
        max_bin = max(bin_array)
        mean = sum(bin_array) / len(bin_array)

        row = [folder[17:], file, f"{compiler}",f"{version}", optimizer, min_bin, max_bin, mean]
        compilation_df.new_row(row)
        compilation_df.save()
    except Exception as e:
        print(f"Unexpected error: {e}")
        sys.exit(1)

def main():
    if len(sys.argv) < 2:
        print("Usage: python chain_code_compiler.py <file_folder>")
        sys.exit(1)

    file_folder = sys.argv[1]

    if not os.path.isdir(file_folder):
        print(f"Folder '{file_folder}' not found.")
        sys.exit(1)

    COMPILERS = {
        "gcc": ["9", "10", "11", "12"]
    }

    OPT_FLAGS = ["-O0", "-O1", "-O2", "-O3", "-Os", "-Ofast"]

    for folder, _, files in os.walk(file_folder):
        files.sort()
        if not os.path.exists(folder+"/output"):
            os.makedirs(folder+"/output")
            for file in files:
                for compiler, versions in COMPILERS.items():
                    for version in versions:
                        for opt in OPT_FLAGS:
                            print(f"File:{file} - Compiler: {compiler}-{version} - Opt: {opt}")
                            compilation(compiler, version, opt, folder, file)

if __name__ == "__main__":
    main()