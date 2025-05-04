#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
struct Node
{
    ll maxSub = LLONG_MIN;
    ll prefix = 0;
    ll suffix = 0;
    ll sum = 0;
};
Node operator +(Node a, Node b)
{
    Node ans;
    ans.maxSub = max({a.maxSub, b.maxSub, a.suffix+b.prefix});
    ans.prefix = max(a.prefix, a.sum+b.prefix);
    ans.suffix = max(b.suffix, b.sum+a.suffix);
    ans.sum = a.sum + b.sum;
 
    return ans;
}
int n, q;
vector<ll> a;
vector<Node> seg(1<<19);
 
void build(int id, int l, int r)
{
    if (l == r)
    {
        if (l <= n)
        {
            seg[id].maxSub = a[l];
            seg[id].prefix = a[l];
            seg[id].suffix = a[l];
            seg[id].sum = a[l];
        }
        return;
    }
 
    int mid = (l+r)>>1;
    build(id<<1, l, mid);
    build(id<<1|1, mid+1, r);
 
    seg[id] = seg[id<<1] + seg[id<<1|1];
}
 
void update(int id, int l, int r, int i, ll val)
{
    if (i < l || i > r) return;
    if (l == r)
    {
        seg[id].maxSub = val;
        seg[id].prefix = val;
        seg[id].suffix = val;
        seg[id].sum = val;
        return;
    }
 
    int mid = (l+r)>>1;
    update(id<<1, l, mid, i, val);
    update(id<<1|1, mid+1, r, i, val);
 
    seg[id] = seg[id<<1] + seg[id<<1|1];
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #if 0
        freopen("INPUT.INP", "r", stdin);
    #endif
 
    cin >> n >> q;
    a.resize(n+1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int sz = 1;
    while (sz < n) sz <<= 1;
    build(1, 1, sz);
    while (q--)
    {
        int k;
        ll x;
        cin >> k >> x;
        update(1, 1, sz, k, x);
        cout << max(0LL, seg[1].maxSub) << '\n';
    }
    return 0;
}
