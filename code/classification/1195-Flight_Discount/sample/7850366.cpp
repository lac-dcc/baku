#include <bits/stdc++.h>
#include <queue>
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
#define INF (1<<30)
#define LINF (1LL<<61)
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define lsb(i) (i&(-i))
#define all(z) begin(z), end(z)
#define EPS ((double)(1e-9))
const int maxn = 512345;
const int maxm = 31234;
 
int n;
vector<pair<int,ll>> prox[maxn];
 
vector<ll> dijkstra(int s){
	priority_queue<pair<ll, int>, vector<pair<ll,int>>, greater<>> que;
	que.emplace(0, s);
	vector<ll> dist(maxn, LINF);
	dist[s] = 0;
	while(que.size()){
		auto atu = que.top();
		que.pop();
		if(atu.x != dist[atu.y]) continue;
		for(auto [u, c]: prox[atu.y]){
			if(dist[u] > dist[atu.y] + c){
				que.emplace(dist[u] = dist[atu.y] + c, u);
			}
		}
	}
	return dist;
}
 
void solve(){
	int m;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int a,b;
		ll c;
		cin >> a >> b >> c;
		prox[a].emplace_back(b, c);
		prox[a].emplace_back(b+n, c/2);
		prox[a+n].emplace_back(b+n, c);
	}
	auto dist = dijkstra(1);
	cout << dist[n+n] << "\n";
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	for(int caso=1;caso<=t;caso++){
		solve();
	}
	return 0;
}
