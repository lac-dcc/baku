#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <fstream>
#include <chrono>
#include <random>
#include <cstring>
#include <cmath>
#include <set>
#include <iomanip>
#include  <queue>
#include <stack>
using namespace std;
long long n,m,q;
const int maxn = 2e5;
struct item
{
    long long ans, sum;
};
item seg[4*maxn+5];
item combine(item x, item y)
{
    item z;
    z.sum = x.sum + y.sum;
    z.ans = max({x.ans,x.sum+y.ans});
    return z;
}
long long a[maxn+5];
 
void update(int node, int l, int r, int idx, long long x)
{
    if(l > idx || r < idx) return;
    if(l == r)
    {
        seg[node].sum = x;
        seg[node].ans = max(0ll,x);
        return;
    }
    int mid = (l+r)/2;
    update(node*2,l,mid,idx,x);
    update(node*2+1,mid+1,r,idx,x);
    seg[node] = combine(seg[node*2],seg[node*2+1]);
}
item query(int node, int l, int r,int u, int v)
{
    if(l > v || r < u) return {0,0};
    if(u <= l && r <= v) return seg[node];
    int mid = (l+r)/2;
    item le = query(node*2,l,mid,u,v);
    item ri = query(node*2+1,mid+1,r,u,v);
    return combine(le,ri);
}
void solve()
{
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> a[i], update(1,1,n,i,a[i]);
    for(int i = 1; i <= q; i++)
    {
        int op,l,r;
        cin >> op >> l >> r;
        if(op==2)
        {
            cout << query(1,1,n,l,r).ans << '\n';
        }
        else
        {
            update(1,1,n,l,r);
        }
 
    }
 
 
 
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
