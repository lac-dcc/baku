//Author: A_S_M_M@sud_P@rvez
#include <bits/stdc++.h>
using namespace std;
#define MP ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define Forn(i,a,n) for (int i = a; i < n; i++)
#define Fors(i,s) for (int i = 0; i < s.size(); i++)
#define all(v) v.begin(), v.end()
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * (b / __gcd(a, b)))
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define min4(a, b, c, d) min(min(a, b), min(c, d))
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define Max(a) *max_element(a, a + sizeof(a) / sizeof(a[0]))
#define Min(a) *min_element(a, a + sizeof(a) / sizeof(a[0]))
#define vprint(v) {Fors(i,v)cout<<v[i]<<" ";cout<<"\n";}
#define arprint(a,n) {Forn(i,0,n)cout<<a[i]<<" ";cout<<"\n";}
#define pprint(vp) {Fors(i,vp) {cout << vp[i].ff << " " << vp[i].ss << endl;}}
#define mpprint(mp) for (auto it : mp) {cout <<it.ff << " " << it.ss << endl;}
#define gt greater<ll>() 
#define ff first
#define ss second
#define pb push_back
#define ok return
#define vi vector<int>
#define mod 1000000007
#define sp(n) fixed << setprecision(n)
#define Erase(s) s.erase(unique(s.begin(), s.end()), s.end())
#define ll long long int
#define yes cout << "Yes" << endl 
#define no  cout << "No" << endl 
//%%%%%%%%%%%%p%%%a%%%r%%%v%%%e%%%z%%%%%%%%%%%//
const int N = 2e5;
const ll inf = 1e18;
vector<pair<ll,ll>> adj[N+5];
ll dist[N+1];
 
void dijkstra(int n , int src) {
    for (int i = 1; i <= n; i++) dist[i] = inf;
 
	priority_queue< pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
	dist[src] = 0;
	pq.push({0, src});
 
	while(!pq.empty()) {
		ll node = pq.top().second;
		ll d = pq.top().first;
		pq.pop();
		
		if(dist[node] < d) continue;
 
		for(pair<int,int> edge : adj[node]){
			ll v = edge.first;
			ll w = edge.second;
 
			if(d + w < dist[v]){
				dist[v] = d + w;
				pq.push({dist[v] , v});
			}
		}
	}
}
void solve()
{
    ll n, m, w, u, v;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        adj[u].pb({v,w});
    }
    dijkstra(n,1);
    for (int i = 1; i <= n; i++) cout << dist[i] << " ";
}
 
int main()
{
    MP;
    int T = 1;
    //cin >> T; while(T --)
    solve();
 
    cerr<<endl<<(float)clock()/(float)CLOCKS_PER_SEC<<" sec"<<endl;
    return 0;
}