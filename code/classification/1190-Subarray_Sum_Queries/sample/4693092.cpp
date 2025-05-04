#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
class ds {
    public:
    int msum, psum, ssum, csum;
    ds(int val = 0) {
        csum = val;
        psum = ssum = msum = max(0ll, val);
    }
};
 
ds f(ds a, ds b) {
    ds c;
    c.csum = a.csum + b.csum;
    c.psum = max(a.psum, a.csum + b.psum);
    c.ssum = max(b.ssum, b.csum + a.ssum);
    c.msum = max({a.msum, b.msum, a.ssum+b.psum});
 
    return c;
}
 
template <typename T, T (*func) (T, T)>
class SegTree {
    pair<int, int> range;
    T data;
    SegTree *left, *right;
  public:
    SegTree(vector<T> &A, pair<int, int> R) {
        range = R;
        if(R.first == R.second) { data = A[R.first]; left = right = NULL; }
        else {
            int mid = (R.first + R.second) / 2;
            left = new SegTree(A, {R.first, mid});
            right = new SegTree(A, {mid+1, R.second});
            data = func(left->data, right->data);
        }
    }
 
    void update(int idx, T val) {
        if(range.first == range.second) {
            data = val;
            return;
        }
        int mid = (range.first + range.second) / 2;
        if(idx > mid) right->update(idx, val);
        else left->update(idx, val);
        data = func(left->data, right->data);
    }
 
    T query(pair<int, int> R) {
        if(range == R) return data;
        int mid = (range.first + range.second) / 2;
        if(R.first > mid) return right->query(R);
        else if(R.second <= mid) return left->query(R);
        return func(left->query({R.first, mid}), right->query({mid+1, R.second}));
    }
};
 
signed main() {
    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    for(int i=0; i<n; i++) cin >> A[i];
    vector<ds> a(n);
    for(int i=0; i<n; i++) a[i] = ds(A[i]);
    SegTree<ds, f> AA(a, {0, n-1});
    while(m--) {
        int k, x;
        cin >> k >> x;
        k--;
        AA.update(k, ds(x));
        cout<<AA.query({0, n-1}).msum<<endl;
    }
}
