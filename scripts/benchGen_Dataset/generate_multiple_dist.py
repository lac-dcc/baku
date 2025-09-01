# This script generates multiples programs using benchgen, compiles them, runs them multiple times with perf to collect performance metrics, and saves the results to a CSV file.

from benchgen_creator import generate_program, compile_program
from perf_distribution import executeMultipleRuns, saveToCSV

import argparse
import os

ITERATIONS = "4"


def main():
    argparser = argparse.ArgumentParser(description="Generate benchmark datasets.")

    argparser.add_argument(
        "--benchgen_path", type=str, required=True, help="Path to the benchgen."
    )
    argparser.add_argument(
        "--output_path",
        type=str,
        default="data/prediction_test/bg_distributions/",
        help="Path to save the generated data.",
    )

    argparser.add_argument(
        "--code_path",
        type=str,
        default="code/benchgen/src",
        help="Path to the benchgen code.",
    )

    argparser.add_argument(
        "--range_low", type=str, default=1, help="Starting index for program names."
    )

    argparser.add_argument(
        "--range_high", type=str, default=10, help="Ending index for program names."
    )

    argparser.add_argument(
        "--grammars_path",
        type=str,
        default="code/benchgen/grammars/",
        help="Path to the grammars.",
    )

    argparser.add_argument(
        "--machine",
        type=str,
        default=os.uname().nodename,
        help="Machine name for output file naming.",
    )

    benchgen_path = argparser.parse_args().benchgen_path
    code_path = argparser.parse_args().code_path
    output_path = argparser.parse_args().output_path
    range_low = int(argparser.parse_args().range_low)
    range_high = int(argparser.parse_args().range_high)
    grammars_path = argparser.parse_args().grammars_path

    os.makedirs(output_path, exist_ok=True)
    os.makedirs(code_path, exist_ok=True)

    for i in range(range_low, range_high + 1):
        program_name = f"program_{i}"
        print(f"Generating {program_name}...")
        try:
            program_path = generate_program(
                benchgen_path,
                "4",
                f"{grammars_path}rules{i}.txt",
                f"{grammars_path}seed{i}.txt",
                program_name,
                code_path,
            )
            executable_path = compile_program(program_path)
            data = executeMultipleRuns(executable_path)
            machine = os.uname().nodename
            saveToCSV(
                data,
                f"{output_path}/perf_data_{program_name}_{machine}.csv",
                program_name,
            )
            print(f"Data for {program_name} saved successfully.")
        except Exception as e:
            print(f"Error processing {program_name}: {e}")


if __name__ == "__main__":
    main()
