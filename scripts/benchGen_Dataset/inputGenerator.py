with open("inputGenerator.sh", "w") as f:
    f.write("#!/bin/bash\n")
    for i in range(1, 11):
        for j in range(1,21):
            f.write(f'echo "Generating input for {i}_{j}"\n')
            f.write(f'./benchGen {i} program_gen_dataset/rules{j}.txt program_gen_dataset/seed{j}.txt array{i}_{j} array\n')
            f.write(f'./benchGen {i} program_gen_dataset/rules{j}.txt program_gen_dataset/seed{j}.txt sortedlist{i}_{j} sortedlist\n')
            f.write("echo \n")