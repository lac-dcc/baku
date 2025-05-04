#include<bits/stdc++.h>
using namespace std;
int main(){
 
        long long  int  n;
cin >>  n ;
 
 
 
 
 
 
 
 
 
                                                              for( long long int i=1; i<=n; i++)
                                                              {
                                                                         long long int x,y;
                                                                        cin >> x >> y ;      long long  int z=(max(x,y)*max(x,y))-(max(x,y)-1) ;   if(max(x,y)%2==0){if(y<x){cout << z+(max(x,y)-y) << "\n"  ;} if(x<y) { cout << z-(max(x,y)-x) << "\n" ;}         if(x==y){cout <<  z << "\n" ; } }else{if(y<x){cout << z-(max(x,y)-y) << "\n"  ;} if(x<y) { cout << z+(max(x,y)-x) << "\n" ;}                    if(x==y){cout << z << "\n" ;}    }
                                                              }
 
 
 
 }
