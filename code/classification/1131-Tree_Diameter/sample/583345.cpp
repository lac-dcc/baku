#include <bits/stdc++.h>
using namespace std;
 
vector<vector<int>> neighbors;
int answer = 0, far = -1;
 
void dfs(int i, int parent, int cost)
{
	for(auto& neighbor : neighbors[i])
		if(neighbor != parent)
			dfs(neighbor, i, cost + 1);
	if(cost > answer)
	{
		answer = cost;
		far = i;
	}
}
 
int main()
{
	int n; cin >> n;
	neighbors.resize(n);
	for(int i = 0; i < n - 1; ++i)
	{
		int a, b; cin >> a >> b;
		--a; --b;
		neighbors[a].push_back(b);
		neighbors[b].push_back(a);
	}
	dfs(0, 0, 0);
	dfs(far, far, 0);
	cout << answer << '\n';
}
