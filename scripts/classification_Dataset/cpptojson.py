import pandas as pd
import json
import glob
import os
import random
import sys
import argparse

def create_dataset(class_dir):
    csv_file = "/results/results.csv" 
    df = pd.read_csv(csv_file)

            
    if not os.path.isdir(class_dir):
        print(f"Error: Directory '{class_dir}' does not exist")
        return
    
    programs_dir = f'{class_dir}/sample'

    
    cpp_files = [os.listdir(programs_dir)]

    # Create the finals datasets
    training_dataset = []
    testing_dataset = []

    dataset = []


    for _, row in df.iterrows():
        program_name = row['Program']  

        if program_name not in cpp_files:
            print(f"Warning: No .coo file found for program {program_name}. Skipping...")
            continue

        cpp_file_path = programs_dir+cpp_files[program_name] 
        with open(cpp_file_path, "r", encoding="utf-8") as f:
            content = f.read()

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
                {content}
            </Program>
        """

        # Add the entry to the dataset
        dataset.append({"instruction": input_text.strip(), "response": reponse_text.strip()})


        n=80
        random.shuffle(dataset)
        chunks = [dataset[i:i + n] for i in range(0, len(dataset), n)]
        training_dataset = chunks[0]
        testing_dataset = chunks[1]


        # Save the dataset as JSONL
        with open("../../data/fine_tunning/training.jsonl", "w", encoding="utf-8") as jsonl_file:
            for entry in training_dataset:
                jsonl_file.write(json.dumps(entry) + "\n")
                
        with open("../../data/fine_tunning/testing.jsonl", "w", encoding="utf-8") as jsonl_file:
            for entry in testing_dataset:
                jsonl_file.write(json.dumps(entry) + "\n")
                

        print("✅ JSONL files successfully created!")



if __name__ == "__main__":
    
    parser = argparse.ArgumentParser(description='Run perf stat over a set of programs.')
    parser.add_argument('class_dir', help='Path to the set of  the class.')
    args = parser.parse_args()
    
    flags = [f'-{flag}' for flag in args.flags] if args.flags else []
    create_dataset(args.class_dir)
