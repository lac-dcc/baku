CC = clang
DALLOCFLAGS = -Wl,--wrap=malloc -Wl,--wrap=free -I "/home/natan/Documents/projetos/Bench-projects/BenchGen/src/genDalloc/src"
LLVMFLAGS = -S -emit-llvm -I"/home/natan/Documents/projetos/Bench-projects/BenchGen/src/genDalloc/src"
TARGET = outs/3_2_array
SRC_DIR = src
OBJ_DIR = obj
LL_DIR = ll

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
LL = $(patsubst $(SRC_DIR)/%.c, $(LL_DIR)/%.ll, $(SRC))

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) ${DALLOCFLAGS} $(OBJ) "/home/natan/Documents/projetos/Bench-projects/BenchGen/src/genDalloc/src/Dalloc.c" -o $(TARGET) 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) ${CFLAGS} -I "/home/natan/Documents/projetos/Bench-projects/BenchGen/src/genDalloc/src" -c $< -o $@

$(LL_DIR)/%.ll: $(SRC_DIR)/%.c | $(LL_DIR)
	$(CC) ${LLVMFLAGS} $< -o $@

$(OBJ_DIR) $(LL_DIR):
	mkdir -p $@

$(LL_DIR)/fullprogram.ll: $(LL)
	llvm-link -S -o $@ $^

llvm: $(LL) $(LL_DIR)/fullprogram.ll

clean:
	rm -f $(OBJ) $(LL) $(TARGET)
	rm -rf $(OBJ_DIR) $(LL_DIR)

