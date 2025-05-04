#include<bits/stdc++.h>
using namespace std;
bool solve(vector<int>&ans,vector<vector<int>>&adj,vector<int>&visited,int v,int p)
{
        if(visited[v] ==1)
        {
            int i=0;
            while(i<ans.size() && ans[i] != v) i++;
            int x = ans .size()-i + 1,j=i;
            cout<<x<<endl;
            for(i;i<ans.size();i++)
            {
                cout<<ans[i]<<" ";
            }
            cout<<ans[j]<<" ";
            return 1;
        }
        visited[v] =1;
        ans.push_back(v);
        int x =0;
        for(int i=0;i<adj[v].size();i++)
        {
            if(adj[v][i] != p)
            {
                x = (x || solve(ans,adj,visited,adj[v][i],v));
            }
        }
        ans.pop_back();
        return x;
    }
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int>visited(n+1,-1);
    for(int i=1;i<=n;i++)
    {
    vector<int> ans;
    if(visited[i] ==1) continue;
    bool b = solve(ans,adj,visited,i,-1);
    if(b==1) return 0;
    }
    
    cout<<"IMPOSSIBLE";
     
    return 0;
}
