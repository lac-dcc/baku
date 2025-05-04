#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node {
    ll sum, pref;
    node(){}
    node(ll s,ll p){
        sum = s;
        pref = p;
    }
};
template <class T>
struct SegmentTree{
    int N;
    vector<T> tree;
    SegmentTree(vector<T> &A): N (A.size()){
        tree.resize(4*N);
        build(1,0,N-1,A);
    }
    T merge(T a,T b){ // !
        return T(a.sum+b.sum,max(a.pref,a.sum+b.pref));
    }
    void build(int no,int l,int r,vector<T> &A){
        if (l == r){
            tree[no] = A[l];
            return;
        }
        build(no<<1,l,(l+r)/2,A);
        build(no<<1|1,(l+r)/2+1,r,A);
        tree[no] = merge(tree[no<<1],tree[no<<1|1]);
    }
    T query(int i,int j){
        return query(1,0,N-1,i,j);
    }
    T query(int no,int l,int r,int i,int j){
        if (i <= l && r <= j) return tree[no];
        int mid = (l+r)/2;
        if ( mid < i || j < l ) return query(no<<1|1,mid+1,r,i,j);
        if (r < i || j < mid+1) return query(no<<1,l,mid,i,j);
        return merge(query(no<<1,l,mid,i,j),query(no<<1|1,mid+1,r,i,j));
    }
    void update(int i,T val){
        update(1,0,N-1,i,val);
    }
    void update(int no,int l,int r,int i,T val){
        if (i < l || r < i) return;
        if (l == r){
            tree[no] = val;
            return;
        }
        update(no<<1,l,(l+r)/2,i,val);
        update(no<<1|1,(l+r)/2+1,r,i,val);
        tree[no] = merge(tree[no<<1],tree[no<<1|1]);
    }
};
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q;
    cin>>n>>q;
    vector<node> x(n);
    for (int i=0;i<n;i++){
        cin>>x[i].sum;
        x[i].pref = max(x[i].sum,0LL);
    }
    SegmentTree<node> st(x);
    while (q--){
        int t;
        cin>>t;
        if (t == 1){
            int k,u;
            cin>>k>>u;
            st.update(k-1,node(u,max(u,0)));
        } else {
            int a,b;
            cin>>a>>b;
            cout<<st.query(a-1,b-1).pref<<'\n';
        }
    }
    return 0;
}
