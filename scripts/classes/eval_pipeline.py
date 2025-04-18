import numpy as np
import string
import pandas as pd
import random
import os
from datasets import load_dataset, DatasetDict, Dataset #Dataset loader
from data_loader import DataLoader
from code_generator import CodeGeneration
from drive_folder import Drive

class CompilationEvalPipeline: #TODO: setup the file generation to local as well
    def __init__(
            self,
            model: object,
            model_name: str,
            tokenizer: object,
            parent_folder_id: str,
            parent_folder_name: str,
            child_folder: str,
            dataset: Dataset,
            topology: str = "performance"  
        ):
        self.model = model
        self.model_name = model_name
        self.tokenizer = tokenizer
        self.dataset = dataset
        self.topology = topology
        
        try:
            folder_id, folder_name = Drive.find_folder(parent_folder_id,child_folder)
            if folder_id == None or folder_name == None:
                folder_id, folder_name = Drive.create_folder(parent_folder_id,child_folder)
        
            self.folder_id = folder_id
            
            print(parent_folder_name,folder_id,folder_name)

            sampling_path = parent_folder_name+folder_name+"/"+"sampling.csv"
            models_path = parent_folder_name+folder_name+"/"+"models_codes.csv"
            
            sampling = pd.DataFrame(columns=["model","mean_seconds","std_seconds","sample_size"
                                            ,"max_length","lower_value","higher_value"])
            sampling.to_csv(sampling_path,index=False)
            
            models = pd.DataFrame(columns=["model_name","seconds","code_name","caracteristcs"
                                            ,"length"])
            models.to_csv(models_path,index=False)
            
            
            self.models_data = DataLoader(models_path)
            self.sampling_data = DataLoader(sampling_path)
        except Exception as e:
            raise f"Folder coulnd't been created: {e}"

        
         
    def eval_code_generation(self, max_len: int, dataset_flag: str = "train", i: int = 0,model_type="base") -> float:#Single Program Generation
        try:
                
            generator = CodeGeneration(
            model=self.model,
            model_name=self.model_name,
            tokenizer=self.tokenizer,
            data=self.models_data,
            input_str=self.dataset[dataset_flag][i]["instruction"],
            input_id=None,
            max_length=max_len,
            topology=self.topology
            )

            generator.generate_code()

            program = generator.program_extratcion()

            output_list = generator.get_output_list()

            if(output_list[4] > 0):
                code_folder = f"code_{model_type}"
                code_folder_id, code_folder_name = Drive.find_folder(self.folder_id,code_folder)
                
                if code_folder_id == None or code_folder_name == None:
                    code_folder_id, code_folder = Drive.create_folder(self.folder_id,code_folder)
                
                Drive.upload_single_file_to_drive(code_folder_id,output_list[2],program)#Save generation

            self.models_data.new_row(output_list)
            self.models_data.save()

            print("Program Generated:\n" + program)
            
            return output_list[1]

            
        except Exception as e:
            print(f"ERRO: {e}")



    def eval_code_sampling(self, max_len: int, dataset_flag: str = "train", i: int = 0, model_type="base"):#Simulate different generation for time measure

        j = 0
        
        time_array = np.array()
        
        for item in self.dataset[dataset_flag]:
            
            
            generator = CodeGeneration(
            model=self.model,
            model_name=self.model_name,
            tokenizer=self.tokenizer,
            data=self.models_data,
            input_str=item["instruction"],
            input_id=j,
            max_length=max_len,
            topology=self.topology
            )

            generator.generate_code()

            program = generator.program_extratcion()

            output_list = generator.get_output_list()

            
            if(output_list[4] > 0):
                
                code_folder = f"code_{model_type}"
                code_folder_id, code_folder_name = Drive.find_folder(self.folder_id,code_folder)
                
                if code_folder_id == None or code_folder_name == None:
                    code_folder_id, code_folder = Drive.create_folder(self.folder_id,code_folder) 
                    
                Drive.upload_single_file_to_drive(code_folder_id,output_list[2],program)#Save generation

            time_array = np.append(time_array,output_list[1])
            self.models_data.new_row(output_list)
            self.models_data.save()

            print("Program Generated:\n" + program)
            
            if j >= i: break
            

        sampling_output = [self.model_name,
                                np.mean(time_array),
                                np.std(time_array),
                                i,
                                max_len
                            ,np.min(time_array),
                                np.max(time_array)]
        self.sampling_data.new_row(sampling_output)
        self.sampling_data.save()

            
        print("Sampling done!")
