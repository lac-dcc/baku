import sys
import os
import pandas as pd
from datetime import datetime
sys.path.append("../classes")

def write_results_to_file(results, model_name):
    filename = f'{model_name}_results.txt'
    with open(filename, 'w') as f:
        f.write("Regression Analysis Report\n")
        f.write(f"Generated on: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}\n")
        f.write("="*60 + "\n\n")

        results.sort(key=lambda tup: tup[1])

        if not results:
            f.write("No regressions found in any test cases.\n")
            return
        
        f.write(f"Found {len(results)} regression(s):\n\n")
        for i, result in enumerate(results, 1):
            f.write(f"{i}. {result[0]}\n")
        
        f.write("\n" + "="*60 + "\n")
        f.write("End of report\n")


def verify_sample_results(df, file, folder, compiler, version, opt):
    min_size = df["bin_min_size"].iloc[0]
    max_size = df["bin_max_size"].iloc[0]
    mean_size = df["bin_mean_size"].iloc[0]
    df_time = df["time"].iloc[0]

    if min_size != max_size or max_size != mean_size or min_size != mean_size:
        return True,f"Regression found in samples (dead code): {folder} | {file} | {compiler}-{version} | {opt}",df_time
    
    return False,"",df_time

def compare_samples(os_df, other_df, file, folder, compiler, version, opt):
    os_min = os_df["bin_min_size"].iloc[0]
    os_max = os_df["bin_max_size"].iloc[0]
    os_mean = os_df["bin_mean_size"].iloc[0]
    os_time = os_df["time"].iloc[0]
    
    other_min = other_df["bin_min_size"].iloc[0]
    other_max = other_df["bin_max_size"].iloc[0]
    other_mean = other_df["bin_mean_size"].iloc[0]
    
    
    if os_min - other_min >= 32  or os_max - other_max >= 32  or os_mean - other_mean >= 32 :
        return True,f"Regression found (-Os worse than {opt}): {folder} | {file} | {compiler}-{version}",os_time
        
    return False,"",os_time

def regression_search(folder, file, compiler, version, compilation_path, chain):
    OPT_FLAGS = ["-O0", "-O1", "-O2", "-O3", "-Ofast"]
    try:
        compilation_df = pd.read_csv(compilation_path)


        folder_id = folder.split('/')[5]

        if(chain):
            base_query = (
                (compilation_df['folder_id'] == str(folder_id)) &
                (compilation_df['file'] == str(file)) &
                (compilation_df['compiler'] == str(compiler)) &
                (compilation_df['version'] == int(version)) 
            )
        else:
            base_query = (
                (compilation_df['file'] == str(file.split('.')[0])) &
                (compilation_df['compiler'] == str(compiler)) &
                (compilation_df['version'] == int(version)) 
            )

        os_query = base_query & (compilation_df['optimization'] == "-Os") 
        compilation_Os = compilation_df[os_query]
        
        if compilation_Os.empty:
            return False, f"No -Os data found for {file}",0
        
        result,result_str,time = verify_sample_results(compilation_Os, file, folder, compiler, version, "-Os")
        if result:
            return result,result_str,time
        
        for opt in OPT_FLAGS:
            current_df = compilation_df[base_query & (compilation_df["optimization"] == opt)]

            result,result_str,time = compare_samples(compilation_Os, current_df, file, folder, compiler, version, opt)
            if result:
                return result,result_str,time
        
            result,result_str,time = verify_sample_results(current_df, file, folder, compiler, version, opt)
            if result:

                return result,result_str,time
            
        
        return False,"",0
    
    except Exception as e:
        print(e)
        sys.exit()
        return False,f"Error processing {folder}/{file} with {compiler}-{version}: {str(e)}",0

def main():
    if len(sys.argv) < 5:
        print("Usage: python verify_regression.py <file_folder> <data_path> <model_name> <chain or single>")
        sys.exit(1)

    file_folder = sys.argv[1]
    data_path = sys.argv[2]
    model_name = sys.argv[3]
    chain_or_single = sys.argv[4]
    chain = True
    
    if (chain_or_single == "single"): 
        chain = False

    if not os.path.isdir(file_folder):
        print(f"Folder '{file_folder}' not found.")
        sys.exit(1)

    

    COMPILERS = ["gcc"]
    VERSIONS = ["14"]

    time_compilation = 0
    results = []
    for folder, _, files in os.walk(file_folder):
        if "output" not in folder:  # Skip output directories
            for file in sorted(files):
                if not file.endswith(".out"):  # Only process source files
                    for compiler in COMPILERS:
                        for version in VERSIONS:
                            print(f"\nChecking: {file} with {compiler}-{version} in {folder}")
                            if(chain):
                                result,result_str,time = regression_search(folder, file, compiler, version,data_path+'compilation_chain.csv',True)
                                time_compilation = time_compilation + time
                                if result:
                                    time_spent = time_compilation
                                    chains_csv = pd.read_csv(data_path+'chains.csv')
                                    
                                    name_code = file.split(".")[0]

                                    for _,chain in chains_csv.iterrows() :
                                        if chain['folder_id'] == name_code[:4]:
                                            time_spent = time_spent + int(name_code[4:]) * (chain['time_spent']/30)
                                            break
                                        else:
                                            time_spent = time_spent + chain['time_spent']

                                    rows_csv = chains_csv[(chains_csv["folder_id"] == folder.split('/')[5])]
                                    rows_chain = (rows_csv.values).flatten()
                                    if len(rows_chain) > 0:
                                        rows_chain[5] = True

                                        chains_csv = chains_csv.set_index("folder_id") 
                                        chains_csv.loc[rows_chain[0]] = rows_chain[1:]
                                        chains_csv = chains_csv.reset_index()



                                        chains_csv.to_csv(data_path+'chains.csv', index=False)

                                        results.append([f"{result_str} | Seconds until this regression: {time_spent}",time_spent])
                                        print("==> Regression detected:", result_str)
                                    else:
                                        print("==> No regression found")

                                else:
                                    print("==> No regression found")
                            
                            else:
                                result,result_str,time = regression_search(folder, file, compiler, version,data_path+'compilation_singles.csv',False)
                                time_compilation = time_compilation + time
                                if result:
                                    time_spent = time_compilation
                                    code_csv = pd.read_csv(data_path+'model_singles_programs.csv')
                                    
                                    name_code = file.split(".")[0]

                                    for _,code in code_csv.iterrows() :
                                        time_spent = time_spent + (code['seconds'])
                                        if code['code_name'] == name_code.split('.')[0]:
                                            break


                                    results.append([f"{result_str} | Seconds until this regression: {time_spent}",time_spent])
                                    print("==> Regression detected:", result_str)
                                else:
                                    print("==> No regression found")

    write_results_to_file(results,model_name)
    print("\n" + "="*60)
    print(f"Analysis complete. Results saved to {model_name}_results.txt")
    print(f"Total regressions found: {len(results)}")

if __name__ == "__main__":
    main()