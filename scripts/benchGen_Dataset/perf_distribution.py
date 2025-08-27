import subprocess
import os
import argparse

perf_events = """
cpu-cycles
instructions
cache-references
cache-misses
"""


def parse_perf_output(output_lines: list, expected_events: list) -> dict:
    parsed_values = {}
    for line in output_lines:
        parts = line.split(",")
        if len(parts) >= 3:
            # CORREÇÃO: Remove o sufixo (:u, :k, etc.) do nome do evento
            event_name_from_perf = parts[2].strip().split(":")[0]

            # O valor do contador é o primeiro campo, remove vírgulas de milhares
            counter_value = parts[0].strip().replace(",", "")

            # Confere se o evento está na lista dos que estamos esperando
            if event_name_from_perf in expected_events:
                parsed_values[event_name_from_perf] = counter_value
    return parsed_values


def runPerf(executable_path: str) -> dict:
    events_list = perf_events.strip().split("\n")
    perf_command = ["perf", "stat", "-x,"]
    perf_command += ["-e", ",".join(events_list), f"./{executable_path}"]
    result = subprocess.run(perf_command, capture_output=True, check=False, text=True)
    perf_output_lines = result.stderr.strip().split("\n")
    collected_data = parse_perf_output(perf_output_lines, events_list)
    return collected_data


def executeMultipleRuns(executable_path: str, runs: int = 100) -> list[dict]:
    # warmup run
    for _ in range(3):
        runPerf(executable_path)

    all_runs_data = []

    # definitive runs
    for _ in range(runs):
        run_data = runPerf(executable_path)
        all_runs_data.append(run_data)

    return all_runs_data


def saveToCSV(data: list[dict], csv_path: str, program_name: str):
    with open(csv_path, "w") as f:
        f.write("program," + ",run," + ",".join(data[0].keys()) + "\n")
        i = 1
        for run in data:
            f.write(program_name + f",{i}," + ",".join(run.values()) + "\n")
            i += 1


def main():
    parser = argparse.ArgumentParser(
        description="Gets the distribution of perf stats of a given program."
    )
    parser.add_argument(
        "executable", type=str, help="Path to the executable to be measured."
    )
    parser.add_argument("machine", type=str, help="Machine name.")

    data = executeMultipleRuns(parser.parse_args().executable)
    machine = parser.parse_args().machine
    program_name = os.path.basename(parser.parse_args().executable)
    saveToCSV(data, f"perf_data_{program_name}_{machine}.csv", program_name)


if __name__ == "__main__":
    main()
