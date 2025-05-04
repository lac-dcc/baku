#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
 
 
int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s,t;
    cin>>s>>t;
    int n = s.size(), m = t.size();
    vector dp(n+1, vector(m+1, -1));
    dp[0][0] = 0;
    for(int i=1;i<=n;++i){
        dp[i][0] = i;
    }
    for(int i=1;i<=m;++i){
        dp[0][i] = i;
    }
    // function<int(int,int)> dfs = [&](int x,int y){
    //     if(dp[x][y]!=-1) return dp[x][y];
    //     return dp[x][y] = min(dfs(x-1,y-1) + (s[x-1]!=t[y-1]), min(dfs(x-1,y)+1, dfs(x,y-1)+1));
    // };
    // dfs(n,m);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            dp[i][j] = min(dp[i-1][j-1]+(s[i-1]!=t[j-1]), min(dp[i-1][j]+1,dp[i][j-1]+1));
        }
    }
    cout<<dp[n][m]<<'\n';
    
    return 0;
}