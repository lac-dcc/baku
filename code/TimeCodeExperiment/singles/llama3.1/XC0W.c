#include<stdio.h> 

             int f(int a) {
                if (a > 5) {
                    if (a % 2 == 0) {
                        if (a > 10) {
                            if (a % 3 == 0) {
                                if (a < 15) {
                                    if (a > 7) {
                                        if (a % 4 == 0) {
                                            if (a > 12) {
                                                if (a % 5 == 0) {
                                                    if (a < 20) {
                                                        if (a % 6 == 0) {
                                                            if (a > 18) {
                                                                if (a % 7 == 0) {
                                                                    return 1;
                                                                }
                                                                return 0;
                                                            }
                                                            return 0;
                                                        }
                                                        return 0;
                                                    }
                                                    return 0;
                                                }
                                                return 0;
                                            }
                                            return 0;
                                        }
                                        return 0;
                                    }
                                    return 0;
                                }
                                return 0;
                            }
                            return 0;
                        }
                        return 0;
                    }
                    return 0;
                }
                return 0;
                }
            
    void main(){
        printf("%d",f(7));
    }
    