#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <vector>
#include <math.h>
#include <queue>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <numeric>
#include <tuple>
 
using namespace std;
 
#define int long long
 
#define pii pair<int, int>
 
struct SegmentTree {
    int n;
    vector<int> a;
    vector<int> pre, sum;
 
    SegmentTree(int n, vector<int> &a) {
        this->n = n;
        this->a = a;
        pre.resize(4*n+5, 0);
        sum.resize(4*n+5, 0);
        build(1, 0, n-1);
    }
 
    void build(int v, int tl, int tr) {
        if(tl == tr) {
            pre[v] = a[tl];
            sum[v] = a[tl];
        } else {
            int tm = (tl + tr)/2;
            build(v*2, tl, tm);
            build(v*2+1, tm+1, tr);
            pre[v] = max(pre[2*v], sum[2*v] + pre[2*v+1]);
            sum[v] = sum[v*2] + sum[v*2+1];
        }
    }
 
    void update(int v, int tl, int tr, int pos, int val) {
        if(tl == tr) {
            pre[v] = val;
            sum[v] = val;
        } else {
            int tm = (tl + tr)/2;
            if(pos <= tm) {
                update(v*2, tl, tm, pos, val);
            } else {
                update(v*2 + 1, tm+1, tr, pos, val);
            }
            pre[v] = max(pre[2*v], sum[2*v] + pre[2*v+1]);
            sum[v] = sum[v*2] + sum[v*2+1];
        }
    }
 
    pii get(int v, int tl, int tr, int l, int r) {
        if(l > r) {
            return {0, 0};
        }
        if(tl == l && tr == r) {
            return {pre[v], sum[v]};
        } 
 
        int tm = (tl + tr)/2;
 
        pii left = get(v*2, tl, tm, l, min(r, tm));
        pii right = get(v*2+1, tm+1, tr, max(tm+1,l), r);
 
        return {max(left.first, left.second + right.first), left.second + right.second};
    }
};
 
void solve() {
    int n, q; cin >> n >> q;
 
    vector<int> a(n);
    int sum = 0;
 
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
 
    SegmentTree segTree(n, a);
 
    int k, x;
 
    int val;
 
    while(q--) {
        cin >> val;
        if(val == 1) {
            cin >> k >> x;
            segTree.update(1, 0, n-1, k-1, x);
        } else {
            cin >> k >> x;
            pii ans = segTree.get(1, 0, n-1, k-1, x-1);
            cout << max(0LL, ans.first) << endl;
        }
    }
}
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 
    int t=1;
    // cin >> t;
 
    while(t--) {
        solve();
    }
}
