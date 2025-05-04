#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef long double ld;
#define vll vector <ll>
#define vld vector <ld>
#define pb push_back
#define umap unordered_map
#define uset unordered_set
#define prq priority_queue
#define pll pair<ll,ll>
 
ll mod = 1e9 + 7;
ll inf = 1e18;
ll neginf = -1e18;
ll add(ll a, ll b) {return (a%mod + b%mod) % mod;}
ll mul(ll a, ll b) {return (a%mod * b%mod) % mod;}
ll sub(ll a, ll b) {return (a%mod - b%mod + mod) % mod;}
 
struct st {
	ll price;
	ll node;
	ll coup;
};
 
struct compare {
	bool operator()(st a1, st a2) {
		return a1.price > a2.price;
	}
};
 
void solve() {
 
	ll n, m, x, y, z;
	cin >> n >> m;
 
	map <pll, ll> mp;
	vector <vector <pll>> adj(n+1);
	for(ll i=0; i<m; i++) {
		cin >> x >> y >> z;
		if(mp.find({x, y}) == mp.end() || mp[{x, y}] > z) mp[{x, y}] = z;
	}
	for(auto e: mp) adj[e.first.first].pb({e.first.second, e.second});
 
	vector <vll> cost(n+1, vll(2, inf)), v(n+1, vll(2, 0));
	prq <st, vector <st>, compare> pq;
	
	cost[1][0] = 0;
	cost[1][1] = 0;
	pq.push({0, 1, 1});
 
	while(!pq.empty()) {
		ll price = pq.top().price;
		ll node = pq.top().node;
		ll coup = pq.top().coup;
		pq.pop();
 
		if(v[node][coup]) continue;
		v[node][coup] = 1;
 
		for(auto e: adj[node]) {
			ll ch = e.first;
			ll p = e.second;
 
			if(!v[ch][coup]) {
				if(!coup) {
					if(cost[ch][0] > price + p) {
						cost[ch][0] = price + p;
						pq.push({cost[ch][0], ch, 0});
					}
				}
				if(coup) {
					if(cost[ch][0] > price + p/2) {
						cost[ch][0] = price + p/2;
						pq.push({cost[ch][0], ch, 0});
					}
					if(cost[ch][1] > price + p) {
						cost[ch][1] = price + p;
						pq.push({cost[ch][1], ch, 1});	
					}
				}
			}
		}
	}
 
	cout << min(cost[n][0], cost[n][1]);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	ll t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
} 
