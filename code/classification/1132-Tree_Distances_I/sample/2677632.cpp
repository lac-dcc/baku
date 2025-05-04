#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
#define rall(A) A.rbegin(),A.rend()
#define pb push_back 
#define dbg(x) do {cerr << #x <<" = " << (x) << endl; } while (false)
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
//cout << setprecision(12) << fixed;
 
const int maxn = 2e5+5;
 
int n;
vi adj[maxn];
ii dp[maxn];
int ans[maxn];
 
void calc(int v, int p) {
	for(auto to : adj[v]) {
		if(to == p) continue;
		calc(to, v);
	}
 
	dp[v] = {0, 0};
	for(auto to : adj[v]) {
		if(to == p) continue;
 
		vi tmp;
 
		tmp.pb(dp[v].first);
		tmp.pb(dp[v].second);
		tmp.pb(dp[to].first+1);
 
		sort(all(tmp));
 
		dp[v] = {tmp[2], tmp[1]};
	}
}
 
void reroot(int v, int p) {
	ans[v] = dp[v].first;
	ii DPv = dp[v];
 
	int deg = adj[v].size();
 
	for(auto to : adj[v]) {
		if(to == p) continue;
 
		ii DPto = dp[to];
		if(deg == 1) {
			vi tmp;
 
			tmp.pb(dp[to].first);
			tmp.pb(dp[to].second);
			tmp.pb(1);
 
			sort(all(tmp));
			dp[to] = {tmp[2], tmp[1]};
		}
		else {
			if(dp[to].first+1 == dp[v].first) {
				vi tmp;
 
				tmp.pb(dp[to].first);
				tmp.pb(dp[to].second);
				tmp.pb(dp[v].second+1);
 
				sort(all(tmp));
				dp[to] = {tmp[2], tmp[1]};
			}
			else {
				vi tmp;
 
				tmp.pb(dp[to].first);
				tmp.pb(dp[to].second);
				tmp.pb(dp[v].first+1);
 
				sort(all(tmp));
				dp[to] = {tmp[2], tmp[1]};		
			}
		}
 
		reroot(to, v);
		
		dp[to] = DPto;
		dp[v] = DPv;
	}
}
 
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
 
	for(int i = 0; i < n-1; i++) {
		int a,b; cin >> a >> b;
		a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
 
	calc(0, 0);
	reroot(0, 0);
 
	for(int i = 0; i < n; i++)
		cout << ans[i] << "\n";
	
	return 0;
}
