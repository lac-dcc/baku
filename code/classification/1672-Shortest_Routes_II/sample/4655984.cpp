#include <bits/stdc++.h>
using namespace std;
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
 
 
typedef unsigned long long ll;
//typedef unsigned long long ull;
 
typedef pair<ll, ll> pl;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<vl> vvl;
typedef vector<pl> vpl;
typedef vector<vb> vvb;
 
#define loop(n) for(ll ii = 0; ii < n; ii++)
#define loop1(n) for(ll i = 1; i <= n; i++)
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define vc vector
#define inf LLONG_MAX
 
const long long N = 1e5 + 10;
const long long NN = 1e9;
const long long M = 1e3;
 
const long long mod = NN + 7;
 
 
ifstream file;
 
//vb mark(NN + 1, false);
//vector<ll> factor(N + 1, 0);
//vector<ll> b(N + 1, 0);
//vector<ll> primes;
ll n, m, k, q;
 
//map<pl, ll> e;
//vl distA(N, INF);
//vl distB(N, INF);
////vl p(N);
//vector<vpl> adj1(N);
//vector<vpl> adj2(N);
//vector<tuple<ll, ll, ll>> edges;
 
 
//ll cnt;
 
//void dijkstra(ll s, vl& dist, vector<vpl>& adj) {
//    priority_queue<pl> q;
//    dist[s] = 0;
//    q.push({ dist[s], s});
//
//    while (!q.empty()) {
//        ll v = q.top().ss, cur_d = -q.top().ff;
//        q.pop();
//        if (cur_d > dist[v]) continue;
//        for (auto node : adj[v]) {
//            ll to = node.ss, len = node.ff;
//            if (dist[v] + len < dist[to]) {
//                dist[to] = dist[v] + len;
//                q.push({ -dist[to], to });
//            }
//        }
//    }
//}
 
void floyd(vvl & d, ll n) {
    for (ll k = 1; k <= n; k++) {
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[j][k]);
            }
        }
    }
}
 
void solve() {
    cin >> n >> m >> q;
    vvl d(n+1, vector<ll>(n + 1, inf));
 
    for (ll i = 1; i <= n; i++) {
        d[i][i] = 0;
    }
 
    loop1(m) {
        ll a, b, c;
        cin >> a >> b >> c;
        d[a][b] = min(c, d[a][b]);
        d[b][a] = min(c, d[b][a]);
    };
 
    floyd(d, n);
 
    loop(q) {
        ll a, b;
        cin >> a >> b;
        if (d[a][b] >= LLONG_MAX) {
            cout << -1 << endl;
        }
        else {
            cout << d[a][b] << endl;
        }
    }
}
 
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    //file.open("test.txt");
 
    // loop1(N) b[i] += b[i - 1];
 
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
 
        solve();
        // file >> n;
    }
    //file.close();
}
