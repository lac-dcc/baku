#include<bits/stdc++.h>
using namespace std;
#define int long long
 
bool dfs(int node,int parent,vector<int> adj[],vector<int> & vis,vector<int> & ans,vector<int> & par)
{
      vis[node] = 1;
      for(auto it : adj[node])
      {
           if(vis[it]==0)
           {
                  vis[it] = 1;
                  par[it] = node;
                  bool check = dfs(it,node,adj,vis,ans,par);
                  if(check==true)
                  {
                        return true;
                  }
           }
           else if(it!=parent)
           {
                  ans.push_back(it);
                  int child = node;
                  while(child!=it)
                  {
                        ans.push_back(child);
                        child = par[child];
                  }
                  ans.push_back(child);
                  return true;
           }
      }
      
      return false;
}
 
int32_t main()
{
 
      #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
      #endif
      
      int n,m;cin>>n>>m;
      vector<int> adj[n+1];
      for (int i = 0; i < m; ++i)
      {
      	int u,v;cin>>u>>v;
      	adj[u].push_back(v);
      	adj[v].push_back(u);
      }
      vector<int> vis(n+1,0);
      vector<int> ans;
      vector<int> par(n+1);
      int flag = 0;
      for (int i = 1; i <=n; ++i)
      {
            if(vis[i]==0)
            {
                  vis[i] = 1;
                  par[i] = -1;
                  bool check =  dfs(i,-1,adj,vis,ans,par);
                  if(check==true)
                  {
                        flag = 1;break;
                  }
            }     
 
      }
 
      if (flag == 0)
      {
            cout<<"IMPOSSIBLE"<<endl;
      }
      else
      {
            cout<<ans.size()<<endl;
            for (int i = 0; i <ans.size(); ++i)
            {
                  cout<<ans[i]<<" ";
            }cout<<endl;
      }
      
      
    
	
            
            
      
      return 0;
}
