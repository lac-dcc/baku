#include <bits/stdc++.h>
#define ll long long int
 
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pbds tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
using namespace __gnu_pbds;
 
#define ld long double
#define vv vector <ll>
using namespace std;
 
 
#define deb(x) cout << #x << " = " << x << endl;
 
template <typename T>
void print(T t){for (auto &i : t) cout << i << " "; cout << endl;}
template <typename T>
T binpow(T a, T b, T mod){T res = 1; while(b>0){if(b&1){res = res * a % mod;} a = a*a % mod; b = b>>1;} return res;}
 
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define minv(a) *min_element(all(a))
#define maxv(a) *max_element(all(a))
 
#define vect(v, n) vv v(n); for(ll i = 0; i < n; i++) cin >> v[i]
#define uniq(v) v.erase( unique( v.begin(), v.end() ), v.end())
 
#define pb push_back
 
 
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
const ll MOD = 1e9+7;
const ld PI = acos(-1);
const ld EPS = 1e-9;
const ll INF = 1e18;
 
pair<ll, ll> dfs(ll u, vector<ll> &vis, vector< vector<ll> > &adj, vector<ll> &par){
    vis[u] = 1;
    for(auto v:adj[u]){
        if(vis[v] && v != par[u]){
            return {u,v};
        }else if(!vis[v]){
            par[v] = u;
            auto t = dfs(v, vis, adj, par);
            if(t.first != 0) return t;
        }
    }
    return {0,0};
}
class segtree{
public:
    ll n;
    vector<ll> arr;
    segtree(ll sz){
        n = sz;
        arr.clear();
        arr.resize(4*n+5);
    }
 
    void build(ll i, ll l, ll r, vector<ll> &v){
        if(l == r){
            arr[i] = v[l];
            return;
        }
        build(2*i, l, (l+r)/2, v);
        build(2*i+1,(l+r)/2+1, r, v);
        arr[i] = min(arr[2*i], arr[2*i+1]);
    }
 
    void update(ll i, ll l, ll r, ll ind, ll val){
        if(l == r){
            arr[i] = val;
            return;
        }
 
        ll mid = (l+r)>>1;
 
        if(ind <= mid){
            update(2*i, l, mid, ind, val);
        }else{
            update(2*i+1, mid+1, r, ind, val);
        }
        arr[i] = min(arr[2*i], arr[2*i+1]);
    }
 
    ll query(ll i, ll l, ll r, ll ql, ll qr){
        if(l > r) return INF;
        if(ql > qr) return INF;
        if(l == ql && r == qr){
            return arr[i];
        }
 
        ll mid = (l+r)>>1;
        if(qr <= mid){
            return query(2*i, l, mid, ql, qr);
        }else if(ql > mid){
            return query(2*i+1, mid+1, r, ql, qr);
        }else{
            return min(query(2*i, l, mid, ql, mid), query(2*i+1, mid+1, r, mid+1, qr));
        }
    }
};
 
ll dfs(ll u, vector<ll> &vis, vector<ll> &p,vector< vector<ll> > &adj){
    vis[u] = 1;
    for(auto v: adj[u]){
        if(vis[v] && v != p[u]){
            p[v] = u;
            return v;
        }
        else if(!vis[v]){
            p[v] = u;
            ll t = dfs(v, vis, p, adj);
            if(t) return t;
        }
    }
    return 0;
}
 
 
void solve(void){
    ll n, m;
    cin >> n >> m;
 
    vector< vector<ll> > adj(n+1);
    for(ll i = 0; i < m; i++){
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    vector<ll> vis(n+1, 0), p(n+1, -1);
    for(ll i = 1; i <= n; i++){
        if(!vis[i]){
            p[i] = i;
            ll t = dfs(i, vis, p, adj);
            // print(p);deb(t);
            if(t){
                vector<ll> ans;
                ans.push_back(t);
                ll x = p[t];
                
                while(x != t){
                    ans.push_back(x);
                    x = p[x];
                }
 
                ans.push_back(x);
                reverse(all(ans));
                cout << ans.size() << "\n";
                print(ans);
                return;
            }
        }
    }
    cout << "IMPOSSIBLE";
}
 
 
int main(void)
{
 
    FAST
 
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    ll t = 1;
    // cin >> t;
 
    while(t--){
        solve();
        cout << endl;
    }
 
    return 0;
}
