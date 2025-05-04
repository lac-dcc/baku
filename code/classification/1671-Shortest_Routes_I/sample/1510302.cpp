#if 1
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
 
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef pair<ll, ll> l4;
 
#define INFI 1e9 + 1
#define INFL 1e18 + 1
 
#define forn(i, start, upto) for (int(i) = (start); (i) < (upto); (i)++)
 
#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define NAME(x) #x << " = " << x << " "
#define TAB(cnt) forn(i, 0, cnt) cout << "\t";
 
#ifdef HIEPDANG
#include <chrono>
#endif
/*************/
#endif
 
int n, m;
vi visited;
vector<ll> dist;
vector<vector<l4>> g;
 
void add_edge(ll a, ll b, ll w) {
    g[a].emplace_back(b, w);
    //g[b].emplace_back(a, w);
}
 
void dijkstra() {
    dist.assign(n, INFL);
    visited.assign(n, 0);
 
    priority_queue<l4> q;
    q.emplace(0ll, 1ll);
    dist[1] = 0ll;
 
    while (!q.empty()) {
        int temp = q.top().second;
        q.pop();
 
        if (visited[temp]) {
            continue;
        }
        visited[temp] = 1;
 
        for (auto i : g[temp]) {
            ll next = i.first;
            ll c_w = i.second;
 
            if (dist[temp] + c_w < dist[next]) {
                dist[next] = dist[temp] + c_w;
                q.emplace(-dist[next], next);
            }
        }
    }
}
 
int main() {
 
#ifdef HIEPDANG
    auto st = chrono::system_clock::now();
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n >> m;
    n++;
 
    g.assign(n, vector<l4>());
 
    forn(i, 0, m) {
        ll a, b, w;
        cin >> a >> b >> w;
        add_edge(a, b, w);
    }
 
    dijkstra();
 
    forn(i, 1, n) { cout << dist[i] << " "; }
 
#ifdef HIEPDANG
    auto ed = chrono::system_clock::now();
    std::chrono::duration<double> diff = ed - st;
    cout << "\n" << diff.count();
#endif
 
    return 0;
}
