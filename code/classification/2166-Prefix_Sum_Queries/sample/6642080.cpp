//thinhelzan842
#include <bits/stdc++.h>
#define MAX 200005
#define show(x) cout << #x << " = " << x << "\n"
#define el cout << "\n"
#define ll long long
#define all(x) x.begin, x.end()
#define fi first
#define se second
#define oo 100000000000000007
#define NAME "task"
 
using namespace std;
 
#define pii pair<ll, ll>
int n, q;
ll a[MAX];
pii h[4 * MAX] = {};
 
pii merge(pii a, pii b)
{
    return {a.fi + b.fi, max(a.se, a.fi + b.se)};
}
 
void update(int id, int l, int r, int i, int x)
{
    if (i < l || r < i) return;
    if (l == r)
    {
        h[id] = {x, x};
        return;
    }
    int mid = (l + r) / 2;
    update(2 * id, l, mid, i, x);
    update(2 * id + 1, mid + 1, r, i, x);
    h[id] = merge(h[2 * id], h[2 * id + 1]);
}
 
pii get(int id, int l, int r, int u, int v)
{
    if (l > v || r < u) return {0LL, 0LL};
    if (u <= l && r <= v) return h[id];
    int mid = (l + r) / 2;
    pii left = get(2 * id, l, mid, u, v);
    pii right = get(2 * id + 1, mid + 1, r, u, v);
    return merge(left, right);
}
 
int main()
{
    if(fopen(NAME".inp", "r"))
    {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
 
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        update(1, 1, n, i, a[i]);
    }
 
    while (q--)
    {
        int k;
        cin >> k;
        if (k & 1)
        {
            int i, x;
            cin >> i >> x;
            a[i] = x;
            update(1, 1, n, i, x);
        }
        else 
        {
            int u, v;
            cin >> u >> v;
            cout << max(0LL, get(1, 1, n, u, v).se) << "\n";       
        }
    }
 
    return 0;
}
