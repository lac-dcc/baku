import pandas as pd
import json
import glob
import os

# Load the CSV file containing perf event statistics
csv_file = "code/benchgen/results/bg_results.csv"  # Update with your actual CSV filename
df = pd.read_csv(csv_file)

# List all .txt files containing modularized C code
txt_files = {os.path.basename(f).replace(".txt", ""): f for f in glob.glob("code/benchgen/results/code/*.txt")}
print(txt_files)

# Create the final dataset
dataset = []

for idx, row in df.iterrows():
    program_name = row['Program']  # Get the program name from the CSV

    if program_name not in txt_files:
        print(f"Warning: No .txt file found for program {program_name}. Skipping...")
        continue

    txt_file_path = txt_files[program_name]  # Get the corresponding .txt file
    with open(txt_file_path, "r", encoding="utf-8") as f:
        content = f.read().strip()

    # Extract the C code and format it
    formatted_code = "<Program>\n"
    parts = content.split("```")  # Split using the ``` delimiter
    for part in parts:
        lines = part.strip().split("\n", 1)  # Separate filename and code
        if len(lines) == 2:
            filename, code = lines
            formatted_code += f"### File: {filename.strip()}\n{code.strip()}\n\n"
    formatted_code += "</Program>"

    # Construct the list of perf statistics
    events_list = f"""
    - CPU Cycles: {row['cpu-cycles']}
    - Instructions: {row['instructions']}
    - Cache References: {row['cache-references']}
    - Cache Misses: {row['cache-misses']}
    - Branch Instructions: {row['branch-instructions']}
    """.strip()

    # Construct the input text using the provided template
    input_text = f"""
Generate a C program optimized for the following Linux `perf` statistics:
{events_list}

- **Requirements**:
    1. The program must contain a main function that receives the data and invokes the processing logic.
    2. Address performance bottlenecks (e.g., cache misses, branch mispredictions) using:
    - Loop unrolling, SIMD intrinsics (AVX/SSE), memory alignment.
    - Data structure optimizations (e.g., cache-friendly layouts).
    3. **Fuzzer-Specific Constraints**:
    - Process raw bytes from `const uint8_t* data` and `size_t size` as input.
    - Avoid undefined behavior: validate buffer bounds, sanitize inputs.
    - Exclude I/O operations (e.g., `printf`, file access).
    4. Code Style:
    - Zero comments or explanations.
    - Use preprocessor directives only when critical (e.g., `#include <stdint.h>`).
    5. Enclose the code between <Program> tags.
    6. If modularized, include a ### File: <filename> tag before each code snippet.

- **Output Format**:
    <Program>
    {formatted_code.strip()}
    </Program>
"""

    # Add the entry to the dataset
    dataset.append({"input": input_text.strip(), "output": formatted_code.strip()})

# Save the dataset as JSONL
with open("dataset.jsonl", "w", encoding="utf-8") as jsonl_file:
    for entry in dataset:
        jsonl_file.write(json.dumps(entry) + "\n")

print("✅ JSONL file successfully created!")
