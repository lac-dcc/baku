#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
 
struct node{
  int prefix, sum;  
};
 
typedef pair<int,int> ppi;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
 
const int mxn = 2e5+1, INF = 1e18+10;
int arr[mxn];
node tree[4*mxn];
 
void build(int pos, int l, int r){
    
    if(l == r){
        tree[pos] = node{arr[l], arr[l]};
        return;
    }
    
    int mid = (l+r)/2;
    build(2*pos, l, mid);
    build(2*pos+1, mid+1, r);
    
    tree[pos].prefix = max(tree[2*pos].prefix, tree[2*pos].sum + tree[2*pos+1].prefix);
    tree[pos].sum = tree[2*pos].sum + tree[2*pos+1].sum;
    
}
 
void update(int pos, int l, int r, int qpos, int x){
    
    if(l == r){
        tree[pos] = node{x, x};
        arr[qpos] = x;
        return;
    }
    
    int mid = (l+r)/2;
    if(qpos <= mid) update(2*pos, l, mid, qpos, x);
    else update(2*pos+1, mid+1, r, qpos, x);
    
    tree[pos].prefix = max(tree[2*pos].prefix, tree[2*pos].sum + tree[2*pos+1].prefix);
    tree[pos].sum = tree[2*pos].sum + tree[2*pos+1].sum;
    
}
 
node query(int pos, int l, int r, int ql, int qr){
    
    if(l > qr || r < ql)
        return node{-INF, 0};
        
    if(ql <= l && r <= qr)
        return tree[pos];
        
    int mid = (l+r)/2;
    node left_node = query(2*pos, l, mid, ql, qr);
    node right_node = query(2*pos+1, mid+1, r, ql, qr);
    
    node res;
    res.prefix = max(left_node.prefix, left_node.sum + right_node.prefix);
    res.sum = left_node.sum + right_node.sum;
    
    return res;
    
}
 
void solve(){
    
    int n, q, type, a, b;
    cin>>n>>q;
    
    for(int i = 1; i<=n; i++)
        cin>>arr[i];
    build(1, 1, n);
    
    while(q--){
        
        cin>>type>>a>>b;
        
        if(type == 1)
            update(1, 1, n, a, b);
            
        else
            cout<<max(0LL, query(1, 1, n, a, b).prefix)<<'\n';
        
    }
    
}
 
int32_t main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    solve();
	
	return 0;
}
