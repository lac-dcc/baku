#include <bits/stdc++.h>
using namespace std;
 
 
int dfs(int sv, int p, vector<vector<int>>& g, vector<int>& dp){
    int r = 1;
    for(auto i : g[sv]){
        if(p!=i){
            r += dfs(i, sv,g, dp);
        }
    }
    return dp[sv] = r;
}
    
int main() {
 
    int n; cin>>n; 
    vector<vector<int>> g(n);  
    for(int i=1; i<n; i++) { int x; cin>>x; g[i].push_back(x-1); g[x-1].push_back(i); 
    }
    // for(auto i  : g) {for(auto .j : i) cout<<j<<" "; cout<<endl;}
    vector<int> dp(n); 
 
    dfs(0, -1, g, dp); 
 
    for(int i=0; i<n; i++) cout<<dp[i]-1<<endl ;
 
}
