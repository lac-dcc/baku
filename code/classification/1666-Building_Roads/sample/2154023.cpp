#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> a;
vector<bool> vis;
void dfs(int i)
{
    vis[i]=1;
    for(int j=0;j<a[i].size();j++)
    {
        if(!vis[a[i][j]]) dfs(a[i][j]);
    }
}
int main()
{
    int v,e;cin>>v>>e;
    a.resize(v+1);
    vis.resize(v+1,0);
    while(e--)
    {
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    vector<int> ans;
    for(int i=1;i<=v;i++)
    {
        if(!vis[i])
        {
            ans.push_back(i);
            dfs(i);
        }
    }
    cout<<ans.size()-1<<endl;
    for(int i=1;i<ans.size();i++) cout<<ans[i-1]<<" "<<ans[i]<<endl;
}
