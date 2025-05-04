#include <bits/stdc++.h>
using namespace std;
 
#define ssize(c) static_cast<int>(c.size())
 
using ll = long long;
 
struct Node {
    ll best, start, end, total;
 
    Node(int n) {
        if(n>0){
            best=n;
            start=n;
            end=n;
            total=n;
        } else {
            best=0;
            start=0;
            end=0;
            total=n;
        }
    }
    Node(ll a, ll b, ll c, ll d) {
        best=a;
        start=b;
        end=c;
        total=d;
    }
 
    friend ostream& operator << (ostream& os, const Node& n) {
        os << n.best;
        return os;
    }
};
 
struct SegmentTree {
    Node unit{0, 0, 0, 0};
    Node merge(Node a, Node b) {
        return {
            max(a.end+b.start, max(a.best, b.best)),
            max(a.start, a.total+b.start),
            max(b.end, a.end+b.total),
            a.total+b.total
        };
    }
 
    int n_po2;
    vector<Node> st;
 
    SegmentTree(vector<int> data)
    {
        n_po2 = 1;
        while(n_po2 < ssize(data)) n_po2 *= 2;
        st.assign(2 * n_po2, unit);
 
        for(int i = 0; i < ssize(data); i++)
            st[i + n_po2] = Node{data[i]};
 
        for(int i = n_po2-1; i > 0; i--)
            st[i] = merge(st[2*i], st[2*i+1]);
    }
    // [x, y]
    Node query(int x, int y)
    {
        Node left = unit, right = unit;
        for(x += n_po2, y += n_po2 + 1; x < y; x /= 2, y /= 2)
        {
            if(x&1) left = merge(left, st[x++]);
            if(y&1) right = merge(st[--y], right);
        }
        return merge(left, right);
    }
    void update(int p, int v)
    {
        p += n_po2;
        st[p] = Node{v};
        for(p /= 2; p > 0; p /= 2)
            st[p] = merge(st[2*p], st[2*p+1]);
    }
};
 
int main() {
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin);
    #endif
    
    int n, m; cin >>n>>m;
    vector<int> a(n);
    for(int i=(0); i<(n); ++i) cin>>a[i];
 
    SegmentTree tree(a);
 
    while(m--) {
        int i, v; cin >>i>>v;
        tree.update(i-1, v);
        cout <<tree.query(0, tree.st.size()/2-1)<<"\n";
    }
}
