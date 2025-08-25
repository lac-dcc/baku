import json
import random
import pandas as pd
import numpy as np

def interval_question_maker(df_origin, df_destiny, program, origin, destiny, counter):
    intervals = []
    
    series_origin = df_origin[df_origin["Program"] == program]
    series_destiny = df_destiny[df_destiny["Program"] == program]

    if series_origin.empty or series_destiny.empty:
        return None, None, None
    
    counter_mean = counter + "_mean"
    counter_ic_low = counter + "_ic_low"
    counter_ic_high = counter + "_ic_high"
    
    value_origin = series_origin[counter_mean].iloc[0]
        
    ic_low_destiny = series_destiny[counter_ic_low].iloc[0]
    ic_high_destiny = series_destiny[counter_ic_high].iloc[0]
    
    wrong_answers_candidates = df_destiny[
        (df_destiny["Program"] != program) &
        ((df_destiny[counter_mean] < ic_low_destiny) | (df_destiny[counter_mean] > ic_high_destiny))
    ]
    
    num_samples = min(4, len(wrong_answers_candidates))
    
    if num_samples < 4:
        return None, None, None

    wrong_samples = wrong_answers_candidates.sample(n=num_samples)
    
    for _, row in wrong_samples.iterrows():
        intervals.append((row[counter_ic_low], row[counter_ic_high]))

    intervals.append((ic_low_destiny, ic_high_destiny))      
    
    random.shuffle(intervals)
    
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
    A){intervals[0][0]} to {intervals[0][1]} 
    B){intervals[1][0]} to {intervals[1][1]}
    C){intervals[2][0]} to {intervals[2][1]}
    D){intervals[3][0]} to {intervals[3][1]}
    E){intervals[4][0]} to {intervals[4][1]}
    """
    
    correct_answer = f"""
    The value are in the interval of {ic_low_destiny} to {ic_high_destiny}, considering a confidence interval around the observed mean.
    """
    
    return text, itens, correct_answer


def program_question_maker(df_origin, program, origin, counter):
    intervals = []
    
    series_origin = df_origin[df_origin["Program"] == program]
    
    if series_origin.empty:
        return None, None, None

    counter_mean = counter + "_mean"
    counter_ic_low = counter + "_ic_low"
    counter_ic_high = counter + "_ic_high"
    
    ic_low = series_origin[counter_ic_low].iloc[0]
    ic_high = series_origin[counter_ic_high].iloc[0]
    
    wrong_answers_candidates = df_origin[
        (df_origin["Program"] != program) &
        ((df_origin[counter_mean] < ic_low) | (df_origin[counter_mean] > ic_high))
    ]
    
    num_samples = min(4, len(wrong_answers_candidates))

    if num_samples < 4:
        return None, None, None

    wrong_samples = wrong_answers_candidates.sample(n=num_samples)
    
    for _, row in wrong_samples.iterrows():
        intervals.append((row[counter_ic_low], row[counter_ic_high]))

    intervals.append((ic_low, ic_high))
    
    random.shuffle(intervals)
    
    program_code = "Code for the program is not available."

    text = f"""
    Below I have a given program. 

    {program_code}

    It was executed in the following machine architecture:

    {origin}

    What is the predicted value for the {counter} counter on the destiny machine?
    """
    
    itens = f"""
    A){intervals[0][0]} to {intervals[0][1]} 
    B){intervals[1][0]} to {intervals[1][1]}
    C){intervals[2][0]} to {intervals[2][1]}
    D){intervals[3][0]} to {intervals[3][1]}
    E){intervals[4][0]} to {intervals[4][1]}
    """
    
    correct_answer = f"""
    The value are in the interval of {ic_low} to {ic_high}, considering a confidence interval around the observed mean.
    """
    
    return text, itens, correct_answer

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
        
        df_guima = pd.read_csv("../../data/prediction_test/perf_data_server_guima.csv")
        df_natan = pd.read_csv("../../data/prediction_test/perf_data_server_natan.csv")
        
        dataframes = [(df_guima,df_natan,"guima","natan",arch_guima,arch_natan),(df_natan,df_guima,"natan","guima",arch_natan,arch_guima)]
        counters = ["cpu-cycles","instructions","cache-references","cache-misses"]
        
        dataset = []

        i = 1
        for df_origin,df_destiny,name_origin,name_destination,origin,destination in dataframes:
            print(f"Creating dataset. Part {i} of {len(dataframes)}...⏰")
            for _, row in df_origin.iterrows():
                for counter in counters:
                    
                    text,itens,answer = interval_question_maker(df_origin,df_destiny,row["Program"], origin, destination, counter) 
                    if text:
                        dataset.append({"instruction" :text,"itens":itens, "answer":answer, "program" : row["Program"], "origin": name_origin,"destination":name_destination,"type":"interval","counter":counter},)

                    text,itens,answer = program_question_maker(df_origin,row["Program"], origin, counter) 
                    if text:
                        dataset.append({"instruction" :text,"itens":itens, "answer":answer, "program" : row["Program"], "origin": name_origin,"destination":"","type":"program","counter":counter})
                    
                    text,itens,answer = qualitative_question_maker(df_origin,df_destiny,row["Program"], origin, destination, counter) 
                    if text:
                        dataset.append({"instruction" :text,"itens":itens, "answer":answer, "program" : row["Program"], "origin": name_origin,"destination":name_destination,"type":"random_qualitative","counter":counter})
            i += 1
        
        random.shuffle(dataset)

    except Exception as e:
        print(f"Failed to generate the results. Erro: {e}")
        return

    try:
        with open("test.jsonl", "w", encoding="utf-8") as jsonl_file:
            for entry in dataset:
                jsonl_file.write(json.dumps(entry) + "\n")
                
        print("✅ JSONL files successfully created!")
    except Exception as e:
        print(f"Failed to save the results. Erro:{e}")       
        
if __name__ == "__main__":
    print("🚀 Starting prompt generation process...")
    main()