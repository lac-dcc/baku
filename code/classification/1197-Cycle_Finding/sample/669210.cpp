#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pii pair<ll,ll>
#define pb push_back
using namespace std;
const int N = 2e5+5;
int n,m;
int vis[N];
vector<pii> adj[N];
int main() {
	cin >> n >> m;
	vector<pair<pair<int,int>,int>> e;
	for (int i = 0; i < n;i++)
		e.pb({{n,i},0});
	for (int i = 0; i < m ;i++) {
		int a,b,val;
		cin >> a >> b >> val;
		a--;
		b--;
		e.pb({{a,b},val});
	//	adj[a].pb({b,val});
	//	adj[b].pb({a,val});
	}
	vector<ll> P(n),d(n+1);
	for (int i = 0; i < n; i++)
		d[i] = 1e15;
	for (int i = 0; i <= n; i++) {
	for (auto x : e) {
		int from = x.first.first;
		int to = x.first.second;
		int val = x.second;
		if (d[from] + val < d[to]) {
			d[to] = d[from] + val;
			P[to] = from;
				if (i ==n ) 
				{
					vector<int> vis(n+1),ans;
				while(vis[to] != 2) {
					vis[to]++;
					if (vis[to] == 2) ans.pb(to);
					to = P[to];
				}
				ans.pb(ans[0]);
				reverse(ans.begin(),ans.end());
				cout <<"YES\n"; //ans.size() <<'\n';
				for (int i : ans) cout << i+1 <<' ';
				exit(0);
			}
		}
	}}
	cout << "NO";
	return 0;
}
