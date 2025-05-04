#include <bits/stdc++.h>
using namespace std;
const int mxn=1e6+7;
int val[mxn],n,m,u,v;
bool used[mxn];
vector<int>g[mxn];
bool check;
void dfs(int u)
{
    used[u]=true;
    for(auto v:g[u])
    {
        if(!used[v])
        {
            val[v]=val[u]^1;
            dfs(v);
        }
        else
        {
            if(val[v]==val[u])
                check=true;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        if(!used[i])
        {
            dfs(i);
            if(check)
            {
                cout<<"IMPOSSIBLE";
                return 0;
            }
        }
    }
    for(int i=1;i<=n;i++)
        cout<<val[i]+1<<" ";
    return 0;
}
