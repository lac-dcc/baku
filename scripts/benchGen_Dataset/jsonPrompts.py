import json
import random
import pandas as pd
import numpy as np

def question_maker(df_origin,df_destiny,program, origin, destiny, counter):
    """Formats a row of performance data into a string prompt."""
    values = []
    
    series_origin = df_origin[df_origin["Program"] == program]
    series_destiny = df_destiny[df_destiny["Program"] == program]
    
    counter_mean = counter+"_mean"
    counter_ic_low = counter+"_ic_low"
    counter_ic_high = counter+"_ic_high"
    
    value_origin = series_origin[counter_mean].iloc[0]
     
    ic_low_destiny = series_destiny[counter_ic_low].iloc[0]
    ic_high_destiny = series_destiny[counter_ic_high].iloc[0]
    
    while len(values) <= 9:
        sample = df_destiny[df_destiny["Program"] != program].sample(n=4)
        for _,row in sample.iterrows():
            if not ic_low_destiny <= row[counter_mean] <= ic_high_destiny:
                values.append(row[counter_ic_low])
                values.append(row[counter_ic_high])

    values.append(ic_low_destiny)
    values.append(ic_high_destiny)   
    
    random.shuffle(values)
    
    text = f"""
    Below I have a perf output for a given program. 

    {counter}
    {value_origin}

    It was executed in the following machine architecture:

    {origin}

    Suppose I change to this CPU. 

    {destiny}

    What is the predicted value for the {counter} counter on the destiny machine?
    
    """
    
    itens = f"""
    A){values[0]} to {values[1]} 
    B){values[2]} to {values[3]}
    C){values[4]} to {values[5]}
    D){values[6]} to {values[7]}
    E){values[8]} to {values[9]}
    """
    
    answer = f"""
    The value are in the interval of {ic_low_destiny} to {ic_high_destiny}, considering a confidence interval around the observed mean.
    """
    
    return text,itens,answer

def row_to_json_qualitative(series, origin, destiny):
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

    How would change the observed values? Give me each response in words separeted by comma, do not explain anything else.
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
        
        df_guima = pd.read_csv("../../data/prediction_test/perf_data_guima.csv")
        df_natan = pd.read_csv("../../data/prediction_test/perf_data_natan.csv")
        
        dataframes = [(df_guima,df_natan,"guima","natan",arch_guima,arch_natan),(df_natan,df_guima,"natan","guima",arch_natan,arch_guima)]
        counters = ["cpu-cycles","instructions","cache-references","cache-misses"]
        
        dataset = []

        for df_origin,df_destiny,name_origin,name_destination,origin,destination in dataframes:
            for _, row in df_origin.iterrows():
                for counter in counters:
                    text,itens,answer = question_maker(df_origin,df_destiny,row["Program"], origin, destination, counter) 
                    dataset.append({"instruction" :text,"itens":itens, "answer":answer, "program" : row["Program"], "origin": name_origin,"destination":name_destination})
        random.shuffle(dataset)

    except Exception as e:
        print(f"Failed to generate the results. Erro: {e}")
        return

    try:
        with open("../../data/prediction_test/test.jsonl", "w", encoding="utf-8") as jsonl_file:
            for entry in dataset:
                jsonl_file.write(json.dumps(entry) + "\n")
                
        print("✅ JSONL files successfully created!")
    except Exception as e:
        print(f"Failed to save the results. Erro:{e}")       
            
if __name__ == "__main__":
    print("🚀 Starting prompt generation process...")
    main()
