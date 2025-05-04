#include <bits/stdc++.h>
using namespace std;
#define int long long int
bool isvalid(int i, int j, int n, int m, vector<vector<bool>> &vis)
{
  if (i < 0 || i >= n || j < 0 || j >= m || vis[i][j])
    return 0;
  return 1;
}
void solve()
{
  int n, m,q;
  cin >> n >> m>>q;
  vector<vector<int>>adj(n+1,vector<int>(n+1,1e12));
  while (m--)
  {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a][b]=min(adj[a][b],c),adj[b][a]=min(adj[b][a],c);
  }
  for(int i=1;i<=n;i++) adj[i][i]=0;
  for(int via=1;via<=n;via++){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        if(i==via || j==via) continue;
        adj[i][j]=min(adj[i][j],adj[i][via]+adj[via][j]);
      }
    }
  }
  while(q--){
    int a,b;
    cin>>a>>b;
    if(adj[a][b]>=1e12) cout<<-1<<endl;
    else cout<<adj[a][b]<<endl;
  }
}
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
