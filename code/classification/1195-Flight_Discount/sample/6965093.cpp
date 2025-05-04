#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int mod = 1000000007;
int main(){
  int n,m;
  cin>>n>>m;
  vector<vector<pair<ll,ll>>>matrix(n+1);
  vector<pair<ll,pair<ll,ll>>>edges;
  vector<vector<pair<ll,ll>>>matrix1(n+1);
  for(int i=0;i<m;i++){
    ll u,v,c;
    cin>>u>>v>>c;
    matrix[u].push_back({v,c});
    matrix1[v].push_back({u,c});
    //cout<<" yy "<<u<<" "<<v<<endl;
    edges.push_back({u,{v,c}});
  }
  vector<ll>dis(n+1,LLONG_MAX);
  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
  pq.push({0,1});
  dis[1]=0;
  while(!pq.empty()){
    ll distance = pq.top().first;
    ll node = pq.top().second;
    pq.pop();
    if(distance>dis[node])continue;
    
   // cout<<" gg "<<node<<" "<<distance<<endl;
    for(auto it : matrix[node]){
    ll adjNode = it.first;
    ll wt = it.second;
   // cout<<" tt "<<adjNode<<" "<<wt<<endl;
    if(dis[adjNode]> wt + distance){
       dis[adjNode] = wt + distance;
      pq.push({dis[adjNode],adjNode});
    }
    }
  }
  vector<ll>dis1(n+1,LLONG_MAX);
  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq1;
  pq1.push({0,n});
  dis1[n]=0;
  while(!pq1.empty()){
    ll distance = pq1.top().first;
    ll node = pq1.top().second;
    pq1.pop();
    if(distance>dis1[node])continue;
    //cout<<" mm "<<distance<<" "<<node<<endl;
    for(auto it : matrix1[node]){
      ll adjNode = it.first;
      ll wt = it.second;
     // cout<<" ll "<<adjNode<<" "<<wt<<endl;
      if(dis1[adjNode]>wt+distance){
        dis1[adjNode] = wt + distance;
        pq1.push({dis1[adjNode],adjNode});
      }
    }
  }
  ll ans = LLONG_MAX;
  for(auto it : edges){
    ll u = it.first;
    ll v = it.second.first;
    ll wt = it.second.second;
   // cout<<" yy "<<u<<" "<<v<<" "<<wt<<" "<<dis[u]<<" "<<dis1[v]<<" "<<ans<<endl;
    if(dis[u]!=LLONG_MAX && dis1[v]!=LLONG_MAX){
    //  cout<<" kk "<<u<<" "<<v<<" "<<wt<<" "<<dis[u]<<" "<<dis1[v]<<" "<<ans<<endl;
     ans = min(ans,dis[u] + dis1[v] + (wt/2));
    }
  }
  cout<<ans<<endl;
 
}
