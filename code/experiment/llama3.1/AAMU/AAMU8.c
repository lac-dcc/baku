#include<stdio.h> 

            <h1>Explanation</h1>
            <p>This program demonstrates the use of a loop with a complex condition and a statement inside. The loop iterates 5 times, but breaks after the third iteration due to the condition `i == 3`. The function `f` is called with the arguments 0, 0, and 0, and its result is stored in the variable `a`. The value of `a` is then printed to the console.</p>
            <p>The dead code block `if(0)` is used to demonstrate how the compiler handles unreachable code. In this case, the code inside the block will never be executed, as the condition `0` is always false.</p>
            <p>The function `f` takes three integer parameters `x`, `y`, and `z`, and returns an integer value. It checks if the value of `x` is greater than 5, and if so, returns 10; otherwise, it returns 0.</p>
            <p>The program also includes a call to the function `f` with the arguments 10, 0, and 0, and prints the result to the console.</p>
            
    void main(){
        printf("%d",f(7));
    }
    