#include<stdio.h> 

            int f(int a) {
                if (a > 0 && a < 100)
                {
                    if (a % 2 == 0)
                    {
                        if (a % 3 == 0)
                        {
                            if (a % 5 == 0)
                            {
                                if (a % 7 == 0)
                                {
                                    if (a % 11 == 0)
                                    {
                                        if (a % 13 == 0)
                                        return a;
                                        else
                                        return 0;
                                    }
                                    else
                                    return 0;
                                }
                                else
                                return 0;
                            }
                            else
                            return 0;
                        }
                        else
                        return 0;
                    }
                    else
                    return 0;
                }
                else
                return 0;
                }
            
    void main(){
        printf("%d",f(7));
    }
    