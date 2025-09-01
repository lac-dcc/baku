# This script generates and compile programs with benchgen

import argparse
import subprocess
import os


def generate_program(benchgen_path, iterations, rule, seed, program_name, output_path):
    command = [benchgen_path, iterations, rule, seed, program_name, "array"]
    path = os.path.join(output_path, program_name)
    subprocess.run(command, check=True)
    try:
        subprocess.run(["mv", f"{program_name}/", f"{output_path}/"], check=True)
    except Exception as e:
        print(f"Error moving directory: {e}")
        raise

    return path


def compile_program(path):
    subprocess.run(["make", "-C", path], check=True)
    return os.path.join(path, path.split("/")[-1])


def main():
    argparser = argparse.ArgumentParser(description="Generate benchmark datasets.")

    argparser.add_argument(
        "--benchgen_path", type=str, required=True, help="Path to the benchgen."
    )

    argparser.add_argument(
        "--output_path",
        type=str,
        required=True,
        help="Path to save the generated programs.",
    )

    argparser.add_argument(
        "--name", type=str, required=True, help="Name of the program."
    )

    argparser.add_argument(
        "--iterations",
        type=str,
        required=True,
        help="Number of iterations for benchgen.",
    )
    argparser.add_argument(
        "--rule", type=str, required=True, help="Rule to be used by benchgen."
    )
    argparser.add_argument(
        "--seed", type=str, required=True, help="Seed for random generation."
    )

    program = generate_program(
        argparser.parse_args().benchgen_path,
        argparser.parse_args().iterations,
        argparser.parse_args().rule,
        argparser.parse_args().seed,
        argparser.parse_args().name,
        argparser.parse_args().output_path,
    )

    final_path = compile_program(program)
    print(f"Generated and compiled program at: {final_path}")


if __name__ == "__main__":
    main()
