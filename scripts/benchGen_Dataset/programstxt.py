with open('scripts/benchGen_Dataset/programs.txt', 'w') as f:
    for i in range (1, 16):
        for j in range(1, 21):
            for type in ['array', 'sortedlist']:
                f.write(f'code/benchgen/source/{type}{i}_{j}\n')