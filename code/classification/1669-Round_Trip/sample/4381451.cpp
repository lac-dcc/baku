#include<bits/stdc++.h>
using namespace std;
unordered_map<int,vector<int>> adj;
vector<bool> dp;
vector<int> parent;
vector<int> ans;
 
void dfs (int i, int p)
{
    if (dp[i] || !ans.empty())
    return;
    
    dp[i]=true;
    
    for (auto& x:adj[i])
    {
        if (!ans.empty())
            return;
        if (x==parent[i])
            continue;
        parent[x]=i;
        if (dp[x])
        {
            ans.push_back(x);
            while (i!=x)
            {
                ans.push_back(i);
                i=parent[i];
            }
            ans.push_back(x);
            return;
        }
        dfs(x,i);
    }
}
   
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m,n;
    cin>>n>>m;
    dp.assign(n+1,false); 
    parent.assign(n+1,-1);
 
    for (int j=0;j<m;j++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    for (int i=1;i<=n;i++)
        dfs(i,-1);
 
    if (!ans.empty())
    {
        cout<<ans.size()<<endl;
        for (auto& x:ans)
        cout<<x<<" ";
    }
    else
    cout<<"IMPOSSIBLE\n";
}
