#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
 
ll mod = 1e9 + 7;
int ans = 0;
 
int f(int v, vector<int> &h, vector<bool> &vis, vector<int> *adj) {
	vis[v] = true;
	int x = 0;
	for(auto j : adj[v]) {
		if(!vis[j])
			x = max(x, f(j, h, vis, adj));
	}
 
	h[v] = x;
	return (h[v] + 1);
}
 
void res(int v, vector<int> &h, vector<bool> &vis, vector<int> *adj) {
	vis[v] = true;
	multiset<int> st;
	for(auto j : adj[v]) {
		if(!vis[j]) {
			st.insert(h[j]);
			if(st.size() == 3)
				st.erase(st.begin());
		}
	}
 
	if(st.size() == 2) {
		ans = max(ans, 2 + (*st.begin()) + *(--st.end()));
	}
 
	for(auto j : adj[v]) {
		if(!vis[j]) {
			res(j, h, vis, adj);
		}
	}
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	int n;
	cin >> n;
 
	vector<int> adj[n + 1];
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
 
	if(n == 2) {
		cout << "1";
		return 0;
	}
 
	vector<bool> vis(n + 1, false);
	vector<int> h(n + 1);
	f(1, h, vis, adj);
	for(int i = 1; i <= n; i++) {
		vis[i] = false;
	}
	res(1, h, vis, adj);
 
	if(n > 1) {
		for(int i = 1; i <= n; i++) {
			vis[i] = false;
		}
		f(2, h, vis, adj);
		for(int i = 1; i <= n; i++) {
			vis[i] = false;
		}
		res(2, h, vis, adj);
	}
	
 
	cout << ans;
}	
