#include<stdio.h> 

            #include <string.h>
            struct Person {
                int age;
                char name[20];
            };

            int f(int a) {
                struct Person person;
                person.age = 30;
                strcpy(person.name, "John");
                return 0;
                }
            
    void main(){
        printf("%d",f(7));
    }
    