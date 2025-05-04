#include <bits/stdc++.h>
#include <iostream>
 
#define ll long long
#define ui unsigned int
 
#define INF 1e9
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
 
int main(){
    ll test, x,y;
    cin>>test;
    while(test--){
        cin>>y>>x;
        if(y>x){
            if(y%2 == 0){
                cout<<y*y- x+1;
            }else{
                y--;
                cout<<(y*y) + x;
            }
        }else{
            if(x%2 == 1){
                cout<< x*x - y+1;
                        //System.out.println((x*x) - (y-1));
            }else{
                x--;
                cout<<(x*x) + y;
                        //long temp = ;
                        //System.out.println(((x-1)*(x-1) ) + (y));
            }
 
        }
        cout<<"\n";
    }
      
 
return 0;
}