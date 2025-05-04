#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, false, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vp vector<pair<int,int>>
#define fast_io ios_base :: sync_with_stdio(false); cin.tie(nullptr);
#define vvi vector<vector<int>>
#define rep(i,n) for(int i = 0; i < n; i++)
#define Rep(i,a,b) for(int i = a; i < b; i++)
#define int long long
 
map<int,int> mp;
void dfs(int node, int par, vvi &adj, vi &dp){
    if(mp[node]==1){
        dp[node]=0;
        return;
    }
 
    for(int i:adj[node]){
        if(i!=par){
            dfs(i,node,adj,dp);
            dp[node]+=1+dp[i];
        }
    }
}
 
signed main(){
    fast_io;
    int t;
    t=1;
    while(t--){
        mp.clear();
        int n; cin>>n;
        vvi adj(n);
        for(int i=1;i<n;i++){
            int x; cin>>x;
            x--;
            adj[i].pb(x);
            adj[x].pb(i);
            mp[x]++;
            mp[i]++;
        }
        mp[0]++;
        vi dp(n,0);
        dfs(0,-1,adj,dp);
        for(int i:dp){
            cout<<i<<" ";
        }
    }
}
