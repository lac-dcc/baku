with open("inputGenerator.sh", "w") as f:
    f.write("#!/bin/bash\n")
    for i in range(1, 6):
        for j in range(0,10):
            f.write(f'./benchGen {i}, examples/ex{j}/production_rule.txt examples/ex{j}/seed_string.txt outs/{i}_{j}_array array\n')
            # f.write(f'./benchGen {i}, examples/ex{j}/production_rule.txt example/ex{j}/seed_string.txt outs/{i}_{j}_sortedList sortedList\n')
