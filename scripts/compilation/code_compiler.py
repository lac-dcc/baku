import sys
import os
import subprocess

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Usage: python code_compiler.py <file> <optimizer>")
        sys.exit(1)

    file = sys.argv[1]
    optimizer = sys.argv[2]

    if not os.path.isfile(file):
        print(f"File '{file}' not found.")
        sys.exit(1)

    output = file.replace(".c", ".out")

    opt_flags = ["-O0", "-O1", "-O2", "-O3", "-Os", "-Ofast"]

    if optimizer not in opt_flags:
        print(f"WARNING: Invalid optimizer flag '{optimizer} (using -O0)'.")
        print("Valid flags are: -O0, -O1, -O2, -O3, -Os, -Ofast")

    try:
        result = subprocess.run(["gcc", optimizer, file, "-o", output],
                                capture_output=True, text=True)

        if result.returncode != 0:
            print(f"Error compiling '{file}':")
            print(result.stderr)
            # TODO: Register the file as not compiled in the data
            sys.exit(1)
        else:
            print(f"Compiled '{file}' to '{output}'")

    except Exception as e:
        print(f"Unexpected error: {e}")
        sys.exit(1)
