#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef string str;
 
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<double, double> pd;
 
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<pd> vpd;
 
#define vc vector
#define pb push_back
#define pf push_front
#define rsz resize
#define sz size
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
 
#define ub upper_bound
#define lb lower_bound
 
#define f first
#define s second
#define mp make_pair
 
#define ln length
#define IMX INT_MAX
#define IMN INT_MIN
 
void IO(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    if (s.length()) {
        freopen((s+".in").c_str(),"r",stdin);
        freopen((s+".out").c_str(),"w",stdout);
    }
}
 
int n, m;
vi v[100001];
bool vis[100001];
int bi[100001];
bool no = false;
 
void dfs(int k, int x) {
    if (vis[k]) return;
    if (no) return;
    int now;
    vis[k] = true;
    if (x == 1) now = 2;
    else now = 1;
    bi[k] = now;
    for (auto i: v[k]) {
        if (!vis[i])
            dfs(i, now);
        else 
            if (bi[i] == now)
                no = true;
    }
}
 
int main() {
    IO("");
 
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        dfs(i, 2);
    }
    if (no) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for (int i = 1; i <= n; i++)
        cout << bi[i] << ' ';
    cout << '\n';
}
 
/* Stuff to look for
 * int overflow, array bounds
 * special cases (n=1)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
