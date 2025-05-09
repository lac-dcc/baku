import os
import subprocess
import argparse

def compile_each_c_file(directory):
    if not os.path.isdir(directory):
        print(f"Erro: o diretório '{directory}' não existe.")
        return

    c_files = [f for f in os.listdir(directory) if f.endswith(".c")]
    if not c_files:
        print("Nenhum arquivo .c encontrado no diretório.")
        return
    
    successfulCompiles = 0
    totalTries = 0

    for c_file in c_files:
        totalTries += 1
        source_path = os.path.join(directory, c_file)
        output_name = os.path.splitext(c_file)[0]  # Remove .c
        output_path = os.path.join(directory, output_name + ".out")

        compile_cmd = ["gcc", source_path, "-fsanitize=address", "-o", output_path]

        print(f"Compilando {c_file} -> {output_name}")
        result = subprocess.run(compile_cmd)

        if result.returncode == 0:
            successfulCompiles += 1
            print(f"✓ {output_name} compilado com sucesso.")
        else:
            print(f"✗ Erro ao compilar {c_file}.")

    print(f'Programas compilados: {successfulCompiles}/{totalTries}')

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Compila cada arquivo .c individualmente em um executável.")
    parser.add_argument("directory", help="Caminho para o diretório com os arquivos .c")
    args = parser.parse_args()

    compile_each_c_file(args.directory)

    print()
