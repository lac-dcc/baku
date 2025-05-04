#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long long int lli;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef unsigned long long int ulli;
 
void fast_io(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}
 
int main(){
 
	fast_io();
	//code starts here
	
	int n, m;
	cin >> n >> m;
	
	vector<pair<int, ll> > G[n+5];
	for(int e = 0; e < m; e++){
		int u, v;
		ll c;
		cin >> u >> v >> c;
		G[u].push_back({v, c});
	}
	
	priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > pq;
	vector<ll> dist(n+5, 1e16);
	vector<bool> visited(n+5, false);
	
	pq.push({0, 1});
	dist[1] = 0;
	
	while(!pq.empty()){
		
		int node = pq.top().second;
		pq.pop();
		if(visited[node])continue;
		visited[node] = true;
		
		vector<pair<int, ll> >::iterator it;
		for(it = G[node].begin(); it != G[node].end(); it++){
			if(dist[it->first] > dist[node] + it->second){
				dist[it->first] = dist[node] + it->second;
				pq.push({dist[it->first], it->first});
			}
		}
		
	}
	
	for(int i = 1; i <= n; i++){
		cout << dist[i] << " "; 
	}
	cout << endl;
 
	return 0;
 
}
 
 
