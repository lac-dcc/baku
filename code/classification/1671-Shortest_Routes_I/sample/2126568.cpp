#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pp pair<int,int>
struct cmp{
  bool operator()(pp a,pp b){
    return a.second>b.second;
  }
};
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<pp>> arr(n+1);
    while(m--)
    {
      int a,b,c;
      cin>>a>>b>>c;
      arr[a].push_back({b,c});
    }
    priority_queue<pp,vector<pp>,cmp> pq;
    pq.push({1,0});
    vector<int> vis(n+1,0);
    vector<int> dis(n+1,0);
 
    while(!pq.empty()){
      pp p=pq.top(); pq.pop();
      if(vis[p.first]) continue;
      dis[p.first]=p.second;
      vis[p.first]=1;
 
      for(auto it:arr[p.first]){
        if(vis[it.first]) continue;
        pq.push({it.first,it.second+p.second});
      }
    }
    for(int i=1;i<=n;i++) cout<<dis[i]<<" ";
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
 
    solve();
 
 
}
