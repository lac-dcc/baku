#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
bool visited[(int)1e5 + 1];
 
void dfs( vector<int> graph[] , int src)
{	visited[src] = true;
	for(auto x : graph[src])
	{
		if(visited[x] == false)
		{
			dfs(graph, x);
		}
	}
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	 cin.tie(NULL);
 
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
 
int n , m;
cin >> n >> m;
 
vector<int> graph[n+1];
int a , b ;
vector<int> roads;
for(int i = 0 ; i < m ; i++)
{
	cin >> a >> b;
	graph[a].push_back(b);
	graph[b].push_back(a);
}
 
// for (int i = 1; i <=n; i++)
// {	
// 	for(auto city : graph[i])
// 	{
// 		cout << i << city << " ";
// 	}
 
// 	cout << endl;
// 	/* code */
// }
 
 
// DFS on each unvisited city
	int count = 0;
 
	for(int i = 1 ; i <= n ; i++)
	{	
		if(visited[i] == false)
	{		count++ ;
			roads.push_back(i);
			dfs(graph, i);
 
	}
 
	}
 
	cout << count-1 <<"\n";
	for( int i = 1 ; i < count ; i++)
	{
		cout << roads[i-1] << " "<< roads[i] <<endl;
	}
	
	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}


