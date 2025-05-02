#include<stdio.h> 

            
                                             int f(int a) {
                                                    int arr[] = {1, 2, 3, 4, 5};
                                                    int prev = 0;
                                                    for (int i = 0; i < 5; i++) {
                                                        if (i == 0) {
                                                            prev = arr[i];
                                                        } else if (arr[i] > prev) {
                                                            return arr[i];
                                                        }
                                                        prev = arr[i];
                                                        if (i == 2) {
                                                            if (arr[i] == 3) {
                                                                arr[i] = 0;
                                                            }
                                                        }
                                                    }
                                                    return 0;
                                                }
                                            

            
    void main(){
        printf("%d",f(7));
    }
    