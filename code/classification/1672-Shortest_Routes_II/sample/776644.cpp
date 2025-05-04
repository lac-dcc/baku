#include<bits/stdc++.h>
using  namespace std;
const int mod = (int)1e9+7;
const int mx = (int)(1e3);
typedef long long int lli;
const lli inf = (1e17);
#define rep(s,e) for(int i=s;i<=e;i++)
#define drep(s,e) for(int i=s;i>=e;i--)
#define reps(ch,str) for(char ch :str)
int n;
int t;
vector<pair<lli,lli>> adj[mx+7];
lli dist[mx+7][mx+7];
 
void dij(lli s){
   dist[s][s]=  0;
   pair<lli,lli> it;
   vector< pair<lli, lli> >::iterator itr;
   priority_queue<pair<lli,lli>,vector<pair<lli,lli>>,greater<pair<lli,lli>>> pq;
   pq.push({0,s});
   while(!pq.empty()){
      it = pq.top(); pq.pop();
       
        for (itr = adj[it.second].begin(); itr != adj[it.second].end(); ++itr) 
        { 
           
            lli v = (*itr).first; 
            lli weight = (*itr).second;  
            if (dist[s][v] > dist[s][it.second] + weight) 
            { 
  
                dist[s][v] = dist[s][it.second] + weight; 
                pq.push(make_pair(dist[s][v], v)); 
            } 
        } 
   }
}
 
 
int main() 
{  
  lli n,m,b,q;
 cin>>n>>m>>q;
  lli u,v,d;
   rep(1,n)for(int j=1;j<=n;j++)if(i!=j)dist[i][j]=inf;
  rep(1,m){
      cin>>u>>v>>d;
       dist[u][v] = min(dist[u][v],d);
       dist[v][u] = min(dist[v][u],d);
  }
 
   rep(1,n)for(int j=1;j<=n;j++)for(int k=1;k<=n;k++){
     if(dist[j][k] > dist[j][i] + dist[i][k])dist[j][k]=dist[j][i]+dist[i][k];
   }
    
    //  rep(1,n)dij(i);
 
     while(q--){
            cin>>u>>v;
            if(dist[u][v] == inf)cout<<-1<<"\n";
            else
            cout<<dist[u][v]<<"\n";
     }
 
}
