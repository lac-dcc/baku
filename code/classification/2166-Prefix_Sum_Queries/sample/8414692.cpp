#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define F first
#define S second
#define pb push_back
 
ll mod = 1e9+7;
inline ll add(ll a, ll b)
{
    return (a%mod + b%mod)%mod;
}
 
 
class node{
public:
    ll total, best; 
    node(ll t = 0, ll b = 0)
    {
        total = t; 
        best = max(b,0LL);
    }
};
 
node merge(node &a, node &b)
{
    node temp(0, 0);
    temp.total = a.total + b.total;
    
    temp.best = max(max(0LL,a.best), a.total + b.best);
    return temp ;
}
 
class segment_tree{
public:    
    vector<node> t;
    segment_tree(ll n)
    {
       t.resize(4*n + 1) ; 
    }
 
    void build(ll i, ll l, ll r, vector<ll> &a)
    {
        if(l == r)
        {
            t[i] = node(a[l], a[l]);
            return ;
        }
 
        ll mid = (l+r)/2 ;
        build(2*i, l, mid, a);
        build(2*i + 1, mid+1, r, a);
        t[i] = merge(t[2*i], t[2*i + 1]);
    }
 
    void update(ll i, ll l, ll r, ll pos, ll val)
    {
        if(pos < l || pos > r)
            return ;
        if(l == r)
        {
            t[i] = node(val, val);
            return ;
        }
        ll mid = (l+r)/2 ;
        update(2*i, l, mid, pos, val);
        update(2*i + 1, mid+1, r, pos, val);
        t[i] = merge(t[2*i], t[2*i + 1]);
    }
 
    node query(ll i, ll l, ll r, ll lq, ll rq)
    {
        if(l > rq || lq > r)
            return node(0, 0);
 
        if(lq <= l && rq >= r)
            return t[i]; 
 
        ll mid = (l + r)/2; 
        node x = query(2*i, l, mid, lq, rq);
        node y =query(2*i+1, mid+1, r, lq, rq) ;
        node z = merge(x , y);
        return z;
 
    }
};
 
 
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    ll t; t = 1;
    // cin >> t;
    while(t--)
    {
        ll n, q;
        cin >>n >> q;
        vector<ll> a(n);
        for(ll i = 0; i < n; i++)
            cin >> a[i];
        segment_tree tree(n);
        tree.build(1, 0, n-1, a);
        while(q--)
        {
            ll type;
            cin >> type;
            if(type == 1)
            {
                ll x, y;
                cin >> x >> y;
                tree.update(1, 0, n-1, x-1, y);
            }
            else
            {
                ll x, y;
                cin >> x >> y;
                node no = tree.query(1, 0, n-1, x-1, y-1);
                cout << no.best << "\n";
            }
        }
 
    }
 
    
    
 
    return 0;
}
 
