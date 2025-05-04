#include <bits/stdc++.h>
 
// Importing header files
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
 
// Declaring Ordered Set
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update>
    pbds;
 
using namespace std;
using vi = vector<long long>;
 
#define ll long long
#define pb push_back
#define F first
#define S second
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
 
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;
const ll INF = 1e18;
const ll NINF = -INF;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};    
 
// Segment
struct Segment {
    // 左子序列最大值, 右子序列最大值, 所有序列最大值,和
    ll lmx, rmx,mx, sum;
}seg[maxn*4];
 
ll a[maxn];
 
int md (int l, int r) {
    return (l + r) / 2;
}
 
void build (int l, int r, int v) {
    if (l == r) {
        seg[v].lmx = a[l] > 0 ? a[l] : 0;
        seg[v].rmx = a[l] > 0 ? a[l] : 0; 
        seg[v].mx = a[l] > 0 ? a[l] : 0; 
        seg[v].sum = a[l];
        return;
    }
 
    int mid = md (l, r);
    build (l, mid, v*2);
    build (mid+1, r, v*2+1);
    // 和
    seg[v].sum = seg[v*2].sum + seg[v*2+1].sum;
    // 左子序列最大值 MAX 左子樹的左子序列最大值 VS 左子樹的和 加 右子樹的左子序列最大值
    seg[v].lmx = max(seg[v*2].lmx, seg[v*2].sum + seg[v*2+1].lmx);
    // 右子序列最大值 MAX 右子樹的右子序列最大值 VS 右子樹的和 加 左子樹的右子序列最大值
    seg[v].rmx = max(seg[v*2+1].rmx, seg[v*2+1].sum + seg[v*2].rmx);
    // 所以序列: 中間的序列
    seg[v].mx = max(seg[v*2].rmx + seg[v*2+1].lmx, max(seg[v*2].mx, seg[v*2+1].mx));
}
 
Segment query (int l, int r, int L, int R, int v) {
    if (l == L && r == R) {
        return seg[v];
    }
 
    int mid = md (L, R);
    if (l > mid) {
        return query (l, r, mid+1, R, v*2+1);
    } else if (r <= mid) {
        return query (l, r, L, mid, v*2);
    } else {
        Segment lSeg = query(l, mid, L, mid, v*2);
        Segment rSeg = query (mid+1, r, mid+1, R, v*2+1);
        Segment curSeg;
        curSeg.sum = lSeg.sum + rSeg.sum;
        curSeg.lmx = max(lSeg.lmx, lSeg.sum + rSeg.lmx);
        curSeg.rmx = max(rSeg.rmx, rSeg.sum + lSeg.rmx);
        curSeg.mx = max(lSeg.rmx + rSeg.lmx, max(lSeg.mx, rSeg.mx));
        return curSeg;
    }
}
 
void update (int pos, ll val, int l, int r, int v) {
    if (l == r) {
        seg[v].lmx = val > 0 ? val : 0;
        seg[v].rmx = val > 0 ? val : 0;
        seg[v].mx = val > 0 ? val : 0;
        seg[v].sum = val;
        return;
    }
 
    int mid = md (l, r);
    if (pos <= mid) {
        update (pos, val, l, mid, v*2);
    } else {
        update (pos, val, mid+1, r, v*2+1);
    }
 
    seg[v].sum = seg[v*2].sum + seg[v*2+1].sum;
    seg[v].lmx = max(seg[v*2].lmx, seg[v*2].sum + seg[v*2+1].lmx);
    seg[v].rmx = max(seg[v*2+1].rmx, seg[v*2+1].sum + seg[v*2].rmx);
    seg[v].mx = max(seg[v*2].rmx + seg[v*2+1].lmx, max(seg[v*2].mx, seg[v*2+1].mx));
}
 
void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
 
    build(1, n, 1);
 
    while (q--) {
        int a, b;
        cin >> a >> b;
        update(a, b, 1, n, 1);
        // Segment allSeg = query(1, n, 1, n, 1);
        // cout << allSeg.rmx << ' ';
        cout << seg[1].mx << '\n';
    }
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
 
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
 
    return 0;
}
 
