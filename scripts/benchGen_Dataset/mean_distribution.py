import argparse
import numpy as np
import pandas as pd 

def bootstrap(file,server):
    data_path = '../../data/prediction_test/bg_distributions/'
    df = pd.read_csv(data_path+file)
    
    dists = []
    
    names = set(df["program"])
    
    for name in names:
        df_temp = df[df["program"] == name]
        for _ in range(10000):
            series_temp = df_temp[["cpu-cycles","instructions","cache-references","cache-misses"]].sample(n=5,replace=True)
            means = series_temp.mean()
            dists.append({"program":name,"cpu-cycles":means["cpu-cycles"],"instructions":means["instructions"],
            "cache-references":means["cache-references"],"cache-misses":means["cache-misses"]})
    
    
    df_result = pd.DataFrame(dists)
    df_result.to_csv(data_path+server+"_mean_dists.csv")
    return


def main():
    parser = argparse.ArgumentParser(
        description="Creates the distribution of means for a given arch with n programs."
    )
    parser.add_argument(
        "input_file",
        help="The csv with programs and it's distributions per counters.",
    )
    parser.add_argument(
        "server",
        help="Wich server the counters are from.",
    )
    
    args = parser.parse_args()
    
    bootstrap(args.input_file,args.server)

if __name__ == "__main__":
    main()
