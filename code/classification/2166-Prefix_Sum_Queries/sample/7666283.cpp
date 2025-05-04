#include <bits/stdc++.h>
using namespace std;
 
const int MAX = 200005;
class Node {
    public:
    long pre, sum;
};
 
long arr[MAX];
Node seg[MAX*4];
 
void build(int node, int l, int r) {
    if(l==r) {
        seg[node].pre = max(0L, arr[l]);
        seg[node].sum = arr[l];
        return;
    }
    int m = l + (r-l)/2;
    int left = 2*node+1;
    int right= 2*node+2;
    build(left,    l, m);
    build(right, m+1, r);
 
    seg[node].sum = seg[left].sum+seg[right].sum;
    seg[node].pre = max(seg[left].pre, seg[left].sum+seg[right].pre);
}
 
Node query(int node, int l, int r, int L, int R) {
    //cout<<l<<r<<endl;
    if(R<l || r<L) {
        Node node;
        node.pre = 0;
        node.sum = 0;
        return node;
    }
    if(L <= l && r <= R) {
        return seg[node];
    }
    int m = l + (r-l)/2;
 
    Node left  = query(2*node+1,   l, m, L, R);
    Node right = query(2*node+2, m+1, r, L, R);
    Node nnode;
    nnode.sum = left.sum + right.sum;
    nnode.pre = max(left.pre, left.sum + right.pre);
    return nnode;
}
 
void update(int node, int l, int r, int i, int v) {
    if(l==r && l==i) {
        arr[l] = v;
        seg[node].pre = max(v, 0);
        seg[node].sum = v;
        return;
    }
 
    if(r<i || i<l) return;
 
    int m = l + (r-l)/2;
    int left = 2*node+1;
    int right= 2*node+2;
    update(left,    l, m, i ,v);
    update(right, m+1, r, i, v);
 
    seg[node].sum = seg[left].sum+seg[right].sum;
    seg[node].pre = max(seg[left].pre, seg[left].sum+seg[right].pre);
}
 
int main() {
    int n, m;
    cin>>n>>m;
    for(int i=0; i<n; i++) cin>>arr[i];
    build(0, 0, n-1);
    for(int i=0; i<m; i++) {
        int c,a,b;
        cin>>c>>a>>b;
        if(c==1) {
            update(0, 0, n-1, a-1, b);
        } else {
            cout<<query(0, 0, n-1, a-1, b-1).pre<<endl;
        }
    }
}
