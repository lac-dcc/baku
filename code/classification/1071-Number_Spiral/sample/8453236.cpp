#include <bits/stdc++.h>
using namespace std;
 
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long a, b;
        cin>>a>>b;
        if(a>=b ){
            if(a%2){
                cout<<(a-1)*(a-1) + b<<endl;
            }
            else{
                cout<<a*a + 1 -b<<endl;
            }
        }
        if(b>a ){
            if(b%2){
                cout<<b*b + 1 - a<<endl;
            }
            else{
                cout<<(b-1)*(b-1) + a<<endl;
            }
        }
      
    }
    
 
    return 0;
}
