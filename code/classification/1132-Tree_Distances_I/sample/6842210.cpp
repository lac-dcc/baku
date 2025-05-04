#include<bits/stdc++.h>
using namespace std;
#define int long long
int siz=2e6+1;
vector<vector<int>> adj;
int maxnode=-1,maxi=0;
vector<int>ans;
void bfs(int root,int n)
{
 
    unordered_map<int,bool> vis;
    vector<int> dist(n+1,0);
    queue<int>q;
    q.push(root);
    vis[root]=1;
    while(q.size())
    {
        auto node = q.front();
        q.pop();
 
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                vis[it]=1;
                dist[it] = dist[node]+1;
                if(maxi<dist[it])
                {
                    maxi = dist[it];
                    maxnode = it;
                }
                q.push(it);
                ans[it] = max(dist[it],ans[it]);
            }
        }
    }
}
signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif  
 
    vector<int> dp(siz,0);
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    adj.resize(n+1);
    ans.resize(n+1);
    //vector<int>par(n+1,-1);
    for(int i=1;i<=n-1;i++)
    {
        int  a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    bfs(1,n);
    maxi=0;
    bfs(maxnode,n);
    bfs(maxnode,n);
 
    for(int i=1;i<=n;i++)
    cout<<ans[i]<<" ";
  
    
}
