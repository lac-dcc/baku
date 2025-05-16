#include<stdio.h> 

        struct Person {
                char name[20];
                int age;
                };

        int f(int a) {
                struct Person person;
                person.name[0] = 'J';
                person.name[1] = 'o';
                person.name[2] = 'h';
                person.name[3] = 'n';
                person.name[4] ='';
                person.name[5] = 'D';
                person.name[6] = 'o';
                person.name[7] = 'e';
                person.name[8] ='';
                person.name[9] = 'S';
                person.name[10] ='m';
                person.name[11] = 'i';
                person.name[12] = 't';
                person.name[13] = 'h';
                person.name[14] = '.';
                person.name[15] = '\0';
                person.age = 25;
                printf("Name: %s, Age: %d\n", person.name, person.age);
                return 0;
                }
        
    void main(){
        printf("%d",f(7));
    }
    