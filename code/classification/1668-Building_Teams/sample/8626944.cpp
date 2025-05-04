#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <deque>
 
 
bool bfs(const std::vector<std::vector<int>>& g, std::vector<int>& visited, int t)
{
	int n = g.size();
	//std::vector<int> visited(n, 0);
	std::queue<int> q;
	visited[t] = 1;
	q.push(t);
	int count = 1;
	while (!q.empty())
	{
		auto v = q.front();
		q.pop();
		for (int u : g[v])
		{
			if (!visited[u])
			{
				q.push(u);
				visited[u] = 3 - visited[v];
			}
			else if (visited[v] == visited[u])
				return false;
		}
		//count = (count + 1) % 2;
	}
	return true;
}
 
int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> g(n);
 
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		std::cin >> u >> v;
		--u;
		--v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
 
	std::vector<int> visited(n, 0);
	for (int i = 0; i < n; ++i)
	{
		if (visited[i] == 0)
		{
			if (!bfs(g, visited, i))
			{
				std::cout << "IMPOSSIBLE" << std::endl;
				return 0;
			}
		}
	}
 
	for (const auto x : visited)
	{
		std::cout << x << " ";
	}
	std::cout << std::endl;
	return 0;
}