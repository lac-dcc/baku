#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    int arr[102],dp[1000003];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<=x;i++){
        if(i==0){
            dp[i]=0;
        }
        else{
            dp[i]=1e9;
            for(int j=0;j<n;j++){
                if(arr[j]<=i){
                    dp[i]=min(1+dp[i-arr[j]],dp[i]);
                }
            }
        }
 
    }
    if(dp[x]==1e9){
        cout<<-1<<endl;
    }
    else{
    cout<<dp[x]<<endl;
    }
}