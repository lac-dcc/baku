#include <bits/stdc++.h>
using namespace std;
#define sc second
#define fr first
#define ll long long
 
const int maxn = 2e5 + 10;
int cnt[maxn] = {};
vector<int> adj[maxn] = {};
 
void dfs(int s) {
	cnt[s] = 1;
	for (auto u : adj[s]) {
		dfs(u);
		cnt[s] += cnt[u];
	}
}
 
int main() {
 
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout); 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	int n; cin >> n;
	for (int i = 2; i <= n; i++) {
		int a; cin >> a;
		adj[a].push_back(i);
	}
 
	dfs(1);
	for (int i = 1; i <= n; i++) cout << cnt[i] - 1 << " ";
}
 
 
 
 
 
 
 
 
 
