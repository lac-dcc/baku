#include<bits/stdc++.h>
#define endl "\n"
#define ll long long 
#define N 1e9+7
#define M 1e5+8
#define pii pair<ll,ll> 
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
/*------------------------------ PRAJWAL TS  ----------------------------*/ 
 
int main()
{
  ll n,m;
  cin>>n>>m;
 
  vector<pii> adj[n];
 
  while(m--)
  {
     ll a,b,c;
     cin>>a>>b>>c;
     a--,b--;
     adj[a].push_back({b,c});
  }
  vector<bool> pro(n,false);
  vector<ll> dis(n,1e18+2);
 
  priority_queue<pii,vector<pii>,greater<pii>> pq;
  int curr=0;
  dis[0]=0;
 
  while(curr!=-1)
  {
     pro[curr]=true;
 
     for(auto u:adj[curr])
     {
       ll x,y;
       x=u.first,y=u.second;
 
       if(pro[x] or dis[x]<dis[curr]+y)
        continue;
 
      dis[x]=dis[curr]+y;
      pq.push({dis[x],x});
     }
 
     while(!pq.empty() and pro[curr])
     {
       auto u=pq.top();
        curr=u.second;
        pq.pop();
     }
     if(pro[curr])
      curr=-1;
 
  }
 
  for(auto u:dis)
     cout<<u<<" ";
  return 0;
 
}
