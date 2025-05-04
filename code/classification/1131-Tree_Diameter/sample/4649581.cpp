#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
#define endl "\n"
#define pb push_back
#define mod 1000000007 
#define N 500010
#define inf 100000000000000000
// 1. brute force | 2. two pointers | 3. Prefix sum | 4. Binary search 
// 5. DSU | 6. Graphs | 7. DP
int n,ans = 0;
vector<vector<int>>gr,dp;
// dp[i][0] => max diameter of subtree i and path ending at i
// dp[i][1] => max diameter of subtree i not ending at i
void dfs(int node, int p)
{
    vector<int>temp;
    if(node != 1 and gr[node].size()==1)
        return;
    for(auto i:gr[node])
    {
        if(i == p)
            continue;
        dfs(i,node);
        temp.pb(dp[i][0]);
    }
    sort(temp.rbegin(),temp.rend());
    if(temp.size()==1)
    {
        dp[node][0] = temp[0]+1;
        dp[node][1]=0;
    }
    else
    {
        dp[node][0] = temp[0]+1;
        dp[node][1] = 2+temp[0]+temp[1];
    }
    ans=max(ans,max(dp[node][0],dp[node][1]));
}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    gr=vector<vector<int>>(n+1);
    dp = vector<vector<int>>(n+1,vector<int>(2,0));
    int x,y;
    for(int i=0;i<n-1;i++)
    {
        cin>>x>>y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    dfs(1,-1);
    cout<<ans;
}
