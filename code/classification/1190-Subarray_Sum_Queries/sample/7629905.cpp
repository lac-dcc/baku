#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using vll = vector<ll>;
 
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
 
const int mxN = 2e5 + 4;
ll INF = 1e15, mod = 1e9 + 7;
 
ll tree[4*mxN+4][4];
 
void build(int si, int ss, int se, vll &arr)
{
    if (ss == se)
    {
        ll val = arr[ss];
        tree[si][0]=tree[si][1]=tree[si][2]=tree[si][3]=val;
    }
    else
    {
        int sm = (ss + se) >> 1;
        build(2 * si, ss, sm, arr);
        build(2 * si + 1, sm + 1, se, arr);
        tree[si][2] = tree[2 * si][2] + tree[2 * si + 1][2];
        tree[si][0] = max(tree[2 * si][0], tree[2 * si][2] + tree[2 * si + 1][0]);
        tree[si][1] = max(tree[2 * si + 1][1], tree[2 * si + 1][2] + tree[2 * si][1]);
        tree[si][3] = max({tree[2 * si][1] + tree[2 * si + 1][0], tree[2*si][3], tree[2*si+1][3]});
    }
}
 
void update(int si, int ss, int se, int k, ll x)
{
    if (ss == se)
    {
        ll val=tree[si][0];
        tree[si][0]=tree[si][1]=tree[si][2]=tree[si][3]=x;
    }
    else
    {
        int sm = (ss + se) >> 1;
        if (k <= sm)
            update(2 * si, ss, sm, k, x);
        else
            update(2 * si + 1, sm + 1, se, k, x);
        tree[si][2] = tree[2 * si][2] + tree[2 * si + 1][2];
        tree[si][0] = max(tree[2 * si][0], tree[2 * si][2] + tree[2 * si + 1][0]);
        tree[si][1] = max(tree[2 * si + 1][1], tree[2 * si + 1][2] + tree[2 * si][1]);
        tree[si][3] = max({tree[2 * si][1] + tree[2 * si + 1][0], tree[2*si][3], tree[2*si+1][3]});
    }
}
 
int main()
{
    fastio;
    int n, q;
    cin >> n >> q;
    vll arr;
    arr.push_back(-1);
    for (int i = 1; i <= n; i++)
    {
        ll h;
        cin >> h;
        arr.push_back(h);
    }
    build(1, 1, n, arr);
    while (q--)
    {
        int k, x;
        cin >> k >> x;
        update(1, 1, n, k, x);
        arr[k] = x;
        cout << max(0LL, tree[1][3]) << "\n";
    }
}
