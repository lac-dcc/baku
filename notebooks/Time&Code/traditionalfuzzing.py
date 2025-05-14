# %% [markdown]
# ### Imports

# %%

import numpy as np #to better use of the arrays

import time #measure time

import matplotlib.pyplot as plt #plots

import pandas as pd #for csv

import seaborn as sns

import subprocess #for write file...
import random
import string
import os
import sys
import shutil
import glob

# %% [markdown]
# ### Generating

# %%
YARPGEN_PATH = '../../bin/yarpgen.out'
SOURCE_FILE = 'driver.c'
BINARY_FILE = 'program'
YARPGEN_DIR_BASE = '../../data/TimeCodeExperiment/traditionalFuzzers/yarpgen/'
CSMITH_DIR_BASE = '../../data/TimeCodeExperiment/traditionalFuzzers/csmith/'
opt_flag = '-O2'

if not os.path.exists(YARPGEN_DIR_BASE):
    os.makedirs(YARPGEN_DIR_BASE)
if not os.path.exists(CSMITH_DIR_BASE):
    os.makedirs(CSMITH_DIR_BASE)


# %% [markdown]
# ### Pipeline

# %%
class GenerationPipeline:

    def __init__(self, output_dir_base: str, fuzzer="yarpgen"):
        self.output_dir_base = output_dir_base
        self.totalTime = 0
        self.totalTries = 0
        self.failures = 0
        self.success = 0
        self.regressions = 0
        self.first_regression_time = 0
        self.fuzzer = fuzzer
        
    def yarpgen_program(self, output_dir: str):
        if not os.path.exists(output_dir):
            os.makedirs(output_dir)
            
        print("[*] Generating program with YARPGen...")
        result = subprocess.run([YARPGEN_PATH, "--std=c", f"--out-dir={output_dir}"])
        if result.returncode != 0:
            print("[!] YARPGen failed")
            sys.exit(1)
            return None
        else:
            print("[*] YARPGen program generated successfully")
            return result.stdout
        
    def csmith_program(self, output_dir: str, source: str):
        if not os.path.exists(output_dir):
            os.makedirs(output_dir)
            
        print("[*] Generating program with Csmith...")
        with open(f"{output_dir}/{source}.c", "w") as output_file:
            result = subprocess.run(["csmith"], stdout=output_file)
        if result.returncode != 0:
            print("[!] Csmith failed")
            sys.exit(1)
            return None
        else:
            print("[*] Csmith program generated successfully")
            return result.stdout
        

    def compile_program(self, source_dir: str, out_dir: str, out_file: str):
        if not os.path.exists(out_dir):
            os.makedirs(out_dir)
            
        opt_flags = ['-O0', '-O1', '-O2', '-O3', '-Os', '-Ofast']
        print("[*] Compiling the program...")
        for opt_flag in opt_flags:
            c_files = glob.glob(f"{source_dir}/*.c")
            result = subprocess.run(["gcc", opt_flag, *c_files, f'-I{source_dir}', "-o", f'{out_dir}/{out_file}{opt_flag}.out'])
            if result.returncode != 0:
                print("[!] Compilation failed")
                self.failures += 1
                return False
        self.success += 1
        return True

    def folder_generator(self, size=4):
        # Geração de nome aleatório para a pasta
        chars = string.ascii_uppercase
        random_name = ''.join(random.choice(chars) for _ in range(size))

        # Verifica se o nome da pasta já existe no diretório local
        while os.path.exists(os.path.join(self.output_dir_base, random_name)):
            random_name = ''.join(random.choice(chars) for _ in range(size))

        # Caminho completo da nova pasta
        folder_path = os.path.join(self.output_dir_base, random_name)

        # Cria a pasta localmente
        os.makedirs(folder_path)

        # Retorna o caminho da pasta criada e o nome aleatório
        return folder_path, random_name
    def get_binary_size(self, file_path):
        if not os.path.exists(file_path):
            return 0
        result = subprocess.run(['size', file_path], capture_output=True, text=True, check=True)
        lines = result.stdout.splitlines()
        
        if len(lines) < 2:
            return 0
        
        parts = lines[1].split()
        return int(parts[0])
    
    def verify_regression(self, binary_dir: str, binary_file: str) -> bool:
        # Verifica se o diretório existe
        if not os.path.exists(binary_dir):
            print(f"Directory {binary_dir} does not exist.")    
            return False
        
        optmization_flags = ['-O0', '-O1', '-O2', '-O3', '-Os', '-Ofast']

        binary_sizes = {}

        for opt_flag in optmization_flags:
            binary_path = os.path.join(binary_dir, f"{binary_file}{opt_flag}.out")
            size = self.get_binary_size(binary_path)
            binary_sizes[opt_flag] = size
            print(f"Binary size for {opt_flag}: {size} bytes")
            
        for opt_flag in optmization_flags:
            if opt_flag != '-Os' and int(binary_sizes['-Os']) - int(binary_sizes[opt_flag]) > 32:
                return True

        # Check for regression
        return False
    
    def generate(self):
        # Inicializa o cronômetro
        start_time = time.time()

        # Aumenta o contador de tentativas
        self.totalTries += 1

        # Cria uma nova pasta com nome aleatório
        folder_path, random_name = self.folder_generator()

        # Gera o programa YARPGen
        match self.fuzzer:
            case "yarpgen":
                self.yarpgen_program(folder_path)
            case "csmith":
                self.csmith_program(folder_path, random_name)

        # Compila o programa gerado
        compiled = self.compile_program(folder_path, folder_path, random_name)
        
        regression = False


        if not compiled:
            shutil.rmtree(folder_path)
        else:
            # Verifica a regressão TODO!
            regression = self.verify_regression(folder_path, random_name)
            if regression:
                self.regressions += 1
                if self.first_regression_time == 0:
                    self.first_regression_time = time.time() - start_time
                print(f"[!] Regression detected in {folder_path}")
            else:
                shutil.rmtree(folder_path)

        # Termina o cronômetro
        end_time = time.time()
        timeSpent = end_time - start_time
        self.totalTime += timeSpent

        # Retorna o caminho da pasta criada e o nome aleatório
        return regression, timeSpent, self.totalTime
    

    def print_status(self):
        print(f"Total time: {self.totalTime:.2f}s")
        print(f"Failures: {self.failures}")
        print(f"Success: {self.success}")
        print(f"Regressions: {self.regressions}")
        if self.regressions > 0:
            print(f"First regression time: {self.first_regression_time:.2f}s")


