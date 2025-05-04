#include <bits/stdc++.h>
using namespace std;
 
#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif
 
template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}
 
const long long INF = 1e18;
 
long long dist[500][500];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
 
    int n, m, q;
    cin >> n >> m >> q;
 
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            dist[i][j] = (i == j ? 0 : INF);
 
    for (int i=0; i<m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        a--, b--;
        dist[a][b] = dist[b][a] = min(dist[a][b], c);
    }
 
    for (int k=0; k<n; k++)
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
 
    for (int i=0; i<q; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
 
        cout << (dist[a][b] == INF ? -1 : dist[a][b]) << "\n";
    }
 
    return 0;
}
