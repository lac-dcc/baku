import DataLoader
import CodeGenerator
import numpy as np

class GenerationPipeline:
    def __init__ (self,model,model_name,tokenizer,simulation_data_path,
                  models_data_path,input_data_path,typolgy='regression'):
        self.model = model 
        self.model_name = model_name
        self.tokenizer = tokenizer
        self.input_data = DataLoader(input_data_path)
        self.models_data = DataLoader(models_data_path)
        self.simulation_data = DataLoader(simulation_data_path)
        
        if typolgy is "performance":
            self.ignore_coluns = ['Suite','Program','id']
        
        else:
            self.ignore_coluns = ['id']
        
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
    
    def single_code_generation(self,max_len,static=False,id=0):#Single Program Generation
        try:
            input_value = ""
            
            if not static == 0:#Static Value
                input_value,input_id = self.input_data.static_row_string(id,self.ignore_coluns)
            
            else:#Random
                input_value,input_id = self.input_data.random_row_string(self.ignore_coluns)
            
            generator = CodeGenerator(self.model,self.model_name,self.tokenizer,self.model_data,input_value,
                                    input_id, max_len, base_code="", perf=self.typolgy)
            
            generator.generate_code()
            
            program = generator.program_extratcion()
            
            output_list = generator.get_output_list()
            
            self.upload_file_to_drive(output_list[2],program)#Save generation
        
            self.model_data.new_row(output_list)
            self.model_data.save()
            
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


            simulation_output = [self.model_name,np.mean(time_array),sample,current_max_length
                                ,np.min(time_array),np.max(time_array)]


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
        