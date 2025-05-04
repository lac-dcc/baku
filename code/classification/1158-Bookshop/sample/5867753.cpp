// this is simply 0/1 knapsack 
#include<bits/stdc++.h>
using namespace std; 
int main(){
    int n,w; cin>>n>>w; 
    vector<int> weights(n),profit(n);
    for(auto &elm: weights) cin>>elm; 
    for(auto &elm: profit) cin>>elm; 
    // now dp[i][j] is largest profit we can get considering weights till index i only 
    // and j being amount of money you have 
    // also we have either take it or don't take it types of states 
    // dp[i][j] = max(dp[i-1][j],dp[i][j-wegihts[i]] + profit[i])
    vector<int> prev(w+1,0),cur(w + 1,0); 
    for(int i=0;i<n;i+=1){
        for(int j=0;j<=w;j+=1){
            if(j<weights[i]) cur[j] = prev[j]; 
            else cur[j] = max(prev[j - weights[i]] + profit[i],prev[j]);
        }
        swap(prev,cur); 
    } 
    cout<<prev.back()<<endl; 
}
