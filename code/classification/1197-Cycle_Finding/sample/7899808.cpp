#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
template<class T> bool ckmin(T& a, const T& b) {
    return a > b ? a = b, 1 : 0;
}
template<class T> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0;
}
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pp;
#define int ll
#define lld long double
#define REP(x, y) for (int x = 0; x < y; ++x)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define vt vector
#define f first
#define s second
#define pb push_back
#define PI atan(1) * 4
#define read(a) for (int &i : a) { cin >> i; }
#define KickstarT(test_case) cout << "Case #" << test_case << ": "
#define endl '\n'
#define in(input) freopen(input, "r", stdin)
#define out(output) freopen(output, "w", stdout)
//----------------------------------------------------------------------------------------//
int d8[2][8] = {{-1, -1, 0, 1, 1, 1, 0, -1}, {0, 1, 1, 1, 0, -1, -1, -1}};
int d4[2][4] = {{-1, 0, 1, 0}, {0, 1, 0, -1}};
char dc[] = {'U', 'R', 'D', 'L'}; // N E S W
const int MD = 1e9 + 7;
const int N = 2e5 + 1;
 
/*
*/
 
#define ar array
const int inf = 1e15;
int n, m;
vt<ar<int, 3>> E;
vt<int> dist, p;
bool neg;
int last;
 
/*
You are given a directed graph, and your task is to determine whether it contains a negative cycle. Additionally, if a negative cycle is present, provide an example of such a cycle.
 
Input:
 
The first line contains two integers, n and m, representing the number of nodes and edges, respectively. Nodes are numbered from 1 to n.
The following m lines describe the edges, each containing three integers a, b, and c. This signifies an edge from node a to node b with a length of c.
Output:
 
If the graph contains a negative cycle, output "YES" followed by the nodes in the cycle in their correct order.
If there are multiple negative cycles, any valid cycle is acceptable.
If there are no negative cycles, output "NO".
Constraints:
 
1 ≤ n ≤ 2500
1 ≤ m ≤ 5000
1 ≤ a, b ≤ n
-10^9 ≤ c ≤ 10^9
*/
 
void bellman_ford() {
    dist[0] = 0;
    for (int i = 0; i < n; i++) {
        for (auto [x, y, v] : E) {
            if (dist[x] + v < dist[y]) {
                dist[y] = dist[x] + v;
                p[y] = x;
                last = y;
                if (i == n - 1) {
                    neg = 1;
                }
            }
        }
    }
    if (neg) {
        for (int i = 0; i < n; i++) {
            last = p[last];
        }
        vt<int> path;
        for (int v = last;; v = p[v]) {
            path.pb(v);
            if (v == last && path.size() > 1)
                break;
        }
        reverse(ALL(path));
        cout << "YES\n";
        for (int v : path) cout << v + 1 << " ";
    }
}
 
void solve(int t_c) {
    cin >> n >> m;
    p.assign(n, -1);
    dist.assign(n, inf);
    for (int i = 0; i < m; i++) {
        int x, y, v;
        cin >> x >> y >> v;
        --x, --y;
        E.pb({x, y, v});
    }
    bellman_ford();
    if (!neg)
        cout << "NO";
}
 
#undef int
int main() {
//    in("test_input.txt");
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
//    cin >> t;
    REP (i, t) {
        solve(i);
    }
    return 0;
}
