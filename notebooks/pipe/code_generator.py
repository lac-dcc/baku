import time
import string
import random
import subprocess
from data_loader import DataLoader

class CodeGeneration:

    def __init__(self,model,model_name,tokenizer,data : DataLoader,input_str: str,input_id : int,
                 max_length : int, base_code: str = "", topology="regression"):
        self.model = model
        self.model_name = model_name
        self.data = data
        self.input_str = input_str
        self.max_length = max_length
        self.input_id = input_id
        self.tokenizer = tokenizer
        self.base_code = base_code

        if topology == "performance":
            self.template =  f"""
        Generate a C program optimized for the following Linux `perf` statistics:
        {self.input_str}

        - **Requirements**:
            1. The program must contain a main function that receives the data and invokes the processing logic.
            2. Address performance bottlenecks (e.g., cache misses, branch mispredictions) using:
            - Loop unrolling, SIMD intrinsics (AVX/SSE), memory alignment.
            - Data structure optimizations (e.g., cache-friendly layouts).
            3. **Fuzzer-Specific Constraints**:
            - Process raw bytes from `const uint8_t* data` and `size_t size` as input.
            - Avoid undefined behavior: validate buffer bounds, sanitize inputs.
            - Exclude I/O operations (e.g., `printf`, file access).
            4. Code Style:
            - Zero comments or explanations.
            - Use preprocessor directives only when critical (e.g., `#include <stdint.h>`).
            5. Enclose the code between <Program> tags.

        - **Output Format**:
            <Program>
            // C code here
            </Program>
        """

        else:
             self.template = f"""
        Complete the following C code, {self.input_str}:
        {self.base_code}


        - **Requirements**:
            1. The program must be a completicion to the base code.
            2. Enclose the code between <Program> tags.
        - **Output Format**:
            <Program>
            {self.base_code}
            </Program>
        """

        self.dif_seconds = 0
        self.ouput = ""
        self.program_name = ""
        self.program = ""


    def generate_code(self,response=True):#Measure time and generate the code
        input_time = time.time()
        inputs = self.tokenizer(self.template, return_tensors="pt").to(self.model.device)
        outputs = self.model.generate(**inputs, max_length=self.max_length) #model output
        output_time = time.time()

        self.dif_seconds = (output_time - input_time) #time measure
        decoded_output = self.tokenizer.decode(outputs[0], skip_special_tokens=True)
        self.output = decoded_output

        if(response):
            print('The output was:' + decoded_output)
            print(f'Time spend in the code generation: {self.dif_seconds}')


    def get_output_list(self):#Return the data from the program generation
        if (self.program_name == "") or (self.program == ""):
            program = self.program_extratcion()

        if(self.base_code in self.program):#Do not accept base code as a generated code

            len_program = len(self.tokenizer.encode(self.program)) #count the amount of tokens in the program
            return [self.model_name,
                    self.dif_seconds,
                    self.program_name,
                    self.input_id,
                    -1]

        len_program = len(self.tokenizer.encode(self.program)) #count the amount of tokens in the program
        return [self.model_name,
                self.dif_seconds,
                self.program_name,
                self.input_id,
                len_program]


    def program_extratcion(self):#Return the program generated"
        self.name_generator()

        if self.program == "":
            final_program = ""
            suboutput_list = self.output.split("<Program>")

            for subprogram in (suboutput_list):
              if "</Program>" in subprogram:
                program = subprogram.split("</Program>")[0]

                if program.count('{') == program.count('}'):
                        final_program = program

            self.program = final_program

        return self.program


    def name_generator(self,size=4): #Randomly generate a new file name

        if self.program_name == "" :
            chars=string.ascii_uppercase + string.digits
            random_name = ''.join(random.choice(chars) for _ in range(size))
            while random_name in self.data.column_values('code_name'):
                random_name = ''.join(random.choice(chars) for _ in range(size))
            self.program_name = random_name


