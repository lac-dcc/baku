#pragma GCC optimize("Ofast,O3,unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define bp __builtin_popcountll
#define mp make_pair
#define pb push_back
#define vec vector
#define ll long long
#define F first
#define S second
#define pii pair <int, int>
#define elif else if
#define sz(a) int32_t(a.size())
#define lb lower_bound
#define ub upper_bound
#define all(a) a.begin(), a.end()
#define fl fflush(stdout)
#define ex exit(0)
#define inta ll
using namespace std;
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rnd(878787);
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
const inta N = 2e5 + 10;
vector <pii> g[N], gr[N];
inta n, ar[N], d[N], m;
bool us[N];
 
vector <inta> get(inta st){
    set <pii> s;
    for(inta i = 0; i < N; ++i) d[i] = 1e18, us[i] = 0;
    d[st] = 0;
    for(inta i = 1; i <= n; ++i) s.insert(mp(d[i], i));
 
    while(!s.empty()){
        pii f = *(s.begin());
        inta x = f.S; us[x] = 1;
        for(auto to: g[x]){
            if(!us[to.F] && d[to.F] > d[x] + to.S){
                s.erase(mp(d[to.F], to.F));
                d[to.F] = d[x] + to.S;
                s.insert(mp(d[to.F], to.F));
            }
        }
        s.erase(s.begin());
    }
 
    vector <inta> v;
    for(inta i = 1; i <= n; ++i){
        v.pb(d[i]);
    }
    return v;
 
 
}
 
struct nod{
    inta a, b, c;
};
vector <nod> ff;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    cin >> n >> m;
 
 
    for(inta i = 1; i <= m; ++i){
        inta a, b, c; cin >> a >> b >> c;
        g[a].pb(mp(b, c));
        ff.emplace_back(); ff[sz(ff) - 1].a = b;
        ff[sz(ff) - 1].b = a; ff[sz(ff) - 1].c = c;
    }
    vector <inta> v1 = get(1);
 
    for(inta i = 1; i <= n; ++i) g[i].clear();
    for(auto to: ff) g[to.a].pb(mp(to.b, to.c));
 
    vector <inta> v2 = get(n);
 
    inta ans = 1e18;
    for(auto to: ff){
        inta x = to.b, y = to.a;
        //cout << x << " " << y << " " << to.c << endl;
        ans = min(ans, v1[x - 1] + v2[y - 1] + (to.c / 2));
    }
    cout << ans;
 
 
    //for(auto to: v1) cout << to << " "; cout << endl;
    //for(auto to: v2) cout << to << " "; cout << endl;
 
 return 0;
}
