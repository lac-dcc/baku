#include<stdio.h> 

            
# Define the function f, which returns the sum of its four arguments
def f(a, b, c, d):
    # Return the sum of a, b, c, and d
    return a + b + c + d

# Define the function g, which returns the product of its four arguments
def g(a, b, c, d):
    # Return the product of a, b, c, and d
    return a * b * c * d

# Define the function h, which returns the sum of the results of f and g
def h(a, b, c, d):
    # Return the sum of the results of f and g
    result = f(a, b, c, d) + g(a, b, c, d)
    if result > 100:
        return "Result is too large"
    else:
        return result

# Call the function f with the arguments 1, 2, 3, and 4, and print the result
print(f(1, 2, 3, 4))

# Call the function g with the arguments 1, 2, 3, 4, and print the result
print(g(1, 2, 3, 4))

# Call the function h with the arguments 1, 2, 3, 4, and print the result
print(h(1, 2, 3, 4))

# This is a comment, which is ignored by the Python interpreter
# 

            
    void main(){
        printf("%d",f(7));
    }
    