/// Source : https://cses.fi/problemset/task/2166/
/// Author : liuyubobobo
/// Time   : 2021-07-17
 
#include <iostream>
#include <vector>
#include <cassert>
 
using namespace std;
 
 
/// Segment Tree Modified
/// Time Complexity: init:   O(nlogn)
///                  update: O(logn)
///                  query:  O(logn)
/// Space Complexity: O(n)
class SegmentTree{
 
private:
    int n;
    vector<long long> data, sumtree, pretree;
 
public:
    SegmentTree(const vector<long long>& data): n(data.size()), data(data), sumtree(4 * n, 0ll), pretree(4 * n, 0ll){
        buildSegTree(0, 0, n - 1);
    }
 
    void update(int index, long long value){
        data[index] = max(0ll, value);
        update(0, 0, n - 1, index, value);
    }
 
    long long query(int l, int r){
        return query_pre(0, 0, n - 1, l, r);
    }
 
private:
    void buildSegTree(int treeID, int l, int r){
 
        if(l == r){
            sumtree[treeID] = data[l];
            pretree[treeID] = max(0ll, data[l]);
            return;
        }
 
        int mid = (l + r) / 2;
        buildSegTree(treeID * 2 + 1, l, mid);
        buildSegTree(treeID * 2 + 2, mid + 1, r);
        sumtree[treeID] = sumtree[treeID * 2 + 1] + sumtree[treeID * 2 + 2];
        pretree[treeID] = max(pretree[treeID * 2 + 1], sumtree[treeID * 2 + 1] + pretree[treeID * 2 + 2]);
        pretree[treeID] = max(pretree[treeID], 0ll);
        return;
    }
 
    void update(int treeID, int l, int r, int index, long long value){
 
        if(l == r){
            assert(l == index);
            sumtree[treeID] = value;
            pretree[treeID] = max(0ll, value);
            return;
        }
 
        int mid = (l + r) / 2;
        if(index <= mid) update(treeID * 2 + 1, l, mid, index, value);
        else update(treeID * 2 + 2, mid + 1, r, index, value);
 
        sumtree[treeID] = sumtree[treeID * 2 + 1] + sumtree[treeID * 2 + 2];
        pretree[treeID] = max(pretree[treeID * 2 + 1], sumtree[treeID * 2 + 1] + pretree[treeID * 2 + 2]);
        pretree[treeID] = max(pretree[treeID], 0ll);
        return;
    }
 
    long long query_sum(int treeID, int l, int r, int ql, int qr){
 
        if(ql == l && qr == r)
            return sumtree[treeID];
 
        int mid = (l + r) / 2;
        if(qr <= mid) return query_sum(treeID * 2 + 1, l, mid, ql, qr);
        else if(ql > mid) return query_sum(treeID * 2 + 2, mid + 1, r, ql, qr);
 
        long long resl = query_sum(treeID * 2 + 1, l, mid, ql, mid);
        long long resr = query_sum(treeID * 2 + 2, mid + 1, r, mid + 1, qr);
        return resl + resr;
    }
 
    long long query_pre(int treeID, int l, int r, int ql, int qr){
 
        if(ql == l && qr == r)
            return pretree[treeID];
 
        int mid = (l + r) / 2;
        if(qr <= mid) return query_pre(treeID * 2 + 1, l, mid, ql, qr);
        else if(ql > mid) return query_pre(treeID * 2 + 2, mid + 1, r, ql, qr);
 
        long long resl = query_pre(treeID * 2 + 1, l, mid, ql, mid);
        long long resr = query_pre(treeID * 2 + 2, mid + 1, r, mid + 1, qr);
        long long lsum = query_sum(treeID * 2 + 1, l, mid, ql, mid);
        return max(resl, lsum + resr);
    }
};
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, q; cin >> n >> q;
 
    vector<long long> arr(n);
    for(int i = 0; i < n; i ++) cin >> arr[i];
 
    SegmentTree seg_tree(arr);
 
    int k, a, b;
    while(q --){
        cin >> k >> a >> b;
        if(k == 1){
            a --;
            seg_tree.update(a, b);
        }
        else{
            a --, b --;
            cout << seg_tree.query(a, b) << '\n';
        }
    }
 
    return 0;
}
