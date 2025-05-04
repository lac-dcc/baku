#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define F first
#define S second
#define PB push_back
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define v(a, n) vector <ll> a(n + 1, 0)
#define oset tree <ll, null_type, greater<ll>, rb_tree_tag, tree_order_statistics_node_update>
using namespace __gnu_pbds;
using namespace std;
const ll INF = 1e8;
const ll MOD = 1e9 + 7;
const ll N = 1e5;
vector <int> adj[N + 1];
int used[N + 1];
 
void dfs(int start){
	used[start] = true;
	for (int i1 = 0; i1 < adj[start].size(); i1++){
		if (!used[adj[start][i1]]){
			dfs(adj[start][i1]);
		}
	}
	return;
}
 
int main(){
	int n, m;
	int t1, t2;
	cin >> n >> m;
	fill (used, used + N + 1, 0);
 
	for (int i1 = 1; i1 <= m; i1++){
		cin >> t1 >> t2;
		adj[t1].push_back(t2);
		adj[t2].push_back(t1);
	}
	int count = 1;
	int prev = 1;
 
	if (!used[1]) {
		dfs(1);
	}
 
	vector <pair<int, int>> ans;
	for (int i1 = 1; i1 <= n; i1++){
		if (!used[i1]) {
			ans.push_back({prev, i1});
			prev = i1;
			dfs(i1);
		}
	}
	cout << ans.size() << endl;
	for (int i1 = 0; i1 < ans.size(); i1++){
		cout << ans[i1].first << " " << ans[i1].second << endl;
	}
}
