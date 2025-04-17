import numpy as np
import string
import random
import os
from datasets import load_dataset, DatasetDict, Dataset #Dataset loader
from data_loader import DataLoader
from code_generator import CodeGeneration
#Drive usage
#from googleapiclient.discovery import build
#from googleapiclient.http import MediaFileUploadclass 

class TestPipeline: #TODO: setup the file generation to local as well
    def __init__(
            self,
            model: object,
            model_name: str,
            tokenizer: object,
            sampling_data_path: str,
            models_data_path: str,
            folder_id: str,
            dataset: Dataset,
            topology: str = "performance"  # Nome corrigido
        ):
        self.model = model
        self.model_name = model_name
        self.tokenizer = tokenizer
        self.folder_id = folder_id
        self.dataset = dataset
        self.models_data = DataLoader(models_data_path)
        self.sampling_data = DataLoader(sampling_data_path)

        self.topology = topology

    def upload_single_file_to_drive(self,code_name,program):#Upload file to drive for colab
        try:
            folder_id = self.folder_id 
            local_file_path = f"/content/{code_name}.c"


            with open(local_file_path, "w") as file:
             file.write(program)


            file_metadata = {
                'name': f'{code_name}.c',
                'parents': [folder_id]
            }

            media = MediaFileUpload(local_file_path, mimetype='text/plain')
            service = build('drive', 'v3')
            uploaded_file = service.files().create(body=file_metadata, media_body=media, fields='id').execute()

            print(f"File uploaded successfully. File ID: {uploaded_file.get('id')}")
        except Exception as e:
            print(f"File could not be uploaded. ERROR: {e}")
    
    def single_code_generation(self, max_len: int, dataset_flag: str = "train", i: int = 0) -> float:#Single Program Generation
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
                self.upload_single_file_to_drive(output_list[2],program)#Save generation

            self.models_data.new_row(output_list)
            self.models_data.save()

            print("Program Generated:\n" + program)
            
            
            
            return output_list[1]

            
        except Exception as e:
            print(f"ERRO: {e}")



    def single_sampling(self, max_len: int, dataset_flag: str = "train", i: int = 0):#Simulate different generation for time measure


        # model,mean_seconds,std_seconds,sample_size,max_length,lower_value,higher_value
        j = 0
        
        time_array = np.array()
        
        for item in self.dataset[dataset_flag]:
            
            
            generator = CodeGeneration(
            model=self.model,
            model_name=self.model_name,
            tokenizer=self.tokenizer,
            data=self.models_data,
            input_str=item["instruction"],
            input_id=None,
            max_length=max_len,
            topology=self.topology
            )

            generator.generate_code()

            program = generator.program_extratcion()

            output_list = generator.get_output_list()

            
            if(output_list[4] > 0):
                self.upload_single_file_to_drive(output_list[2],program)#Save generation

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
