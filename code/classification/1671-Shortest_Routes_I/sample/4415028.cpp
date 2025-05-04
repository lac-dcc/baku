#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int,int>;
using pl = pair<ll,ll>;
 
#define pb push_back
#define mp make_pair
 
int n, m;
vector<vector<pl>> adj;
vector<bool> vis;
 
 
int main(){
	cin >> n >> m;
	adj.resize(n+1);
	vll ans(n+1);
	for(int i = 0; i < m; ++i){
		int a, b, c; cin >> a >> b >> c;
		adj[a].pb(mp(b, c));
	}
 
	priority_queue<pl> q;
	q.push(mp(0, 1)); // dist, val
	while(q.size()){
		pl p = q.top();
		ll dist = p.first, val = p.second;
		q.pop();
		if(val > 1 && ans[val]) continue;
		else if(val > 1 && !ans[val]) {
			ans[val] = -dist;
			// printf("%lld %lld\n", val, dist);
		}
		for(auto& pp : adj[val]) if(pp.first > 1 && !ans[pp.first]) q.push(mp(dist - pp.second, pp.first));
	}
	for(int i = 1; i <= n; ++i){
		cout << ans[i] << " \n"[i==n];
	}
}
 
