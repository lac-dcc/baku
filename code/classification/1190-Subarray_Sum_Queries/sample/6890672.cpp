#include <iostream>
 
using namespace std;
 
struct Node {
 
    long long tot, le, ri, su;
 
    Node operator+(Node p) {
        return {max(max(tot, p.tot), ri+p.le),
                max(le, su+p.le),
                max(p.ri, p.su+ri),
                su+p.su};
    }
 
};
 
Node segtree[800005];
long long arr[200005];
const long long xd = 0;
long long n;
 
void build(long long node = 1, long long tl = 1, long long tr = n) {
 
    if(tl == tr) {
        segtree[node] = {max(xd, arr[tl]), max(xd, arr[tl]), max(xd, arr[tl]), arr[tl]};
    }
    else {
        long long m = (tl+tr)/2;
 
        build(node*2, tl, m);
        build(node*2+1, m+1, tr);
 
        segtree[node] = segtree[node*2]+segtree[node*2+1];
    }
}
 
void update(long long pos, long long val) {
 
    long long tl = 1;
    long long tr = n;
    long long node = 1;
    long long m;
 
    while(tl < tr) {
 
        m = (tl+tr)/2;
 
        if(pos > m) {
            tl = m+1;
            node = node*2+1;
        }
        else {
            tr = m;
            node*=2;
        }
    }
 
    segtree[node] = {max(xd, val), max(xd, val), max(xd, val), val};
    node/=2;
 
    while(node > 0) {
        segtree[node] = segtree[node*2]+segtree[node*2+1];
        node/=2;
    }
}
 
int main() {
 
    long long m, x, y;
 
    cin >> n >> m;
 
    for(long long i=1; i<=n; i++) {
        cin >> arr[i];
    }
 
    build();
 
    for(long long i=0; i<m; i++) {
        cin >> x >> y;
 
        update(x, y);
 
        cout << segtree[1].tot << "\n";
    }
}
