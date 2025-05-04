#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define fr(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>
#define minheap priority_queue<int, vector<int>, greater<int>>
using namespace std;
 
const int mod = 1e9 + 7;
// const int mod = 998244353;
const int inf = 1e18;
pii maxi = {1, 0};
 
vi adj[200005];
int maxdist[200005];
 
void dfs(int child, int par, int dist) {
    for(auto node : adj[child]) {
        if(node != par) dfs(node, child, dist + 1);
    }
    if(dist >= maxi.second) maxi = {child, dist};
}
 
void bfs(int child, int par, int dist) {
    maxdist[child] = max(dist, maxdist[child]);
    for(auto node : adj[child]) {
        if(node != par) bfs(node, child, dist + 1);
    }
}
 
void solve()
{
    memset(maxdist, 0, sizeof(maxdist));
    int n, a, b;
    cin >> n;
    fr(i, 1, n) {cin >> a >> b; adj[a].pb(b); adj[b].pb(a);}
    dfs(1, -1, 0);
    a = maxi.first;
    dfs(a, -1, 0);
    b = maxi.first;
    bfs(a, -1, 0);
    bfs(b, -1, 0);
    fr(i, 1, n + 1) cout << maxdist[i] << " ";
}
 
signed main()
{
 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int tc;
    // cin >> tc;
    // while (tc--)
    solve();
    return 0;
}
