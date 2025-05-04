#include <bits/stdc++.h>
using namespace std;
#define int long long int
 
struct trips{
	int a, b, w;
};
 
int x;
vector<trips> edges;
vector<int> dist;
vector<int> relaxant;
 
 
int32_t main(){
 
	int n,m;cin>>n>>m;
	dist.resize(n+1);
	relaxant.assign(n+1,-1);
	for(int i= 0; i < m;++i){
		int a, b, w;
		cin >>a>>b>>w;
		edges.push_back({a,b,w});
	}
 
	//bellman-ford
	for(int i = 1; i <= n; ++i)
	{
		x= -1;
		for(auto e: edges)
		{
 
			int u = e.a;
			int v = e.b;
			int d = e.w;
			if(dist[u]+d < dist[v])
			{
				dist[v] = d+dist[u];
				relaxant[v] = u;
				x = v;
			}
		}
	}
 
	if(x == -1)
		cout << "NO" << endl;
 
	else
	{
		for(int i = 1; i <= n; ++i)
		{
			x = relaxant[x];
		}
 
		vector<int> cycle;
 
		for(int v = x; ; v = relaxant[v])
		{
			cycle.push_back(v);
			if(v == x and cycle.size() > 1)
				break;
		}
 
		reverse(cycle.begin(), cycle.end());
 
		cout << "YES" << endl;
		for(auto v: cycle)
		{
			cout << v << " ";
		}
 
		cout << endl;
	}
}
