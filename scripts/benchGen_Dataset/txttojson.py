import pandas as pd
import json
import glob
import os
import random

# Load the CSV file containing perf event statistics
csv_file = "../../code/benchgen/results/bg_results.csv"  
df = pd.read_csv(csv_file)

# List all .txt files containing modularized C code
txt_files = {os.path.basename(f).replace(".txt", ""): f for f in glob.glob("../../code/benchgen/results/code/*.txt")}

# Create the finals datasets
training_dataset = []
testing_dataset = []
eval_dataset = []

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

Enclose the code between <Program> tags.
"""
    reponse_text =  f"""
        <Program>
            {formatted_code.strip()}
        </Program>
    """

    # Add the entry to the dataset
    dataset.append({"instruction": input_text.strip(), "response": formatted_code.strip()})


n=250
random.shuffle(dataset)
chunks = [dataset[i:i + n] for i in range(0, len(dataset), n)]
training_dataset = chunks[0]
testing_dataset = chunks[1]
eval_dataset = chunks[2]


# Save the dataset as JSONL
with open("../../data/fine_tunning/training.jsonl", "w", encoding="utf-8") as jsonl_file:
    for entry in training_dataset:
        jsonl_file.write(json.dumps(entry) + "\n")
        
with open("../../data/fine_tunning/testing.jsonl", "w", encoding="utf-8") as jsonl_file:
    for entry in testing_dataset:
        jsonl_file.write(json.dumps(entry) + "\n")
        
with open("../../data/fine_tunning/evaluating.jsonl", "w", encoding="utf-8") as jsonl_file:
    for entry in eval_dataset:
        jsonl_file.write(json.dumps(entry) + "\n")
        

print("✅ JSONL files successfully created!")
