// Problem: Flight Discount
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1195
// Memory Limit: 512 MB
// Time Limit: 1000 ms
 
#include <iostream>
#include <fstream>
#include <random>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <functional>
#include <typeinfo>
 
#include <vector>
#include <array>
#include <valarray>
#include <queue>
#include <stack>
#include <set>
#include <map>
 
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>
#include <cmath>
#include <climits>
using namespace std;
 
#define int long long int
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define all(x) (x).begin(),(x).end()
#define ln cout<<'\n'
#define X first
#define Y second
 
template<typename T>
void print(T a)
{
    for(int i=0; i<a.size(); ++i)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}
const int INF = 1e17;
 
vector<int> disktra(int root, vector<vector<pair<int, int > > > &g){
	int n = g.size();
	vector<int> dist(n+1, INF);
	priority_queue<pair<int, int> > Q;
	Q.push({0, root});
	dist[root] = 0;
	while (Q.size() > 0) {
		auto [w, v] = Q.top();Q.pop();
		if (dist[v] < -w) continue;
		for(pair<int, int> x: g[v]) {
			auto [u, c] = x;
			if (dist[u] > -w + c) {			
				dist[u] = min(dist[u], -w + c);
				Q.push({-dist[u], u});
			}
		}
	}
	return dist;
	
}
 
 
void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int> > > g(n+1), g1(n+1);
	for(int i=0; i<m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		g[a].push_back({b, c});
		g1[b].push_back({a, c});
	}
	vector<int> dist1 = disktra(1, g);
	vector<int> distn = disktra(n, g1);
	
	int res = dist1[n];
	
	for(int v=1; v<=n; v++) {
		for(pair<int, int> x: g[v]) {
			auto [u, c] = x;
			
			res = min(res, dist1[v] + distn[u] + c / 2);
		}
	}
	cout << res;
}
 
 
signed main()
{
    fast;
    int t=1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
