#pragma GCC optimize ("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
class Node{
public:
    int totalSum;
    int prefSum;
    int suffSum;
    int maxSum;
 
    Node(){
        this -> totalSum = 0;
        this -> prefSum = 0;
        this -> suffSum = 0;
        this -> maxSum = 0;
    }
};
 
vector<int> a;
vector<Node> seg;
 
void lessCode(Node &res, Node &node1, Node &node2){
    res.maxSum = max(node1.maxSum, max(node2.maxSum, node1.suffSum + node2.prefSum));
    res.prefSum = max(node1.prefSum, node1.totalSum + node2.prefSum);
    res.suffSum = max(node1.suffSum + node2.totalSum, node2.suffSum);
    res.totalSum = node1.totalSum + node2.totalSum;
}
 
void build(int id, int l, int r){
    if(r - l == 1){
        seg[id].maxSum = a[l];
        seg[id].prefSum = a[l];
        seg[id].suffSum = a[l];
        seg[id].totalSum = a[l];
        return;
    }
    int mid = (r + l) / 2;
    build(2*id, l, mid);
    build(2*id + 1, mid, r);
 
    lessCode(seg[id], seg[2*id], seg[2*id + 1]);
}
 
void update(int k, int u, int id, int l, int r){
    if(r - l == 1){
        seg[id].maxSum = u;
        seg[id].prefSum = u;
        seg[id].suffSum = u;
        seg[id].totalSum = u;
        return;
    }
 
    int mid = (r + l) / 2;
    if(k < mid)
        update(k, u, 2 * id, l, mid);
    else
        update(k, u, 2 * id + 1, mid, r);
 
    lessCode(seg[id], seg[2*id], seg[2*id + 1]);
}
 
Node query(int x, int y, int id, int l, int r){
    Node ans;
    if(l >= y || r <= x)
        return ans;
 
    else if(l >= x and r <= y) return seg[id];
 
    int mid = (l + r) / 2;
    Node l_ans = query(x, y, 2 * id, l, mid);
    Node r_ans = query(x, y, 2 * id + 1, mid, r);
 
    lessCode(ans, l_ans, r_ans);
    return ans;
}
 
void solve(){
    int n, q; cin >> n >> q;
    a.resize(n);
    for(auto &x : a) cin >> x;
 
    seg.resize(4*n + 1);
    build(1, 0, n); // root node
 
    while(q--){
        int x, y;
        cin >> x >> y;
        x--;
        update(x, y, 1, 0, n);
        cout << max(0LL, query(0, n, 1, 0, n).maxSum) << "\n";
    }
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int tc = 1;
    while(tc--)
        solve();
}
