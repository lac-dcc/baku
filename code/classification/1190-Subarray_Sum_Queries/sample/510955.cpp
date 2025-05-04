#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<ll,int> pii;
 
ll arr[200000], tree[800000], ml[800000], mr[800000], sum[800000];
 
void build(int v, int l, int r)
{
    if (l == r) {
        tree[v] = ml[v] = mr[v] = max(0LL, sum[v] = arr[l]);
    } else {
        build(v * 2, l, (l + r) / 2);
        build(v * 2 + 1, (l + r) / 2+1, r);
        sum[v] = sum[v * 2] + sum[v * 2 + 1];
        ml[v] = max(sum[v * 2] + ml[v * 2 + 1], ml[v * 2]);
        mr[v] = max(sum[v * 2 + 1] + mr[v * 2], mr[v * 2 + 1]);
        tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
        tree[v] = max(tree[v], ml[v * 2 + 1] + mr[v * 2]);
    }
}
 
void upd(int v, int l, int r, int i)
{
    if (l > i || r < i)
        return;
    if (l == r)
        tree[v] = ml[v] = mr[v] = max(0LL, sum[v] = arr[l]);
    else {
        upd(v * 2, l, (l + r) / 2, i);
        upd(v * 2 + 1, (l + r) / 2+1, r, i);
        sum[v] = sum[v * 2] + sum[v * 2 + 1];
        ml[v] = max(sum[v * 2] + ml[v * 2 + 1], ml[v * 2]);
        mr[v] = max(sum[v * 2 + 1] + mr[v * 2], mr[v * 2 + 1]);
        tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
        tree[v] = max(tree[v], ml[v * 2 + 1] + mr[v * 2]);
    }
}
 
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    build(1, 0, n-1);
    while (m--) {
        int k, x;
        cin >> k >> x;
        arr[--k] = x;
        upd(1, 0, n-1, k);
        cout << tree[1] << "\n";
    }
 
    return 0;
}
