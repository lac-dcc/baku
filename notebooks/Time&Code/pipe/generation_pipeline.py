import numpy as np
import string
import random
import os
from data_loader import DataLoader
from code_generator import CodeGeneration
#Drive usage
#from googleapiclient.discovery import build
#from googleapiclient.http import MediaFileUploadclass 

class GenerationPipeline: #TODO: setup the file generation to local as well
    def __init__(
            self,
            model: object,
            model_name: str,
            tokenizer: object,
            sampling_data_path: str,
            models_data_path: str,
            input_data_path: str,
            models_chain_path: str,
            chains_data_path: str,
            topology: str = 'regression'  # Nome corrigido
        ):
        self.model = model
        self.model_name = model_name
        self.tokenizer = tokenizer
        self.input_data = DataLoader(input_data_path)
        self.models_data = DataLoader(models_data_path)
        self.sampling_data = DataLoader(sampling_data_path)
        self.models_chain = DataLoader(models_chain_path)
        self.chains_data = DataLoader(chains_data_path)

        if topology == "performance":
            self.ignore_coluns = ['Suite','Program','id']

        else:
            self.ignore_coluns = ['id','type']

        self.topology = topology

    def upload_single_file_to_drive(self,code_name,program):#Upload file to drive for colab
        try:
            folder_id = '' #need to add the folder id
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

    def upload_chain_file_to_drive(self,program,folder_id,folder_name,n):#Upload file to drive for colab
        try:
            local_file_path = f"/content/{folder_name}{n}.c"


            with open(local_file_path, "w") as file:
             file.write(program)


            file_metadata = {
                'name': f'{folder_name}{n}.c',
                'parents': [folder_id]
            }

            media = MediaFileUpload(local_file_path, mimetype='text/plain')
            service = build('drive', 'v3')
            uploaded_file = service.files().create(body=file_metadata, media_body=media, fields='id').execute()

            print(f"File uploaded successfully. File ID: {uploaded_file.get('id')}")
        except Exception as e:
            print(f"File could not be uploaded. ERROR: {e}")


    def folder_generator(self,parent_folder_id,size=4):
        chars=string.ascii_uppercase
        random_name = ''.join(random.choice(chars) for _ in range(size))
        while random_name in self.chains_data.column_values('folder_id'):
            random_name = ''.join(random.choice(chars) for _ in range(size))

        folder_metadata = {
            'name': random_name,
            'mimeType': 'application/vnd.google-apps.folder'
        }

        if parent_folder_id:
            folder_metadata['parents'] = [parent_folder_id]

        service = build('drive', 'v3')
        created_folder = service.files().create(
            body=folder_metadata,
            fields='id'
        ).execute()

        return created_folder.get('id'),random_name

    def find_folder(self, parent_folder_id: str, folder_name: str):
        try:
            drive_service = build('drive', 'v3')

            query = f"'{parent_folder_id}' in parents and name = '{folder_name}' and mimeType = 'application/vnd.google-apps.folder'"

            results = drive_service.files().list(
                q=query,
                fields='files(id, name)'
            ).execute()

            folders = results.get('files', [])

            if folders:
                return folders[0]['id'], folders[0]['name']
            else:
                return None, None

        except Exception as e:
            raise f"Folder coulnd't been founded: {e}"

    def single_code_generation(self, max_len: int, static: bool = False, id: int = 0) -> float:#Single Program Generation
        try:
            input_value = ""

            if static:#Static Value
                input_value,input_id = self.input_data.static_row_string(id,self.ignore_coluns)

            else:#Random
                input_value,input_id = self.input_data.random_row_string(self.ignore_coluns)


            base_code = """ int f(int a) {
                return 0;
                }"""

            generator = CodeGeneration(
            model=self.model,
            model_name=self.model_name,
            tokenizer=self.tokenizer,
            data=self.models_data,
            input_str=input_value,
            input_id=input_id,
            max_length=max_len,
            base_code=base_code,
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



    def single_sampling(self,first_max_length=1024,max_lenght_pow=1,sample=12):#Simulate different generation for time measure

        current_max_length = first_max_length#Begin with some length
        time_array = np.array([])

        for _ in range(max_lenght_pow):

            for _ in range(sample):
                time_temp = self.single_code_generation(current_max_length) #time spent

                time_array = np.append(time_array,time_temp)


            sampling_output = [self.model_name,
                                 np.mean(time_array),
                                 np.std(time_array),
                                 sample,
                                 current_max_length
                                ,np.min(time_array),
                                 np.max(time_array)]


            self.sampling_data.new_row(sampling_output)
            self.sampling_data.save()

            time_array = np.empty(0)

            current_max_length *= 2 #make it double beacause could grow better

        print("Sampling Done!")

    def chain_code_generation(self, max_len: int, n: int = 1) -> float:
        try:
            ac_time = 0
            base_code = """ int f(int a) {
                    return 0;
                    }"""
            i = 0
            last_code_id = ''
            folder_id,folder_name = self.folder_generator('1y_BZ7M_Rpq7q4TEoRQiGMkfDWhR0okan')
            for _ in range(n):
                input_value,input_id = self.input_data.random_row_string(self.ignore_coluns)

                generator = CodeGeneration(
                model=self.model,
                model_name=self.model_name,
                tokenizer=self.tokenizer,
                data=self.models_data,
                input_str=input_value,
                input_id=input_id,
                max_length=max_len,
                base_code=base_code,
                topology=self.topology
                )

                generator.generate_code()

                program = generator.program_extratcion()

                output_list = generator.get_output_list()


                if(output_list[4] > 0):
                    if i==0:
                        last_code_id = 'None'
                    else:
                        last_code_id = f'{folder_name}{i}'

                    i = i + 1

                    output_list.append(last_code_id)
                    output_list.append(folder_name)
                    output_list[2] = f'{folder_name}{i}'

                    self.models_chain.new_row(output_list)
                    self.models_chain.save()


                    self.upload_chain_file_to_drive(program,folder_id,folder_name,i)


                    ac_time = ac_time + output_list[1]
                    base_code = program

                    print("Program Generated:\n" + program)

            #folder_id,num_regression,time_spent,mean_time_program,std_time,compilation
            rows_chain = [folder_name,i,ac_time,0,0,"False"]
            self.chains_data.new_row(rows_chain)
            self.chains_data.save()

            return ac_time
        except Exception as e:
            print(f"ERRO: {e}")

    def chain_sampling(self,first_max_length=1024,max_lenght_pow=1,sample=12,iterations=6):

        current_max_length = first_max_length#Begin with some length
        time_array = np.array([])
        iterations = random.randint(1,15)

        for _ in range(max_lenght_pow):

            for _ in range(sample):
                time_temp = self.chain_code_generation(current_max_length,iterations) #time spent

                time_array = np.append(time_array,time_temp)


            sampling_output = [self.model_name,
                                 np.mean(time_array),
                                 np.std(time_array),
                                 sample,
                                 current_max_length
                                ,np.min(time_array),
                                 np.max(time_array)]


            self.sampling_data.new_row(sampling_output)
            self.sampling_data.save()

            time_array = np.empty(0)

            current_max_length *= 2 #make it double beacause could grow better

        print("Sampling Done!")




    def continue_chain(self, folder_chain: str , max_len: int, n: int = 1) -> float:
        try:
            chain_values = self.chains_data.get_row('folder_id',folder_chain)

            base_code = """ int f(int a) {
                    return 0;
                    }"""

            with open(f'/content/drive/My Drive/Colab_Notebooks/Baku/codes/{folder_chain}/{folder_chain}{chain_values[0]}.c', 'r') as f:
                base_code = f.read()

            ac_time = chain_values[1]
            i = chain_values[0]
            last_code_id = ''
            folder_id,folder_name = self.find_folder('1y_BZ7M_Rpq7q4TEoRQiGMkfDWhR0okan',folder_chain)
            for _ in range(n):
                input_value,input_id = self.input_data.random_row_string(self.ignore_coluns)

                generator = CodeGeneration(
                model=self.model,
                model_name=self.model_name,
                tokenizer=self.tokenizer,
                data=self.models_data,
                input_str=input_value,
                input_id=input_id,
                max_length=max_len,
                base_code=base_code,
                topology=self.topology
                )

                generator.generate_code()

                program = generator.program_extratcion()

                output_list = generator.get_output_list()


                if(output_list[4] > 0):
                    if i==0:
                        last_code_id = 'None'
                    else:
                        last_code_id = f'{folder_name}{i}'

                    i = i + 1

                    output_list.append(last_code_id)
                    output_list.append(folder_name)
                    output_list[2] = f'{folder_name}{i}'

                    self.models_chain.new_row(output_list)
                    self.models_chain.save()


                    self.upload_chain_file_to_drive(program,folder_id,folder_name,i)


                    ac_time = ac_time + output_list[1]
                    base_code = program

                    print("Program Generated:\n" + program)

            #folder_id,num_regression,time_spent,mean_time_program,std_time,compilation
            rows_chain = [folder_name,i,ac_time,0,0,"False"]
            self.chains_data.new_row(rows_chain)
            self.chains_data.save()

            return ac_time
        except Exception as e:
            print(f"ERRO: {e}")
