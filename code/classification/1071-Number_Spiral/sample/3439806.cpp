//#include<bits/stdc++.h>
#include<iostream>
#define ll long long 
using namespace std;
 
 
int main()
{
 
    ll int t;
    cin>>t;
 
    while(t--){
        ll int x,y;
        cin>>y>>x;
 
        if(y>x){
            ll ans;
 
             if(y%2 == 1){
                ans =  (y-1)*(y-1) + x;
                cout<<ans<<endl;
            }
            else{
                ans = y*y - x + 1;
                cout<<ans<<endl;
            }
        }
        else {
            ll ans;
 
            if(x%2 != 0){
                ans = x*x -y + 1 ;
                cout<<ans<<endl;
            }
 
            else{
                ans = (x-1)*(x-1) + y;
                cout<<ans<<endl;
            }
        }
    }
   
return 0;
 
}