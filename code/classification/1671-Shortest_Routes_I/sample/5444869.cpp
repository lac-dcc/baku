#include <bits/stdc++.h>
using namespace std;
 
//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("bmi,bmi2,lzcnt,popcnt")
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define pb push_back
#define mp make_pair
#define f first
#define s second
 
int MAXN = 1e5+5;
vector<vector<pair<ll, ll>>> adj(MAXN);
vector<ll> dist(MAXN, 1e18), parent(MAXN);
 
void Dijkstra(int x){
    set<pair<ll, ll>> s;
    dist[x] = 0;
    parent[x] = -1;
    s.insert({0, x});
    while(!s.empty()){
        int a = s.begin()->second;
        s.erase(s.begin());
        for(auto i : adj[a]){
            int b = i.f, w = i.s;
            if(dist[b] > dist[a] + w){
                s.erase({dist[b], b});
                dist[b] = dist[a] + w;
                parent[b] = a;
                s.insert({dist[b], b});
            }
        }
    }
}
 
void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].pb({b, w});
    }
    Dijkstra(1);
    for(int i = 1; i <= n; i++)
        cout << dist[i] << ' ';
    cout << '\n';
    /*int u = n;
    vi path;
    while(u != -1){
        path.pb(u);
        u = parent[u];
    }
    reverse(path.begin(), path.end());
    for(auto i : path)
        cout << i << ' ';
    cout << '\n';*/
}  
 
int main(){
    //freopen("bomboane2.in", "r", stdin);
    //freopen("bomboane2.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
