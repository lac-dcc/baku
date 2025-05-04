#include <bits/stdc++.h>
using namespace std;
#define int long long
std::vector<int> g[200005];
int dp[200005];
int dfs(int u)
{
    int mx = 0;
    for(auto v:g[u])
    {
       mx += dfs(v);
    }
 
    dp[u] = mx;
 
    return 1 + mx;
 
}
signed main()
{    
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif    
 
    int n;
    cin >> n;
 
    for(int i=2;i<=n;i++)
    {
        int x;cin >> x;
        g[x].push_back(i);
    }
    int x =  dfs(1);
    for(int i=1;i<=n;i++)cout << dp[i] << ' ';
}
 
