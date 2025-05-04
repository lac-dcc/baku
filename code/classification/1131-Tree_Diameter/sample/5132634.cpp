#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn = 2e5+10;
vector<int> G[maxn];
int hei[maxn],dp[maxn];
void init(){
    int u,v;
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
}
void dfs(int u , int p){
    int max_hei=0, sec_hei=0;
    for(auto v:G[u]){
        if(v==p) continue;
        dfs(v,u);
        dp[u] = max(dp[u] , dp[v]);
        if(hei[v]>max_hei) sec_hei=max_hei , max_hei=hei[v];
        else if(hei[v]>sec_hei) sec_hei=hei[v];
    }
    hei[u] = max_hei+1;
    dp[u] = max(dp[u] , max_hei+sec_hei);
}
void solve(){
    for(int i=0;i<=n;i++) dp[i]=0, hei[i]=0;
    dfs(1,-1);
    cout<<dp[1];
}
int main(){
    init();
    solve();
}
