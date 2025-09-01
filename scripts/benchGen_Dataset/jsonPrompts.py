import json
import random
import pandas as pd
import numpy as np

def transfer_question_maker(df_origin, df_destiny, program, origin, destiny, counter):
    
    series_origin = df_origin[df_origin["Program"] == program]
    series_destiny = df_destiny[df_destiny["Program"] == program]

    if series_origin.empty or series_destiny.empty:
        return None, None, None
    
    counter_mean = counter + "_mean"
    
    value_origin = series_origin[counter_mean].iloc[0]
    

    
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
        
    return text


def program_question_maker(df_origin, program, origin, counter):
    
    program_code = "Code for the program is not available."
    
    with open(f"code/benchgen/texts/{program}.txt") as f:
        program_code = f.read()

    text = f"""
    Below I have a given program. 

    {program_code}

    It was executed in the following machine architecture:

    {origin}

    What could be the predicted value for the {counter} counter on the destiny machine? 
    Give me only single number that fit the perf program distribution.
    """

    
    return text

def qualitative_question_maker(df_origin,df_destiny,program, origin, destiny, counter):
    series_origin = df_origin[df_origin["Program"] == program]
    series_destiny = df_destiny[df_destiny["Program"] == program]
    
    if series_origin.empty or series_destiny.empty:
        return None, None, None

    counter_mean = counter+"_mean"
    counter_ic_low = counter+"_ic_low"
    counter_ic_high = counter+"_ic_high"
    
    value_origin = series_origin[counter_mean].iloc[0]
        
    ic_low_destiny = series_destiny[counter_ic_low].iloc[0]
    ic_high_destiny = series_destiny[counter_ic_high].iloc[0]
    mean_destiny = series_destiny[counter_mean].iloc[0]
    
    correct_answer = ""
    
    answers = ["It won't change.","It is higher.","It is lower."]
    
    if ic_low_destiny <= value_origin <= ic_high_destiny:
        correct_answer = answers[0]
        
    elif value_origin > mean_destiny:
        correct_answer = answers[1]
    
    elif value_origin < mean_destiny:
        correct_answer = answers[2]
        
    if not correct_answer:
        return None, None, None

    random.shuffle(answers)
        
    text = f"""
    Below I have a perf output for a given program. 

    {counter}
    {value_origin}

    It was executed in the following machine architecture:

    {origin}

    Suppose I change to this CPU. 

    {destiny}

    How would change the observed values?
    """
    
    itens = f"""
    A){answers[0]} 
    B){answers[1]}
    C){answers[2]}
    """
    
    return text, itens, correct_answer


def main():
    try:
        arch_A = """
        vendor_id   : GenuineIntel
        cpu family  : 6
        model       : 62
        model name  : Intel(R) Xeon(R) E5-2680 v2 @ 2.80GHz
        stepping    : 4
        microcode   : 0x42e
        cpu MHz     : 1200.000
        cache size  : 25600 KB
        """
        
        arch_B = """
        vendor_id       : AuthenticAMD
        cpu family      : 23
        model           : 113
        model name      : AMD Ryzen 7 3700X 8-Core Processor
        stepping        : 0
        microcode       : 0x8701021
        cpu MHz         : 2195.860
        cache size      : 512 KB
        """ 
        
        df_B = pd.read_csv("perf_data.csv")
        df_A = pd.read_csv("perf_data.csv")
        
        dataframes = [(df_B,df_A,"B","A",arch_B,arch_A),(df_A,df_B,"A","B",arch_A,arch_B)]
        counters = ["cpu-cycles","instructions","cache-references","cache-misses"]
        
        dataset_qualitatives = []
        dataset_programs = []
        dataset_transfer = []

        i = 1
        for df_origin,df_destiny,name_origin,name_destination,origin,destination in dataframes:
            print(f"Creating dataset. Part {i} of {len(dataframes)}...⏰")
            for _, row in df_origin.iterrows():
                for counter in counters:
                    
                    text = transfer_question_maker(df_origin,df_destiny,row["Program"], origin, destination, counter) 
                    if text:
                        dataset_transfer.append({"instruction" :text, "program" : row["Program"], "origin": name_origin,"destination":name_destination,"type":"interval","counter":counter},)

                    text = program_question_maker(df_origin,row["Program"], origin, counter) 
                    if text:
                        dataset_programs.append({"instruction" :text, "program" : row["Program"], "origin": name_origin,"destination":"","type":"program","counter":counter})
                    
                    text,itens,answer = qualitative_question_maker(df_origin,df_destiny,row["Program"], origin, destination, counter) 
                    if text:
                        dataset_qualitatives.append({"instruction" :text,"itens":itens, "answer":answer, "program" : row["Program"], "origin": name_origin,"destination":name_destination,"type":"random_qualitative","counter":counter})
            i += 1
        
        random.shuffle(dataset_programs)
        random.shuffle(dataset_qualitatives)
        random.shuffle(dataset_transfer)
        datasets = [(dataset_transfer,"transfer"),(dataset_programs,"programs"),(dataset_qualitatives,"qualitatives")]

    except Exception as e:
        print(f"Failed to generate the results. Erro: {e}")
        return

    try:
        for dataset,name in datasets:
            with open(f"../../data/prediction_test/test_{name}.jsonl", "w", encoding="utf-8") as jsonl_file:
                for entry in dataset:
                    jsonl_file.write(json.dumps(entry) + "\n")
                
        print("✅ JSONL files successfully created!")
    except Exception as e:
        print(f"Failed to save the results. Erro:{e}")       
        
if __name__ == "__main__":
    print("🚀 Starting prompt generation process...")
    main()