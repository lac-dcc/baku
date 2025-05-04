#include <bits/stdc++.h>
using namespace std;
 
//vector<vector<int>>dp;
 
static bool cmp(vector<long long>&a,vector<long long>&b)
{
    if(a[1]==b[1])
    {
        if(a[0]==b[0])
            return a[2]>b[2];
        return a[0]<b[0];
    }
    return a[1]<b[1];
}
 
bool solve(vector<vector<int>>&g,int v,vector<int>&vis,int col)
{
    vis[v] = col;
 
    for(int t : g[v])
    {
        if(vis[t]==-1)
        {
            if(!solve(g,t,vis,!col))
                return false;
        }
 
        else if(vis[t]==vis[v])
            return false;
    }
 
    return true;
}
void solve()
{
    int n,m;
    cin>>n>>m;
 
    vector<vector<int>>g(n+1);
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
 
        g[x].push_back(y);
        g[y].push_back(x);
    }
 
    vector<int>vis(n+1,-1);
    bool flag = false;
 
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==-1)
        {
            vis[i] = 1;
            if(!solve(g,i,vis,1))
            {
                flag = true;
                break;
            }
        }
    }
 
    if(flag)
        cout<<"IMPOSSIBLE";
 
    else{
        for(int i=1;i<=n;i++)
        {
            if(vis[i])
                cout<<1<<" ";
            else cout<<2<<" ";
        }
    }
}
int main()
{
  solve();
}
