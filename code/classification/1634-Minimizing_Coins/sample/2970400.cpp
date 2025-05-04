#include<bits/stdc++.h>
using namespace std;
vector<int> arr;
int dp[1000010];
 
int solve(int now){
    if(now<0){
        return 999999999;
    }
    if(now==0){
        return 0;
    }
    //cout<<now<<" "<<cnt<<endl;
    if(dp[now]==0){
        int ans=999999999;
        for(int i=0;i<arr.size();i++){
            int temp=solve(now-arr[i])+1;
            ans=min(temp,ans);
        }
        dp[now]=ans;
    }
    return dp[now];
}
int main(){
    int n,x;
    cin>>n>>x;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    int temp=solve(x);
    if(temp==999999999){
        cout<<-1<<endl;
    }
    else{
    cout<<solve(x)<<endl;
    }
}