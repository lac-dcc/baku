#include<bits/stdc++.h>
using namespace std;
#define INF 10000000000000000
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
   int n,m;
   cin>>n>>m;
   vector<pair<pair<int,int>,int>> adj;
 
 
   int cycle_start=-1,cycle_end=-1;
   int par[n+1];
   par[1]=-1;
   
   while(m--)
     {
      int a,b,x;
      cin>>a>>b>>x;
      adj.push_back({{a,b},x});
      
     }
 
 
     
     long long dist[n+1];
     for(int i=1;i<=n;i++)
      dist[i]=INF;
    dist[1]=0;
    bool nehu=false;
    for(int i=1;i<=n;i++)
    {
      nehu=false;
 
      cycle_end=-1;
    for(int j=0;j<adj.size();j++)
    {
      long long  u=adj[j].first.first;
      long long v=adj[j].first.second;
      long long w=adj[j].second;
 
      if(dist[v]>dist[u]+w)
      {
        dist[v]=dist[u]+w;
        par[v]=u;
    
          cycle_start=v;
          cycle_end=v;
        
      }
       
        
          
        
        
      
    }
 
    }
    if(cycle_end!=-1)
      {
 
 
         cout<<"YES"<<endl;
         vector<int> res;
 
         for(int i=1;i<=n;i++)
             cycle_end=par[cycle_end];
 
 
           for(int i=cycle_end;;i=par[i])
           {
              res.push_back(i);
              if(i==cycle_end&&res.size()>1)
                break;
           }
           reverse(res.begin(),res.end());
           for(int i=0;i<res.size();i++)
           {
 
            cout<<res[i]<<" ";
           }
 
 
      }
    else
      cout<<"NO"<<endl;
   
 
  return 0;
  
 
 
}
