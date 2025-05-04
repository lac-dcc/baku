// #include <bits/stdc++.h>
// #define endl "\n"
// using namespace std;
// #define int long long int
// #define vin vector<int>
// void solve(){
// int n,m,q;
// cin>>n>>m>>q;
// vector<vector<int>> mat(n+1,vector<int>(n+1,1e15));
// for(int i=0;i<m;i++){
//   int a,b,c;
//   cin>>a>>b>>c;
//   mat[a][b]=mat[b][a]=min(mat[a][b],c);
// }
// for(int i=1;i<n+1;i++){
//   for(int j=1;j<n+1;j++){
//     if(i==j)mat[i][j]=0;
//   }
// }
// for(int i=1;i<n+1;i++){
//   for(int j=1;j<n+1;j++){
//     for(int k=1;k<n+1;k++){
//       mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
//     }
//   }
// }
// for(int i=0;i<q;i++){
//   int a,b;
//   cin>>a>>b;
//   if(mat[a][b]==1e17)cout<<-1<<endl;
//   else cout<<mat[a][b]<<endl;
// }
// }
// int32_t main(){
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL);
// solve();
// }
 
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int
  
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int n, m, q;
	cin >> n >> m >> q;
  vector<vector<int>> g;
	g.resize(n+1);
	for(int i = 0; i <= n; ++i)
	{
		g[i].resize(n+1);
	}
	for(int i = 1; i <= n; ++i)
	{
		for(int j = i+1; j <= n; ++j)
		{
			g[i][j] = g[j][i] = 1e15;
 
		}
	}
 
	for(int i = 0; i < m; ++i)
	{
		int u, v, c;
		cin >> u >> v >> c;
		g[u][v] = g[v][u] = min(g[u][v],c);
	}
 
	for(int k = 1; k <= n; ++k)
	{
		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= n; ++j)
			{
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
 
	for(int i = 0; i < q; ++i)
	{
		int u, v;
		cin >> u >> v;
		if(g[u][v] == 1e15) 
			g[u][v] = -1;
		cout << g[u][v] << endl;
	}
}
