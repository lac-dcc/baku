#include <bits/stdc++.h>
using namespace std;
#define cc  \
  int t;    \
  cin >> t; \
  while (t--)
#define print                 \
  for (int i = 0; i < n; i++) \
  {                           \
    cout << arr[i] << ' ';    \
  }
#define int long long
#define loop for (int i = 0; i < n; i++)
vector<int>answer;
 bool dfs(vector<int>adj[],vector<int>&visited,vector<int>&pathvisited,int node,int cycle_node,int parent){
        visited[node]=1;
        pathvisited[node]=1;
        for(auto val:adj[node]){
            if(visited[val]==0){
             if(  dfs(adj,visited,pathvisited,val,cycle_node,node)==true){
                 answer.push_back(val);
                 return true;
             }
            }
            else if(visited[val]&&pathvisited[val]&&val==cycle_node&&parent!=val){
            answer.push_back(val);
                return true;
            }
        }
        pathvisited[node]=0;
        return false;
    }
signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<int> adj[n + 1];
  for (int i = 0; i < m; i++)
  {
    int x1, x2;
    cin >> x1 >> x2;
    adj[x1].push_back(x2);
    adj[x2].push_back(x1);
  }
  int cycle_node = -1;
  queue<pair<int, int>> q;
  vector<int> visited(n + 1, 0);
  for(int i=1;i<=n;i++){
    if(visited[i]==false){
  q.push({i, -1});
  visited[i] = 1;
  while (q.size() > 0)
  {
    int node = q.front().first;
    int parent = q.front().second;
    q.pop();
    for (auto val : adj[node])
    {
      if (visited[val] == 1 && val != parent)
      {
        cycle_node = val;
        break;
      }
      else if (visited[val] == 0)
      {
        visited[val] = 1;
        q.push({val, node});
      }
    }
  }
  }
  if(cycle_node!=-1){
    break;
  }
  }
  if (cycle_node == -1)
  {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  for (int i = 1; i <= n; i++)
  {
    visited[i] = 0;
  }
  vector<int>pathvisited(n+1,0);
  bool f = dfs(adj,visited,pathvisited,cycle_node,cycle_node,0);
answer.push_back(cycle_node);
cout<<answer.size()<<endl;
for(auto val:answer){
  cout<<val<<" ";
}
cout<<endl;
  return 0;
}
