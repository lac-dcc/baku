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
    if not df.empty:
        min_size = df["bin_min_size"].iloc[0]
        max_size = df["bin_max_size"].iloc[0]
        mean_size = df["bin_mean_size"].iloc[0]
        if min_size != max_size or max_size != mean_size or min_size != mean_size:
            return f"Regression found in samples (dead code): {folder} | {file} | {compiler}-{version} | {opt}"
    return None

def compare_samples(os_df, other_df, file, folder, compiler, version, opt):
    if not os_df.empty and not other_df.empty:
        os_min = os_df["bin_min_size"].iloc[0]
        os_max = os_df["bin_max_size"].iloc[0]
        os_mean = os_df["bin_mean_size"].iloc[0]
        
        other_min = other_df["bin_min_size"].iloc[0]
        other_max = other_df["bin_max_size"].iloc[0]
        other_mean = other_df["bin_mean_size"].iloc[0]
        
        if os_min > other_min or os_max > other_max or os_mean > other_mean:
            return f"Regression found (-Os worse than {opt}): {folder} | {file} | {compiler}-{version}"
    return None

def regression_search(folder, file, compiler, version):
    OPT_FLAGS = ["-O0", "-O1", "-O2", "-O3", "-Ofast"]
    
    try:
        compilation_df = pd.read_csv("../../data/Time&Code/compilation.csv")
        folder_id = folder[23:] 
        
        base_query = (
            (compilation_df["folder_id"] == folder_id) &
            (compilation_df["file"] == file) &
            (compilation_df["compiler"] == compiler) &
            (compilation_df["version"] == version)
        )
        
        compilation_Os = compilation_df[base_query & (compilation_df["optimization"] == "-Os")]
        
        result = verify_sample_results(compilation_Os, file, folder, compiler, version, "-Os")
        if result:
            return result
        
        for opt in OPT_FLAGS:
            current_df = compilation_df[base_query & (compilation_df["optimization"] == opt)]
        
            result = verify_sample_results(current_df, file, folder, compiler, version, opt)
            if result:
                return result
            
            result = compare_samples(compilation_Os, current_df, file, folder, compiler, version, opt)
            if result:
                return result
        
        return ""
    
    except Exception as e:
        return f"Error processing {folder}/{file} with {compiler}-{version}: {str(e)}"

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
                            result = regression_search(folder, file, compiler, version)
                            if result:
                                results.append(result)
                                print("==> Regression detected:", result)
                            else:
                                print("==> No regression found")

    write_results_to_file(results)
    print("\n" + "="*60)
    print("Analysis complete. Results saved to regression_results.txt")
    print(f"Total regressions found: {len(results)}")

if __name__ == "__main__":
    main()