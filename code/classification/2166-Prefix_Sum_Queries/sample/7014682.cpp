// competitive programming template
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
 
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
 
class SegmentTree {
public:
 
    int n;
    vector<long long> seg;
    vector<long long> lazy;
    long long ans;
 
    SegmentTree(int n, vector<long long> &leaves) {
        this->n = n;
        seg.resize(n<<2);
        lazy.resize(n<<2);
        build(1, 0, n-1, leaves);
    }
 
    long long query(int l, int r) {
        ans = -1e18;
        query(1, 0, n-1, l, r);
        if(ans == -1e18 || (l-1 < 0)) return ans;
 
        long long tot = ans;
        ans = -1e18;
        query(1, 0, n-1, l-1, l-1);
        return tot - ans;
    }
 
    void update(int pos, long long val) {
        update(1, 0, n-1, pos, n-1, val);
    }
 
    int left(int node) {
        return node<<1;
    }
 
    int right(int node) {
        return node<<1|1;
    }
 
    long long combine(long long a, long long b) {
        return max(a, b);
    }
 
    long long eval(int node) {
        return seg[node] + lazy[node];
    }
 
    void push(int node) {
        lazy[left(node)] += lazy[node];
        lazy[right(node)] += lazy[node];
        lazy[node] = 0;
    }
 
    void build(int node, int tl, int tr, vector<long long> &leaves) {
        if(tl > tr) return;
        if(tl == tr) {
            seg[node] = leaves[tl];
            return;
        }
 
        int mid = (tl+tr) / 2;
        build(left(node), tl, mid, leaves);
        build(right(node), mid+1, tr, leaves);
        seg[node] = combine(eval(left(node)), eval(right(node)));
    }
 
    void update(int node, int tl, int tr, int l, int r, long long val) {
        if((l > tr) || (r < tl)) return;
        if(tl > tr) return;
        if((tl >= l) && (tr <= r)) {
            lazy[node] += val;
            return;
        }
 
        push(node);
 
        int mid = (tl+tr)/2;
        update(left(node), tl, mid, l, r, val);
        update(right(node), mid+1, tr, l, r, val);
        seg[node] = combine(eval(left(node)), eval(right(node)));
    }
 
    void query(int node, int tl, int tr, int l, int r) {
        if((l > tr) || (r < tl)) return;
        if(tl > tr) return;
        if((tl >= l) && (tr <= r)) {
            // cout << "quering: " << node << " " << seg[node] << " " << lazy[node] << endl;
            ans = combine(ans, eval(node));
            return;
        }
 
        push(node);
 
        int mid = (tl+tr)/2;
        query(left(node), tl, mid, l, r);
        query(right(node), mid+1, tr, l, r);
        seg[node] = combine(eval(left(node)), eval(right(node)));
    }
 
};
 
void solve() {
    // code here
    
    int n, m;
    cin >> n >> m;
 
    vector<int> val(n);
    for(int i=0;i<n;i++) cin >> val[i];
 
    vector<long long> presum(n);
 
    presum[0] = val[0];
    for(int i=1;i<n;i++) {
        presum[i] = presum[i-1] + val[i];
    }
 
    // build
    SegmentTree st(presum.size(), presum);
 
    for(int i=0;i<m;i++) {
        int t;
        cin >> t;
        if(t == 1) {
            int pos;
            long long u;
            cin >> pos >> u;
            pos--;
 
            st.update(pos, u-val[pos]);
            val[pos] = u;
        } else {
            int x, y;
            cin >> x >> y;
            x--, y--;
 
            cout << max(0LL, st.query(x, y)) << endl;
        }
    }
 
}
 
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    // get test cases
    int t = 1;
    // cin >> t;
 
    while (t--) {
 
        solve();
    }
 
    return 0;
}
