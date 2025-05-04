#include<bits/stdc++.h>
using namespace std;
#define int int64_t
#define inf INT64_MAX
#define pii pair<int,int>
#define vi vector<int>
#define endl '\n'
#define pb push_back
int t, n, m, i, j, k,a, b,c,p,x,y,ans,n1;
string s1,s2;
const int M = 1e9+7;
bool bo;
 
int  binpow(int a, int  b, int  m) {
    a %= m;
    int  res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
 
vector<int> in;
vector<int> out;
vector<vector<int>> tree;
 
void dfs2(int i,int p){
    int mx1=-1,mx2=-1;
    for(auto x:tree[i]){
        if(x==p)continue;
        if(in[x]>mx1){
            mx2=mx1;
            mx1=in[x];
        }
        else if(in[x]>mx2)mx2=in[x];
    }
    for(auto x:tree[i]){
        if(x==p)continue;
        int use=mx1;
        if(in[x]==mx1)use=mx2;
        out[x]=max(out[x],max(2+use,1+out[i]));
    }
    for(auto x:tree[i]){
        if(x==p)continue;
        dfs2(x,i);
    }
}
 
void dfs1(int i,int p){
    for(auto x:tree[i]){
        if(x==p)continue;
        dfs1(x,i);
        in[i]=max(in[i],1+in[x]);
    }
}
 
void solve() {
    int n;
    cin>>n;
    tree.resize(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    in.resize(n);
    out.resize(n);
    in.assign(n,0);
    out.assign(n,0);
    dfs1(0,-1);
    dfs2(0,-1);
    for(int i=0;i<n;i++){
        cout<<max(in[i],out[i])<<" ";
    }
 
}
 
 
 
 
 
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    t = 1;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
//  cin >> t;
    while (t--) solve();
}
 
 


