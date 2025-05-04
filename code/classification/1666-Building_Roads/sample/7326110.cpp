#include<bits/stdc++.h>
using namespace std;
void BFS(int start,vector<bool>& visited,vector<pair<int,int>>& p, vector<vector<int>>& adj,set<int>& unvisited){
  queue<int> v;
  v.push(start);
  int x;
  while(!v.empty()){
    x = v.front();
    v.pop();
    unvisited.erase(x);
    visited[x]=true;
    for(int n:adj[x]){
      if(visited[n]==false ){
        v.push(n);
        visited[n]=true;               
      }
    }
  }
  if(!unvisited.empty()){p.push_back(make_pair(x,*unvisited.begin()));}
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<bool> visited(100001,false);
  vector<pair<int,int>> p;
  set<int> prev; 
  int n,m,a,b,c=0;//new minus current
  cin >> n >> m;
  vector<vector<int>> adj(200001);
  for(int k=0;k<m;k++){
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for(int k =1;k<=n;k++){
    prev.insert(k);
  }
  while(!prev.empty()){
    BFS(*prev.begin(),visited,p,adj,prev);
  }
 
 
 
  
  cout << p.size() << '\n';
  for(auto x:p){cout << x.first << ' ' << x.second << '\n';}
  
  
  return 0;
}
