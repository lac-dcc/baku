#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
 
using namespace std;
 
int arr[200005];
 
struct point
{
    int mx, sum, pre, suf;
} seg[4*200005] ;
 
point combine(point lnode, point rnode)
{
    point p;
    p.pre = max(lnode.pre, lnode.sum + rnode.pre);
    p.suf = max(rnode.suf, rnode.sum + lnode.suf);
    p.sum = lnode.sum + rnode.sum;
    p.mx = max({lnode.mx, rnode.mx, lnode.suf + rnode.pre});
    return p;
}
 
void build(int node, int l, int r)
{
    if (l == r) {
        seg[node].mx = seg[node].pre = seg[node].suf = (arr[l] > 0 ? arr[l] : 0);
        seg[node].sum = arr[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);
    seg[node] = combine(seg[2*node], seg[2*node+1]);
}
 
void update(int node, int l, int r, int idx, int val)
{
    if (l == r) {
        seg[node].mx = seg[node].pre = seg[node].suf = (val > 0 ? val : 0);
        seg[node].sum = val;
        return;
    }
    int mid=(l+r)/2;
    if (idx <= mid)
        update(2*node, l, mid, idx, val);
    else
        update(2*node+1, mid+1, r, idx, val);
    seg[node] = combine(seg[2*node], seg[2*node+1]);
}
 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n, q, i;
    cin >> n >> q;
    
    for (i=1;i<=n;i++)
        cin >> arr[i];
    
    build(1, 1, n);
    
    int idx, val;
    while (q--) {
        cin >> idx >> val;
        update(1, 1, n, idx, val);
        cout << seg[1].mx << "\n";
    }
    
    return 0;
}
