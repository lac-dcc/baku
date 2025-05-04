#include<bits/stdc++.h>
#define int long long
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define endl "\n"
#define I ::iterator
#define RI ::reverse_iterator
#define IPR pair<int,int>
#define PQ priority_queue
#define REP(i,n) for(int i=0;i<n;i++)
#define all(v) (v).begin(), (v).end()
#define deb(x) cout<< #x <<" "<< x <<" "<<"\n";
#define ins insert
#define INF LLONG_MAX
using namespace std;
 
const int mxN = 2e5;
int n, q;
int a[mxN];
 
struct node {
	int s, mxl;
} seg[4 * mxN];
 
void upd(int pos, int val, int l = 0, int h = n - 1, int ind = 0) {
	if (l == h) {
		seg[ind].s = seg[ind].mxl = a[l] = val;
		return;
	}
	int m = (l + h) >> 1;
	if (pos <= m)
		upd(pos, val, l, m, ind * 2 + 1);
	else upd(pos, val, m + 1, h, ind * 2 + 2);
	seg[ind].s = seg[ind * 2 + 1].s + seg[ind * 2 + 2].s;
	seg[ind].mxl = max(seg[ind * 2 + 1].mxl, seg[ind * 2 + 1].s + seg[ind * 2 + 2].mxl);
}
 
node qry(int l, int h, int ind = 0, int low = 0, int high = n - 1) {
	if (l <= low && high <= h) {
		return seg[ind];
	}
	if (low > h || high < l || low > high) {
		node res;
		res.s = res.mxl = 0;
		return res;
	}
	int m = (low + high) >> 1;
	node left = qry(l, h, ind * 2 + 1, low, m);
	node right = qry(l, h, ind * 2 + 2, m + 1, high);
	node res;
	res.s = left.s + right.s;
	res.mxl = max(left.mxl, left.s + right.mxl);
	return res;
}
 
void solve() {
	cin >> n >> q;
	for (int i = 0; i < n; ++i)
		cin >> a[i], upd(i, a[i]);
	while (q--) {
		int qt;		cin >> qt;
		if (qt == 1) {
			int k, val;		cin >> k >> val;
			upd(k - 1, val);
		}
		else {
			int l, h;	cin >> l >> h;
			cout << max(0LL, qry(l - 1, h - 1).mxl) << endl;
		}
	}
}
 
 
 
int32_t main()
{
	ios_base::sync_with_stdio(false);	cin.tie(0);	cout.tie(0);
 
	int t = 1;
	// cin >> t;
	while (t--)
		solve();
	return 0;
}
