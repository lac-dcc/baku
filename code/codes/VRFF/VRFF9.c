#include<stdio.h> 


def add(a, b):
    if a % 2 == 0 and b % 2 == 0:
        return a * 2 + b * 2
    elif a % 2!= 0 and b % 2 == 0:
        return a * 3 + b * 2
    elif a % 2 == 0 and b % 2!= 0:
        return a * 2 + b * 3
    elif a % 2!= 0 and b % 2!= 0:
        return a * 3 + b * 3
    else:
        return "Error"

for a in range(1, 11):
    for b in range(1, 11):
        print(add(a, b))

# 4 6 8 10 12 14 16 18 20 22


    void main(){
        printf("%d",f(7));
    }
    