# %% [markdown]
# ### Csmith Run

# %%
# pipeline = GenerationPipeline(CSMITH_DIR_BASE, fuzzer="csmith")
# while(pipeline.totalTime < 3600.00):
#     pipeline.generate()

# df = pd.DataFrame({
#     'fuzzer': pipeline.fuzzer,
#     'total_tries': pipeline.totalTries,
#     'total_time': pipeline.totalTime,
#     'failures': pipeline.failures,
#     'success': pipeline.success,
#     'regressions': pipeline.regressions,
#     'first_regression_time': pipeline.first_regression_time
# }, index=[0])

# df.to_csv(f"{CSMITH_DIR_BASE}/results.csv", index=False)

# pipeline.print_status()

# %%
pipeline = GenerationPipeline(YARPGEN_DIR_BASE, fuzzer="yarpgen")
while(pipeline.totalTime < 3600.00):
    pipeline.generate()

df = pd.DataFrame({
    'fuzzer': pipeline.fuzzer,
    'total_tries': pipeline.totalTries,
    'total_time': pipeline.totalTime,
    'failures': pipeline.failures,
    'success': pipeline.success,
    'regressions': pipeline.regressions,
    'first_regression_time': pipeline.first_regression_time
}, index=[0])

df.to_csv(f"{YARPGEN_DIR_BASE}/results.csv", index=False)

pipeline.print_status()


