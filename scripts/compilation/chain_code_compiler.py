import sys
import os
import subprocess
sys.path.append("../classes")
from data_loader import DataLoader

# TODO: 1. Test diff versions  3. Test clang vs gcc 

def get_binary_size(file_path):
    return os.path.getsize(file_path) if os.path.exists(file_path) else 0

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

def compilation(optimizer,folder,file):

    compilation_df = DataLoader('../../data/Time&Code/compilation.csv')

    if not os.path.isfile(folder+'/'+file):
        print(f"File '{file}' not found.")
        sys.exit(1)


    if not has_main_function(folder+'/'+file):
        get_compilable_code(folder,file)
    
    output = file.replace(".c", ".out")

    opt_flags = ["-O0", "-O1", "-O2", "-O3", "-Os", "-Ofast"]


    if optimizer not in opt_flags:
        print(f"WARNING: Invalid optimizer flag '{optimizer} (using -O0)'.")
        print("Valid flags are: -O0, -O1, -O2, -O3, -Os, -Ofast")

    try:
        for n in range(1,11):
            result = subprocess.run(["gcc", optimizer, folder+'/'+file, "-o", folder+'/output/'+output],
                                    capture_output=True, text=True)

            if result.returncode != 0:
                print(f"Error compiling '{file}':")
                print(result.stderr)
                # TODO: Register the file as not compiled in the data, in n-nth repetitions, why it was not copiled and more
                sys.exit(1)
            else:
                print(f"Compiled '{file}' to '{output}' -> {optimizer}")
                bin_size = get_binary_size(folder+'/output/'+output)
                row=[folder[23:],file,optimizer,bin_size]
                compilation_df.new_row(row)
                print(f"Binary Size: {bin_size}")
            
        compilation_df.save()
    except Exception as e:
        print(f"Unexpected error: {e}")
        sys.exit(1)


if __name__ == "__main__":

    if len(sys.argv) < 2:
        print("Usage: python chain_code_compiler.py <file_folder>")
        sys.exit(1)

    file_folder = sys.argv[1]

    if not os.path.isdir(file_folder):
        print(f"Folder '{file_folder}' not found.")
        sys.exit(1)

    for folder, dirs, files in os.walk(file_folder):
        opt_flags = ["-O0", "-O1", "-O2", "-O3", "-Os", "-Ofast"]
        print(files)
        files.sort()        
        print(files)
        if not os.path.exists(folder+"/output"):
            os.makedirs(folder+"/output")
            for file in files:
                for opt in opt_flags: 
                    print(f"File:{file}")
                    compilation(opt,folder,file)
        else:
            print("Code had already been compiled. Delete the past *.out for run the script again.")
            break

