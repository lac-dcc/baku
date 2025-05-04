#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define watch2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << "\n"
 
int n, m, rooms;
vector<vector<bool>> vis;
 
vector<pair<int,int>> moves = {{-1,0}, {1,0}, {0,-1}, {0,1}};
bool isValid(int x, int y)
{
	if(x<0 or x >= n or y <0 or y>=m)
		return false;
	if(vis[x][y])
		return false;
	return true;
}
 
void dfs(int i, int j)
{
	vis[i][j] = true;
	for(int k=0;k<4;k++ )
	{
		if(isValid(i+moves[k].first, j+moves[k].second))
		{
			dfs(i+moves[k].first, j+moves[k].second);
		}
	}
}
void connected_components()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if(!vis[i][j])
			{
				dfs(i,j);
				++rooms;
			}
		}
	}
}
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	vis.resize(n);
 
	for(int i = 0; i < n; ++i)
	{
		vis[i].resize(m);
	}
 
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			char c; cin >> c;
			if(c == '#')
			{
				vis[i][j] = true;
			}
		}
	}
	connected_components();
	cout << rooms << endl;
}
