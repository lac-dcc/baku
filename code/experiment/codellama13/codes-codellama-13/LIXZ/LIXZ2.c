#include<stdio.h> 

            
             int f(int a) {
                    if(a>0)
                    return 0;
                    else if(a<0)
                    return 1;
                    else if(a==0)
                    return 2;
                    else if(a==1)
                    return 3;
                    else
                    return 4;
                    }
            
            
    void main(){
        printf("%d",f(7));
    }
    