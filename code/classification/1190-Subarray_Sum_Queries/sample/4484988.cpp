#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 2e5 + 5;
const int segSize = 6e5;
typedef long long ll;
 
struct Node
{
    ll pre, suf, sum, g_max;
    Node(ll a = 0)
    {
        pre = suf = sum = g_max = a;
    }
} st[segSize];
 
int arrSize;
 
int mid(int l, int r)
{
    return (l + r) / 2;
}
 
int left(int node)
{
    return 2 * node;
}
 
int right(int node)
{
    return 2 * node + 1;
}
 
int A[maxn];
 
Node mergeNodes(Node a, Node b)
{
    Node res;
    res.sum = a.sum + b.sum;
    res.suf = max(b.suf, a.suf + b.sum);
    res.pre = max(a.pre, a.sum + b.pre);
    ll temp;
    if (a.suf < 0 || b.pre < 0)
    {
        temp = max(a.suf, b.pre);
    }
    else
        temp = a.suf + b.pre;
 
    res.g_max = max(max(a.g_max, b.g_max), temp);
    return res;
}
 
void build(int node, int l, int r)
{
    if (l == r)
    {
        st[node] = Node(A[l]);
    }
    else
    {
        int m = mid(l, r), ln = left(node), rn = right(node);
        build(ln, l, m), build(rn, m + 1, r);
        st[node] = mergeNodes(st[ln], st[rn]);
    }
}
 
void update(int node, int l, int r, int u, int val)
{
    if (l == r)
    {
        st[node] = Node(val);
    }
    else
    {
        int m = mid(l, r), ln = left(node), rn = right(node);
        if (u <= m)
            update(ln, l, m, u, val);
        else
            update(rn, m + 1, r, u, val);
        st[node] = mergeNodes(st[ln], st[rn]);
    }
}
 
ll query()
{
    return max(st[1].g_max, 0LL);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, m;
    cin >> n >> m;
    arrSize = n; // GLOBAL variable
 
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }
    build(1, 1, n);
    for (int i = 1; i <= m; i++)
    {
        int u, val;
        cin >> u >> val;
        update(1, 1, n, u, val);
        cout << query() << "\n";
    }
}
