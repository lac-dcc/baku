#include <bits/stdc++.h>
using namespace std;
 
#define ipr pair<int, int>
#define pb push_back
#define ff first
#define ss second
#define fr(i, j, k) for (int i = j; i < k; i++)
#define rf(i, j, k) for (int i = j; i >= k; i--)
#define ll unsigned long long
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mp make_pair
#define cnt_ones(x) __builtin_popcountll(x)
 
#define IOS                           \
    std::ios::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
 
const int Maxn = 1500;
const ld pi = acos(-1);
const int mod = 998244353;
const int inf = (int)1e18;
 
template <class T>
ostream &operator<<(ostream &out, vector<T> &A) {
    fr(i, 0, (int)A.size()) out << A[i] << " ";
    return out;
}
 
int n, e;
vector<vector<int>> g;
vector<int> dis;
 
 
//--> Take input of given graph
void graph_inp() {
    cin >> n;
    g.resize(n);
    dis.resize(n, inf);
    e = n - 1;
    fr(i, 0, e) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].pb(v);
        g[v].pb(u);
    }
   // assert(false);
}
 
void graph_print() { fr(i, 0, n) cout << g[i] << '\n'; }
 
 
//--> calculate distance from root to every other node for a graph
int bfs(int root) {
    fill(all(dis), inf);
    queue<int> q;
    q.push(root);
    dis[root] = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto child : g[node])
            if (dis[child] == inf) {
                dis[child] = dis[node] + 1;
                q.push(child);
            }
    }
    int node = 0;
    fr(i,0,n){
        if(dis[i] > dis[node]){
            node = i;
        }
    }
    return node;
}
 
 
int32_t main() {
    graph_inp();
    int node = bfs(0);
    //cout << endl;
    cout << dis[bfs(node)];
    return 0;
}
