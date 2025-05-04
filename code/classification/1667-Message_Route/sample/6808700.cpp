#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"
#define pb push_back
int mod=1e9+7;
 int m=998244353;
 
 
 
 
 
void solve()
{   
   int n,m;
   cin>>n>>m;
   vector<int>adj[n+1];
   vector<int>vis(n+1,0);
   for(int i=0;i<m;i++)
   {
   	int u,v;
   	cin>>u>>v;
   	adj[u].push_back(v);
   	adj[v].push_back(u);
   }    
   vector<int>par(n+1,-1);
   queue<pair<int,int>>q;
   q.push({1,0});
   vis[1]=1;
   int ans=0;
   int f=0;
   while(q.size() != 0)
   {
   	int node=q.front().first;
   	int steps=q.front().second;
   	q.pop();
   	if(node==n)
   	{
   	    f=1;
   		ans=steps;
   		break;
   	}
   	for(auto it:adj[node])
   	{
   		if(vis[it]==0)
   		{
   			vis[it]=1;
   			q.push({it,steps+1});
   			par[it]=node;
   		}
   	}
   }
   if(f==0)
   {
       cout<<"IMPOSSIBLE"<<endl;
       return;
   }
   cout<<ans+1<<endl;
   int curr=n;
   vector<int>v;
    v.push_back(curr);
   while(curr != 1)
   {
       curr=par[curr];
       v.push_back(curr);
   }
   reverse(v.begin(),v.end());
   for(int i=0;i<v.size();i++)
   {
       cout<<v[i]<<" ";
   }
   cout<<endl;
   return;
 
}
 
 
int32_t main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t=1;
  //  cin>>t;
   while(t--){
    solve();
  }
}
