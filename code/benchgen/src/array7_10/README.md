# array7_10 Program

This program was generated by the **BenchGen** tool.

## Compilation

There are two ways to compile the program:

1. Standard Compilation:

    ```bash
    make
    ```

    This will create:

    - The executable file `array7_10`

    - The object files in the `obj` directory

2. LLVM Compilation:

    ```bash
    make llvm
    ```

    This will create and `ll` folder containing `.ll` files, which are LLVM IR (Intermediate Representation).

### Compiling with debug mode:

If you want to include debug prints in the output, compile the program with the `-DDEBUG` flag by modifying the `CFLAGS` during the `make` command:

```bash
make CFLAGS="-DDEBUG"
```

This will create an executable with debug mode enabled, which prints additional debugging information to the terminal during execution.

## Run

To run the program, execute the following command:

```bash
./array7_10
```

### Optional Arguments

This program accepts the following optional arguments:

-   `-path-seed <seed>`: Sets the seed for the random number generator. Default is `0`.

-   `-loops-factor <factor>`: Sets the factor for the number of loops. Default is `100`.

#### Example:

```bash
./array7_10 -loops-factor 50 -path-seed 123
```