// Question link - https://cses.fi/problemset/task/2166/
#include <iostream>
using namespace std;
#define int long long
 
struct node
{
    int pre;
    int sum;
};
 
void update(node *tree, int p, int s, int e, int updInd, int val)
{
    if(e < updInd || s > updInd)
        return;
    if (s == e)
    {
        tree[p].pre = val;
        tree[p].sum = val;
        return;
    }
    int mid = s + (e - s) / 2;
    update(tree, 2 * p, s, mid, updInd, val);
    update(tree, 2 * p + 1, mid + 1, e, updInd, val);
    tree[p].pre = max(tree[2 * p].pre, tree[2 * p].sum + tree[2 * p + 1].pre);
    tree[p].sum = tree[2 * p].sum + tree[2 * p + 1].sum;
}
 
node query(node *tree, int p, int s, int e, int l, int r)
{
    if (l > e || r < s)
    {
        node r;
        r.pre = 0;
        r.sum = 0;
        return r;
    }
    if (l <= s && e <= r)
    {
        return tree[p];
    }
    int mid = s + (e - s) / 2;
    node ans1 = query(tree, 2 * p, s, mid, l, r);
    node ans2 = query(tree, 2 * p + 1, mid + 1, e, l, r);
    node ans;
    ans.pre = max(ans1.pre, ans1.sum + ans2.pre);
    ans.sum = ans1.sum + ans2.sum;
    return ans;
}
void build(int *a, node *tree, int p, int s, int e)
{
    if (s == e)
    {
        tree[p].pre = a[s];
        tree[p].sum = a[s];
        return;
    }
    int mid = s + (e - s) / 2;
    build(a, tree, 2 * p, s, mid);
    build(a, tree, 2 * p + 1, mid + 1, e);
    tree[p].pre = max(tree[2 * p].pre, tree[2 * p].sum + tree[2 * p + 1].pre);
    tree[p].sum = tree[2 * p].sum + tree[2 * p + 1].sum;
}
 
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        // freopen("out", "w", stdout);
    #endif
 
    int n;
    cin >> n;
    int q;
    cin >> q;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    node *tree = new node[4 * n];
    build(arr, tree, 1, 0, n - 1);
    while (q--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
            update(tree, 1, 0, n - 1, b - 1, c);
        else
            cout << max(0LL, query(tree, 1, 0, n - 1, b - 1, c - 1).pre) << endl;
    }
}
