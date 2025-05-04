#include <bits/stdc++.h>
#define sum first
#define pre second
using namespace std;
 
const int N = 1e6 + 5;
 
typedef pair<long long, long long> ii;
int n, q;
 
ii merg(ii a, ii b)
{
    return {a.sum + b.sum, max(a.pre, a.sum + b.pre)};
}
struct seg
{
    vector<ii> t;
    int n;
    seg(int _n = 0)
    {
        n = _n;
        t.assign(4*n + 7, {0, 0});
    }
    void upd(int id, int l, int r, int k, long long val)
    {
        if (l == r)
        {
            t[id] = {val, max(0ll, val)};
            return;
        }
        int mid = (l + r)>>1;
        if (k <= mid) upd(id*2, l, mid, k, val); else upd(id*2 + 1, mid + 1, r, k, val);
        t[id] = merg(t[id * 2], t[id * 2 + 1]);
    }
    ii get(int id, int l, int r, int u, int v)
    {
        if (l > v || r < u) return {0, 0};
        if (l >= u && r <= v) return t[id];
        int mid = (l + r)>>1;
        return merg(get(id*2, l, mid, u, v), get(id*2 + 1, mid + 1, r, u, v));
    }
    void upd(int pos, long long val)
    {
        upd(1, 1, n, pos, val);
    }
    ii get(int u, int v)
    {
        return get(1, 1, n, u, v);
    }
};
int main()
{
//    freopen("prefixsum.inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    seg myit(n);
    for (int i = 1 ; i <= n ; i++)
    {
        long long x; cin>>x;
        myit.upd(i, x);
    }
    while (q--)
    {
        int type; cin>>type;
        if (type == 1)
        {
            long long pos, val; cin>>pos>>val;
            myit.upd(pos, val);
        } else
        {
            int a, b; cin>>a>>b;
            cout<<myit.get(a, b).pre<<"\n";
        }
    }
}
