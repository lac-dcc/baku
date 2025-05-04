#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pqueue priority_queue
#define pb push_back
#define F first
#define S second
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) a = (a > b ? a : b)
#define cmin(a, b) a = (a < b ? a : b)
#define put(x) cout << x << endl;
#define putarr(x) for(int i = 0; i < sizeof(x); i++) cout << x[i] << (" \n")[i == sizeof(x) - 1]; 
#define all(v) v.begin(), v.end()
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x &(-x)
#if !LOCAL
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f;
const int P = 1e9+7;
 
using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
int x[MAXN];
 
struct Node {
	int l, r, sum, pre, suf, mx;
} seg[MAXN << 2];
 
void pull(int id) {
	seg[id].sum = seg[id * 2].sum + seg[id * 2 + 1].sum;
	seg[id].pre = max(seg[id * 2].pre, seg[id * 2].sum + seg[id * 2 + 1].pre);
	seg[id].suf = max(seg[id * 2 + 1].suf, seg[id * 2 + 1].sum + seg[id * 2].suf);
	seg[id].mx = max(seg[id * 2].suf + seg[id * 2 + 1].pre, max(seg[id * 2].mx, seg[id * 2 + 1].mx));
	return;
}
 
void build(int id, int l, int r) {
	seg[id].l = l, seg[id].r = r;
	if (l == r) {
		seg[id] = {l, r, x[l], max(0, x[l]), max(0, x[l]), max(0, x[l])};
		return;
	}
	int mid = (l + r) / 2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	pull(id);
}
 
void update(int id, int pos, int val) {
	int l = seg[id].l, r = seg[id].r;
	if (l > pos || r < pos) return;
	if (l == r) {
		x[l] = val;
		seg[id] = {l, r, x[l], max(0, x[l]), max(0, x[l]), max(0, x[l])};
		return;
	}
	update(id * 2, pos, val);
	update(id * 2 + 1, pos, val);
	pull(id);
}
 
Node query(int id, int ql, int qr) {
	int l = seg[id].l, r = seg[id].r;
	if (l > qr || r < ql) return {l, r, -INF, -INF, -INF, -INF};
	if (ql <= l && r <= qr) {
		return seg[id];
	}
	Node q1 = query(id * 2, ql, qr);
	Node q2 = query(id * 2 + 1, ql, qr);
	Node tmp = {q1.l, q2.r, q1.sum + q2.sum, max(q1.pre, q1.sum + q2.pre), max(q2.suf, q2.sum + q1.suf), max(q1.suf + q2.pre, max(q1.mx, q2.mx))};
	return tmp;
}
 
void sol()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> x[i];
	build(1, 1, n);
	int k, x;
	while (m--) {
		cin >> k >> x;
		update(1, k, x);
		cout << query(1, 1, n).mx << endl;
	}
}
 
signed main()
{
    Weakoying;
    int t = 1;
    //while (cin >> t)
    {
    	while (t--)
        {
            sol();
        }
    }
        
    return 0;
}
