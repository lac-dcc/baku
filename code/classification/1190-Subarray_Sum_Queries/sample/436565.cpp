//
// Created by Yanir on 12/05/2020.
//
#include <bits/stdc++.h>
 
using namespace std;
#define maxn 200000
#define mid(a, b) ((a) + (b)) >> 1
#define int int64_t
struct node {
    int sum, maxSum, start, end;
};
 
node merge(node& n1, node& n2) {
    int sum = n1.sum + n2.sum;
    int start = max(n1.start, n1.sum + n2.start);
    int end = max(n2.end, n2.sum + n1.end);
    int maxSum = max(n1.end + n2.start, max(n1.maxSum, n2.maxSum));
    return {
            sum, maxSum, start, end
    };
}
 
node tree[maxn << 2];
int arr[maxn];
int n;
 
void build(int v = 1, int l = 0, int r = n - 1) {
    if (l == r) {
        int cur = arr[l];
        tree[v] = {cur, cur, cur, cur};
    } else {
        int m = mid(l, r), twov = v << 1;
        build(twov, l, m);
        build(twov + 1, m + 1, r);
        tree[v] = merge(tree[twov],tree[twov+1]);
    }
}
void update(int i, int newV, int v = 1, int l = 0, int r = n-1) {
    if(l == r) {
        tree[v] = {newV,newV,newV,newV};
    } else {
        int m = mid(l, r), twov = v << 1;
        if(i <= m) {
            update(i,newV,twov,l,m);
        } else {
            update(i,newV,twov+1,m+1,r);
        }
        tree[v] = merge(tree[twov],tree[twov+1]);
    }
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    build();
    while(m--) {
        int k,x;
        cin >> k >> x;
        update(k-1,x);
        int res = tree[1].maxSum;
        res = res > 0 ? res : 0;
        cout << res << '\n';
    }
    return 0;
}
