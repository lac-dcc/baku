import sys
import os
import pandas as pd
from datetime import datetime

def write_results_to_file(results, filename="regression_results.txt"):
    with open(filename, 'w') as f:
        f.write("Regression Analysis Report\n")
        f.write(f"Generated on: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}\n")
        f.write("="*60 + "\n\n")
        
        if not results:
            f.write("No regressions found in any test cases.\n")
            return
        
        f.write(f"Found {len(results)} regression(s):\n\n")
        for i, result in enumerate(results, 1):
            f.write(f"{i}. {result}\n")
        
        f.write("\n" + "="*60 + "\n")
        f.write("End of report\n")


def verify_sample_results(df, file, folder, compiler, version, opt):
    min_size = df["bin_min_size"].iloc[0]
    max_size = df["bin_max_size"].iloc[0]
    mean_size = df["bin_mean_size"].iloc[0]

    if min_size != max_size or max_size != mean_size or min_size != mean_size:
        return True,f"Regression found in samples (dead code): {folder} | {file} | {compiler}-{version} | {opt}"
    return False,""

def compare_samples(os_df, other_df, file, folder, compiler, version, opt):
    os_min = os_df["bin_min_size"].iloc[0]
    os_max = os_df["bin_max_size"].iloc[0]
    os_mean = os_df["bin_mean_size"].iloc[0]
    
    other_min = other_df["bin_min_size"].iloc[0]
    other_max = other_df["bin_max_size"].iloc[0]
    other_mean = other_df["bin_mean_size"].iloc[0]
    
    if os_min > other_min or os_max > other_max or os_mean > other_mean:
        return True,f"Regression found (-Os worse than {opt}): {folder} | {file} | {compiler}-{version}"
        
    return False,""

def regression_search(folder, file, compiler, version):
    OPT_FLAGS = ["-O0", "-O1", "-O2", "-O3", "-Ofast"]
    
    try:
        csv_path = "../../data/Time&Code/compilation.csv"
        compilation_df = pd.read_csv(csv_path)
        folder_id = folder[17:]

        
        base_query = (
            (compilation_df['folder_id'] == str(folder_id)) &
            (compilation_df['file'] == str(file)) &
            (compilation_df['compiler'] == str(compiler)) &
            (compilation_df['version'] == int(version)) 
        )
        

        os_query = base_query & (compilation_df['optimization'] == "-Os") 
        compilation_Os = compilation_df[os_query]
        
        if compilation_Os.empty:
            return False, f"No -Os data found for {file}"
        
        result,result_str = verify_sample_results(compilation_Os, file, folder, compiler, version, "-Os")
        if result:
            return result,result_str
        
        for opt in OPT_FLAGS:
            current_df = compilation_df[base_query & (compilation_df["optimization"] == opt)]

            result,result_str = compare_samples(compilation_Os, current_df, file, folder, compiler, version, opt)
            if result:
                return result,result_str
        
            result,result_str = verify_sample_results(current_df, file, folder, compiler, version, opt)
            if result:

                return result,result_str
            
        
        return False,""
    
    except Exception as e:
        return False,f"Error processing {folder}/{file} with {compiler}-{version}: {str(e)}"

def main():
    if len(sys.argv) < 2:
        print("Usage: python verify_regression.py <file_folder>")
        sys.exit(1)

    file_folder = sys.argv[1]

    if not os.path.isdir(file_folder):
        print(f"Folder '{file_folder}' not found.")
        sys.exit(1)

    COMPILERS = ["gcc"]
    VERSIONS = ["9", "10", "11", "12"]

    results = []

    for folder, _, files in os.walk(file_folder):
        if "output" not in folder:  # Skip output directories
            for file in sorted(files):
                if not file.endswith(".out"):  # Only process source files
                    for compiler in COMPILERS:
                        for version in VERSIONS:
                            print(f"\nChecking: {file} with {compiler}-{version} in {folder}")
                            result,result_str = regression_search(folder, file, compiler, version)
                            if result:
                                results.append(result_str)
                                print("==> Regression detected:", result_str)
                            else:
                                print("==> No regression found")

    write_results_to_file(results)
    print("\n" + "="*60)
    print("Analysis complete. Results saved to regression_results.txt")
    print(f"Total regressions found: {len(results)}")

if __name__ == "__main__":
    main()