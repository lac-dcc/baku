#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int t,n,x,y,l,ans;
    cin>>t;
    while(t--){
        cin>>x>>y;
        int j=max(x,y);
        if(j==x){
           if(j%2==0){
             l=j*j;
             ans=l-y+1;
           } 
           else
           {
               l=(j-1)*(j-1);
               ans=l+y;
           }
        }
        else{
            if(j%2==0){
                l=(j-1)*(j-1);
                ans=l+x;
            }
            else{
                l=j*j;
                ans=l-x+1;
            }
        }
        cout<<ans<<"\n";
    }
}