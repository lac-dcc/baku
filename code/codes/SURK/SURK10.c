#include<stdio.h> 

            
            int f(int a, int b, int c) {
                for (int i = 0; i < a; i++) {
                    if (i % 2 == 0) {
                        if (i > 10 && i % 4 == 0) {
                            if (i > 20 && i < 30) {
                                return i * 2 + b;
                            } else {
                                return i + b;
                            }
                        } else {
                            if (i > 10 && i < 20) {
                                return i * 2 + c;
                            } else {
                                if (i > 20) {
                                    return i * 3 + b + c;
                                } else {
                                    return i + b + c;
                                }
                            }
                        }
                    }
                    if (i > 10 && i < 20) {
                        return i * 2 + c;
                    }
                    if (i > 20) {
                        return i * 3 + b + c;
                    }
                    if (i == 0) {
                        return i + b + c;
                    }
                    if (i % 3 == 0) {
                        return i * 2 + b + c;
                    }
                    if (i > 0) {
                        return i + b + c;
                    }
                    if (i == i) {
                        return i + b + c;
                    }
                    if (i!= i) {
                        return b + c;
                    }
                    if (i == 15) {
                        return i * 4 + b + c;
                    }
                }
                return b + c;
            }
            
            
    void main(){
        printf("%d",f(7));
    }
    