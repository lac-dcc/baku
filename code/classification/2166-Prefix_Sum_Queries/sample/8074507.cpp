#include<iostream>
#include<stdio.h>
#include<math.h>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<string.h>
#include<utility>
#include<set>
#include<cmath>
#include<queue>
#include<deque>
#include<functional>
#include<stack>
#include<limits.h>
#include<iomanip>
#include<unordered_map> 
#include<numeric>
#include<tuple>
using namespace std;
 
#define MOD 1000000007
#define int long long
#define endl '\n'
int cur;
const int mxN=1e6+1;
vector<int> a(mxN),sum(mxN),tree(mxN);
void build(int node, int l, int r){
    if(l==r){
        sum[node]=a[l];
        tree[node]=max(0ll,a[l]);
        return;
    }
    build(node*2,l,(l+r)/2);
    build(node*2+1,(l+r)/2+1,r);
    sum[node]=sum[node*2]+sum[node*2+1];
    tree[node]=max(tree[node*2],sum[node*2]+tree[node*2+1]);
}
int cal(int node, int L, int R, int l, int r){
    if(L>r||R<l) return 0;
    if(L>=l&&R<=r){
        cur+=sum[node];
        return (cur-sum[node])+tree[node];
    }
    int f=cal(node*2,L,(L+R)/2,l,r);
    int s=cal(node*2+1,(L+R)/2+1,R,l,r);
    return max(f,s);
}
void up(int node, int L, int R, int l, int r, int v){
    if(L>r||R<l) return;
    if(L>=l&&R<=r){
        sum[node]=v;
        tree[node]=max(0ll,v);
        return;
    }
    up(node*2,L,(L+R)/2,l,r,v);
    up(node*2+1,(L+R)/2+1,R,l,r,v);
    sum[node]=sum[node*2]+sum[node*2+1];
    tree[node]=max(tree[node*2],sum[node*2]+tree[node*2+1]);
}
void solve(){
    int n,q; cin>>n>>q;
    for(int i=1; i<=n; i++) cin>>a[i];
    build(1,1,n);
    while(q--){ 
        int i,u,v; cin>>i>>u>>v;
        if(i==1){
            up(1,1,n,u,u,v);
        }else{
          cur=0;
          cout<<cal(1,1,n,u,v)<<endl;
        }
    }
}
signed main(){
    // freopen("248.in", "r", stdin);
    // freopen("248.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t=1;
    // cin>>t;
    while(t--){
        solve();
        cout<<endl;
    }
    return 0;
}   
