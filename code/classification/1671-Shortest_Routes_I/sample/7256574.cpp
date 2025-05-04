// USACO Testing.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//
 
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <cassert>
#include <iostream>
#include <set>
#include <string>
#include <tuple>
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define pli pair<long long, int>
const ll INF = numeric_limits<ll>::max() / 2;
vector<ll> dijkstra(vector<vector<pair<int, ll>>>& adj, int start) {
	int n = adj.size();
 
	vector<ll> dist(n, INF);
	priority_queue<pli, vector<pli>, greater<pli>> q;
 
	q.push({ 0, start });
 
	while (q.size()) {
		ll d;
		int v;
		tie(d, v) = q.top();
		q.pop();
 
		if (dist[v] <= d) continue;
		dist[v] = d;
		for (auto p : adj[v]) {
			q.push({ d + p.second, p.first });
		}
	}
 
	return dist;
}
 
int main()
{
	int n = 0, m = 0;
	cin >> n >> m;
 
	// index || cost
	vector<vector<pair<int, long long>>> adj(n);
	for (int i = 0; i < m; i++) {
		int a, b, c;
 
		cin >> a >> b >> c;
		a--; b--;
 
		adj[a].push_back({ b, c });
	}
 
		auto result = dijkstra(adj, 0);
 
	for (int i = 0; i < n; i++) {
		cout << result[i] << " ";
	}
}
 
/*
 
	int n = 0, m = 0;
	cin >> n >> m;
 
	vector<ll> filler(n,INT_MAX / 2);
	vector<vector<ll>> adj(n,filler);
 
	for (int i = 0; i < m;i++) {
		int a, b,c;
 
		cin >> a >> b >> c;
		a--; b--;
 
		adj[a][b] = c;
	}
 
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}
 
	cout << 0 << " ";
	for (int i = 1; i < n; i++) {
		cout << adj[0][i] << " ";
	}
*/
