#include <bits/stdc++.h>
using namespace std;
#define int long long
const int A = 1e9;
const int mod = 1e9 + 7;
int dp[300005];
 
int count(int node, vector<int> adj[], vector<int> &vis)
{
     dp[node]=1;
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
 
          dp[node]+=count(it, adj, vis);
    }
 
    return dp[node];
}
 
int32_t main()
{
    int t=1;
   // cin >> t;
 
    while (t--)
    {
        int n;
        cin >> n;
        memset(dp, 0, sizeof(dp));
        vector<int> adj[n + 1];
        for (int i = 2; i <= n; i++)
        {
            int a;
            cin >> a;
 
            adj[i].push_back(a);
            adj[a].push_back(i);
        }
        vector<int> vis(n + 1, 0);
        count(1, adj, vis);
 
        // for(int  i=1;i<=n;i++)
        // {
        //     cout<<dp[i]<<" ";
        // }
        // cout<<'\n';
 
        // int ans=0;
        // vector<int>viss(n+1,0);
        // dfs(1,adj,ans,-1,viss);
        // cout<<ans<<"\n";
 
        for (int i = 1; i <= n; i++)
        {
            cout << dp[i]-1 << " ";
        }
    }
}
