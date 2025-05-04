#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<bool> vb;
typedef vector<pair<int,int>> vpi;
 
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
 
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define pi pair<int, int>
#define mp make_pair
#define F first
#define S second
 
int n, a, b;
vvi adj;
 
pi dfs(int i, int par) {
    pi ans = mp(0, i);
    for (int nb : adj[i]) if (nb!=par) {
        pi cur = dfs(nb, i);
        if (cur.F+1>ans.F) ans=mp(cur.F+1, cur.S);
    }
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    adj.rsz(n);
    F0R(i, n-1) {
        cin >> a >> b;
        adj[a-1].pb(b-1);
        adj[b-1].pb(a-1);
    }
    pi cur = dfs(0, 0);
    cur = dfs(cur.S, cur.S);
    cout << cur.F << '\n';
}
