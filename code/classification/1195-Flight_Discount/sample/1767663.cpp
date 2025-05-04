#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#define mikumywaifu ios_base::sync_with_stdio(0)
#define misakamywaifu cin.tie(0)
#define pb push_back
#define S second
#define F first
#define mem(i,j) memset(i,j,sizeof(i))
#define pii pair<int,int>
#define pll pair<long long,long long>
#define lowbit(x) x&-x
const ll mod = 1000000007;
const int INF = 0x3F3F3F3F;
const long long LINF = 4611686018427387903;
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	a %= b;
	return gcd(b, a);
}
void debug() {
	cout << "DEBUG :";
}
/*-----------------------------------------------*/
int n, m;
vector<vector<pll> >edge;
vector<vector<pll> >redge;
vector<ll> dijkstra(int s,vector<vector<pll> >ed) {
	vector<ll> dis(n + 1, LINF);
	dis[s] = 0;
	priority_queue<pll, vector<pll>, greater<pll> >pq;
	pq.push({ 0,s });
	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		ll v = p.first, pos = p.second;
		if (v > dis[pos]) continue;
		for (auto e : ed[pos]) {
			if (dis[e.second] > dis[pos] + e.first) {
				dis[e.second] = dis[pos] + e.first;
				pq.push({ dis[e.second],e.second });
			}
		}
	}
	return dis;
}
struct e {
	ll s, ed, v;
};
signed main() {
	mikumywaifu;
	misakamywaifu;
	cin >> n >> m;
	edge.resize(n + 1);
	redge.resize(n + 1);
	vector<e> mp;
	for (int i = 0;i < m;i++) {
		ll x, y, v;
		cin >> x >> y >> v;
		mp.push_back({ x,y,v });
		edge[x].push_back({ v,y });
		redge[y].push_back({ v,x });
	}
 
	vector<ll> a1 = dijkstra(1,edge);
	vector<ll> a2 = dijkstra(n,redge);
	ll mn = LINF;
	for (int i = 0;i < m;i++) {
		mn = min(mn,a1[mp[i].s]+a2[mp[i].ed]+mp[i].v/2);
	}
	cout << mn << "\n";
 
	return 0;
}
