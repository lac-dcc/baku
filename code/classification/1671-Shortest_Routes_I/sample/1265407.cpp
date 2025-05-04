#include<bits/stdc++.h>
using namespace std;
 
#define fi              first
#define se              second
#define ll              long long int
#define pb              push_back
#define mp              make_pair
#define pai             pair<ll,ll>
#define vi              vector<ll>
#define mpi             map<ll,ll>
#define minH            priority_queue<pai,vector<pai>,greater<pai>>
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000000
#define inp(tc)         int tc; cin>>tc; while(tc--)
#define fast_io         ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define INF 			1000000000
 
ll n, m;
vector<pair<ll, ll>> adj[100001];
 
int main() {
#ifndef ONLINE_JUDGE
	//for reading input from input.txt
	freopen("input2.txt", "r", stdin);
	//for writing output to output.txt
	freopen("output2.txt", "w", stdout);
#endif
 
	fast_io;
	//inp(tc) {
	cin >> n >> m;
	for (ll i = 1; i <= m; i++) {
		ll a, b, w;
		cin >> a >> b >> w;
		adj[a].pb({b, w});
	}
	//int INF = 1000000000;
	minH pq;
	vi dist(n + 1, INF * m);
	pq.push({0, 1});
	dist[1] = 0;
	while (!pq.empty()) {
		ll cur_el = pq.top().second;
		ll cur_d = pq.top().first;
		pq.pop();
 
		if (cur_d != dist[cur_el]) continue;
 
		for (auto edge : adj[cur_el]) {
			if (dist[cur_el] + edge.second < dist[edge.first]) {
				dist[edge.first] = dist[cur_el] + edge.second;
				pq.push({dist[edge.first], edge.first});
			}
		}
	}
	for (ll i = 1; i <= n; i++) {
		cout << dist[i] << " ";
	}
//	}
}
