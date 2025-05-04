#include<bits/stdc++.h> 
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define mod 1000000007
typedef long long int ll;
 
using namespace std;
 
struct Node{
    ll delta;
    ll maximum_prefix;
};
 
struct Node tree[4*2*100000];
 
void build(vector<ll> &prefix, ll v, ll tl, ll tr) {
    if(tl == tr) {
        tree[v].delta = 0;
        tree[v].maximum_prefix = prefix[tl];
    } else {
        ll tm = (tl + tr)/2;
        build(prefix, 2*v, tl, tm);
        build(prefix, 2*v+1, tm+1, tr);
        tree[v].delta = tree[2*v].delta + tree[2*v+1].delta;
        tree[v].maximum_prefix = max(tree[2*v].maximum_prefix, tree[2*v+1].maximum_prefix + tree[2*v].delta);
    }
    return;
}
 
void update(vector<ll> &arr, ll v, ll tl, ll tr, ll k, ll val) {
    if(tl == tr) {
        tree[v].delta += (val - arr[k]);
        tree[v].maximum_prefix += (val - arr[k]);
        arr[k] = val;
    } else {
        ll tm = (tl + tr)/2;
        if(k <= tm)
            update(arr, 2*v, tl, tm, k, val);
        else 
            update(arr, 2*v+1, tm+1, tr, k, val);        
        tree[v].delta = tree[2*v].delta + tree[2*v+1].delta;
        tree[v].maximum_prefix = max(tree[2*v].maximum_prefix, tree[2*v+1].maximum_prefix + tree[2*v].delta);
    }
}
 
ll find(ll v, ll tl, ll tr, ll l, ll r) {
    if(l > r)
        return LLONG_MIN;
    if(tl == l && tr == r)
        return tree[v].maximum_prefix;
    else {
        ll tm = (tl + tr)/2;
        ll f1 = find(2*v, tl, tm, l, min(tm, r));
        ll f2 = find(2*v+1, tm+1, tr, max(l, tm+1), r);
        return max(f1, (f2==LLONG_MIN ? LLONG_MIN : f2 + tree[2*v].delta));
    }
}
 
int main() {
    fastio;
    cout<<fixed<<setprecision(10);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
    ll n, q;
    cin >> n >> q;
    vector<ll> v(n);
    for(ll i=0; i<n; i++)
        cin >> v[i];
    
    vector<ll> prefix(n);
    prefix[0] = v[0];
    for(ll i=1; i<n; i++)
        prefix[i] = prefix[i-1] + v[i];
 
    build(prefix, 1, 0, n-1);
    
    while(q--) {
        ll type;
        cin >> type;
        if(type == 1) {
            ll k, x;
            cin >> k >> x;
            k--;
            update(v, 1, 0, n-1, k, x);
        } else if(type == 2) {
            ll l, r;
            cin >> l >> r;
            l--, r--;
            ll f = find(1, 0, n-1, l, r);
            ll f_ = (l>0 ? find(1, 0, n-1, l-1, l-1) : 0);
            cout << max((ll)0, f - f_) << endl;
        }
    }
 
    return 0;
}
