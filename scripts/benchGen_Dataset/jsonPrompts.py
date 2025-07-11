import json
import random
import pandas as pd

def row_to_json(series, origin, destiny):
    """Formats a row of performance data into a string prompt."""
    cpu = series["cpu-cycles_mean"]
    instructions = series["instructions_mean"]
    cache_ref = series["cache-references_mean"]
    cache_mis = series["cache-misses_mean"]
    
    item = f"""
    Below I have a perf output for a given program. 

    CPU Cycles,Instructions,Cache References,Cache Misses
    {cpu},{instructions},{cache_ref},{cache_mis}

    It was executed in the following machine architecture:

    {origin}

    Suppose I change to this CPU. 

    {destiny}

    Give the perf vector for the new CPU, do not explain anything else.
    """
    return item

def main():
    """Main function to read data, generate prompts, and save to a file."""
    try:
        arch_natan = """
        vendor_id   : GenuineIntel
        cpu family  : 6
        model       : 142
        model name  : Intel(R) Core(TM) i5-8250U CPU @ 1.60GHz
        stepping    : 10
        microcode   : 0xf6
        cpu MHz     : 3192.135
        cache size  : 6144 KB
        """
        
        arch_guima = """
        vendor_id       : GenuineIntel
        cpu family      : 6
        model           : 142
        model name      : Intel(R) Core(TM) i7-8565U CPU @ 1.80GHz
        stepping        : 11
        microcode       : 0xffffffff
        cpu MHz         : 1992.006
        cache size      : 8192 KB
        """ 
        
        df_guima = pd.read_csv("../../data/prediction_test/perf_data_guima.csv").get(['Program','cpu-cycles_mean','instructions_mean','cache-references_mean','cache-misses_mean'])
        df_natan = pd.read_csv("../../data/prediction_test/perf_data_natan.csv").get(['Program','cpu-cycles_mean','instructions_mean','cache-references_mean','cache-misses_mean'])
        
        dataframes = [(df_guima,"guima","natan",arch_guima,arch_natan),(df_natan,"natan","guima",arch_natan,arch_guima)]
        dataset = []

        for df,name_origin,name_destination,origin,destination in dataframes:
            for _, row in df.iterrows():
                dataset.append({"instruction" : row_to_json(row, origin, destination), "program" : row["Program"], "origin": name_origin,"destination":name_destination})

        random.shuffle(dataset)

    except Exception as e:
        print(f"Failed to generate the results. Erro: {e}")
        return

    try:
        with open("../../data/prediction_test/prompts_test.jsonl", "w", encoding="utf-8") as jsonl_file:
            for entry in dataset:
                jsonl_file.write(json.dumps(entry) + "\n")
        print("✅ JSONL files successfully created!")
    except Exception as e:
        print(f"Failed to save the results. Erro:{e}")       
            
if __name__ == "__main__":
    print("🚀 Starting prompt generation process...")
    main()
