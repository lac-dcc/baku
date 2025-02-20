import numpy as np
from data_loader import DataLoader
from code_generator import CodeGeneration
from googleapiclient.discovery import build
from googleapiclient.http import MediaFileUploadclass 
class GenerationPipeline:
    def __init__(
            self,
            model: object,
            model_name: str,
            tokenizer: object,
            simulation_data_path: str,
            models_data_path: str,
            input_data_path: str,
            topology: str = 'regression'  # Nome corrigido
        ):
        self.model = model 
        self.model_name = model_name
        self.tokenizer = tokenizer
        self.input_data = DataLoader(input_data_path)
        self.models_data = DataLoader(models_data_path)
        self.simulation_data = DataLoader(simulation_data_path)
        
        if topology == "performance":
            self.ignore_coluns = ['Suite','Program','id']
        
        else:
            self.ignore_coluns = ['id','type']
            
        self.topology = topology
        
    def upload_file_to_drive(self,code_name,program):#Upload file to drive for colab
        try:
            folder_id = '1y_BZ7M_Rpq7q4TEoRQiGMkfDWhR0okan'
            local_file_path = f"/content/{code_name}.c"
            drive_service = build('drive', 'v3')



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
            
            if(output_list[6] > 0):
                self.upload_file_to_drive(output_list[2],program)#Save generation
        
            self.models_data.new_row(output_list)
            self.models_data.save()
            
            print("Program Generated:\n" + program)
            return output_list[1] 
        except Exception as e:
            print(f"ERRO: {e}")

   
   
    def single_simulation(self,first_max_length=1024,max_lenght_pow=1,sample=12):#Simulate different generation for time measure

        current_max_length = first_max_length#Begin with some length
        time_array = np.array([])

        for i in range(max_lenght_pow):

            for j in range(sample):
                time_temp = self.single_code_generation(current_max_length) #time spent

                time_array = np.append(time_array,time_temp)


            simulation_output = [self.model_name,
                                 np.mean(time_array),
                                 np.std(time_array),
                                 0,
                                 0,
                                 sample,
                                 current_max_length
                                ,np.min(time_array),
                                 np.max(time_array)]


            self.simulation_data.new_row(simulation_output)
            self.simulation_data.save()

            time_array = np.empty(0)

            current_max_length *= 2 #make it double beacause could grow better

        print("Simulation Done!")     
    
    def chain_code_generation():
        return 0
        #empty for now

    def chain_simulation():
        return 0
        #empty for now
        