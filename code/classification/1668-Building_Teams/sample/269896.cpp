#include <iostream>
#include <vector>
using namespace std;
 
const int NCONS = 100001;
vector<int> adj[NCONS];
bool visited[NCONS];
int color[NCONS];
int n, m;
 
void dfs(int cur, bool c)
{
	visited[cur] = true;
	color[cur] = c ? 1 : 2;
	
	for(auto nxt : adj[cur])
	{
		if(visited[nxt])
		{
			if(color[nxt] != c) continue;
			else
			{
				cout << "IMPOSSIBLE" << endl; exit(0);
			}
		}
		dfs(nxt, !c);
	}
}
int main()
{
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n >> m;
	while(m--)
	{
		int a, b; cin >> a >> b; adj[a].push_back(b); adj[b].push_back(a);
	}
	for(int i = 1; i <= n; i++)
	{
		if(visited[i]) continue;
		dfs(i, true);
	}
	for(int i = 1; i <= n; i++)
	{
		cout << color[i] << " ";
	}
}
