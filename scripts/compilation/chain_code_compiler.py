import sys
import os
import subprocess
# TODO: 1. Tests optimns sizes for diff -O? 2. Sample binaries sizes 3. Test diff versions  4. Test clang vs gcc 
def compilation(optimizer,folder,file):
    
    if not os.path.isfile(folder+'/'+file):
        print(f"File '{file}' not found.")
        sys.exit(1)

    output = file.replace(".c", ".out")

    opt_flags = ["-O0", "-O1", "-O2", "-O3", "-Os", "-Ofast"]


    if optimizer not in opt_flags:
        print(f"WARNING: Invalid optimizer flag '{optimizer} (using -O0)'.")
        print("Valid flags are: -O0, -O1, -O2, -O3, -Os, -Ofast")

    try:
        for n in range(1,11):
            result = subprocess.run(["gcc", optimizer, folder+'/'+file, "-o", folder+'/'+output],
                                    capture_output=True, text=True)

            if result.returncode != 0:
                print(f"Error compiling '{file}':")
                print(result.stderr)
                # TODO: Register the file as not compiled in the data, in n-nth repetitions, why it was not copiled and more
                sys.exit(1)
            else:
                print(f"Compiled '{file}' to '{output}'")
                #TODO: Register the binaries sizes and properties
            
            sys.exit(1)
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
        for opt in opt_flags: 
            for file in files:
                print(f"FILES:{file}")
                compilation(opt,folder,file)

