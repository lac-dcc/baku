#include <bits/stdc++.h>
using namespace std;
#define bit(x,i) ((x >>i)&1)
#define pb push_back
#define f first
#define s second
#define mp make_pair
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<long long> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;
const int diri[8] = { -1, 0, 0, 1, -1, -1, 1, 1 };
const int dirj[8] = { 0, 1, -1, 0, -1, 1, -1, 1 };
const int knightj[]={-2, -2, -1, -1,  1,  1,  2,  2};
const int knighti[]={-1,  1, -2,  2, -2,  2, -1,  1};
string dirl = "URLD";
template<typename T,typename V> ostream& operator<<(ostream &s,pair<T,V> t) {return s<<"{"<<t.first<<","<<t.second<<"}";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t) {s << "[";for (int i = 0; i < t.size(); ++i) {s << t[i];
if (i != t.size() - 1) {s << ", ";}}s << "]";return s;}
template<typename T, typename V> ostream& operator<<(ostream &s,map<T, V> t) {s << "{";for (auto& a : t) {s << a << " ";} s << "}";return s;}
template<typename... T> void put(T&&... args) { ((cout << args << " "), ...);}
template<typename... T> void putl(T&&... args) { ((cout << args << " "), ...); cout<<'\n';}
template <typename T> void p(const T &t) {cout << t << " ";}
template <typename T> void pl(const T &t) {cout << t << endl;}void testcases();
const int mod = 1e9+7;
 
void dfs(vvi& g, vb& visited, int v) {
    visited[v] = true;
    for (auto a : g[v]) {
        if (!visited[a]) {
            dfs(g,visited,a);
        }
    }
}
 
void solve() {
    int n, m; cin >> n >> m;
    vvi graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    vi res;
    vb visited(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(graph, visited, i);
            res.push_back(i);
        }
    }
    putl(res.size() - 1);
    for (int i = 0; i < res.size() - 1; ++i) {
        putl(res[i], res[i + 1]);
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // testcases();
    solve();
    return 0;
}
 
void testcases() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}
