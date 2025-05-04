#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
vector<bool> visited(200000);
vector<vector<ll>> a(200000);
vector<ll> ans(200000);
ll n;
int dfs(int v) {
	visited[v] = true;
	for(int i = 0; i < a[v].size(); i++) {
		ans[v] += 1;
		ans[v] += dfs(a[v][i]);
	}
	return ans[v];
}
int main() {
	cin >> n;
	for(ll i = 1; i < n; i++) {
		ll p;
		cin >> p;
		a[p-1].push_back(i);
	}
	for(int i = 0; i < n; i++) {
		if(!visited[i]) {
			dfs(i);
		}
	}
	for(int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
}
