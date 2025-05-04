#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int INF = (1<<29);
const int INFF = 0x7fffffff;
const ll LINF = (1ll<<60);
const ll LINFF = 0x7fffffffffffffff;
const long double PI = 3.14159265359;
 
#define _fi(n) for(int i = 0;i < n;i++)
#define _fj(n) for(int j = 0;j < n;j++)
#define _fk(n) for(int k = 0;k < n;k++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define prec(x) cout << fixed << setprecision(x)
#define sz(x) (int)x.size()
#define _log2(x) 31-__builtin_clz(x)
 
#define hash sodnf9843bsd
#define right iadjfof23n3okd
#define pqueue priority_queue
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define len length
#define endl '\n'
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll a, ll b){return uniform_int_distribution<ll>(a, b)(rng);}
 
// 17988578
const int maxn = 2e5;
 
struct tnode{
    ll sum;
    ll max_sum = -LINF;
    ll max_prefix = -LINF;
    ll max_suffix = -LINF;
};
 
int n;
tnode tree[4*maxn+33];
 
tnode combine(tnode &left, tnode &right){
    tnode res;
 
    res.sum = left.sum+right.sum;
    res.max_sum = max({left.max_sum, right.max_sum, left.max_suffix+right.max_prefix});
    res.max_prefix = max({left.max_prefix, left.sum+right.max_prefix});
    res.max_suffix = max({right.max_suffix, right.sum+left.max_suffix});
 
    return res;
}
 
void update(int i, ll x, int node = 1, int l = 0, int r = n-1){
    if (l > i || r < i) return;
    if (l == i && r == i){
        tree[node].sum = x;
        tree[node].max_sum = x;
        tree[node].max_prefix = x;
        tree[node].max_suffix = x;
        return;
    }
    int mid = (l+r)/2;
    update(i, x, node*2, l, mid);
    update(i, x, node*2+1, mid+1, r);
    tree[node] = combine(tree[node*2], tree[node*2+1]);
}
 
tnode query(int l, int r, int node = 1, int tl = 0, int tr = n-1){
    if (l > r) return {};
    if (l == tl && r == tr) return tree[node];
    int mid = (tl+tr)/2;
    tnode left = query(l, min(r, mid), node*2, tl, mid);
    tnode right = query(max(mid+1, l), r, node*2+1, mid+1, tr);
    tnode res = combine(left, right);
    return res;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int m;cin>>n>>m;
    _fi(n){
        ll x;cin>>x;
        update(i, x);
    }
 
    while(m--){
        int i;cin>>i;
        ll x;cin>>x;
 
        update(i-1, x);
        cout << max(0ll, query(0, n-1).max_sum) << endl;
    }
 
    return 0;
}
