#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define oset tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update>
#define mset tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
 
#define forn(i,n) for(int i=0;i<n;i++)
#define forab(i,a,b) for(int i=a;i<=b;i++)
#define forev(i,a,b) for(int i=a;i>=b;i--)
#define all(v) v.begin(),v.end()
#define int long long
#define ld long double
#define pii pair<int,int>
#define pis pair<int,string>
#define pic pair<int,char>
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define inf 1e18
#define bpi(i) __builtin_popcount(i)
#define bpll(i) __builtin_popcountll(i)
 
vi v;
vi seg;
vi lazy;
 
void prop(int l,int r,int i){
    seg[i]+=lazy[i];
    if(l!=r){
        lazy[2*i]+=lazy[i];
        lazy[2*i+1]+=lazy[i];
    }
    lazy[i]=0;
}
 
void build(int l,int r,int i){
    if(l==r){
        seg[i]=v[l];
        return;
    }
    int m=(l+r)/2;
    build(l,m,2*i);
    build(m+1,r,2*i+1);
    seg[i]=max(seg[2*i],seg[2*i+1]);
 
}
 
void update(int low,int high,int l,int r,int i,int val){\
    prop(low,high,i);
    if(high<l || r<low) return;
 
    if(l<=low && high<=r){
        lazy[i]+=val;
        prop(low,high,i);
        return;
    }
    int m=(low+high)/2;
    update(low,m,l,r,2*i,val);
    update(m+1,high,l,r,2*i+1,val);
    seg[i]=max(seg[2*i],seg[2*i+1]);
}
 
int query(int low,int high,int l,int r,int i){
    prop(low,high,i);
    if(low>r || high<l) return INT64_MIN;
    if(l<=low && high<=r) return seg[i];
    int m=(low+high)/2;
    return max(query(low,m,l,r,2*i),query(m+1,high,l,r,2*i+1));
 
}
 
 
void solve(){
    int n,q;
    cin>>n>>q;
 
    v.resize(n+1);
    seg.resize(4*(n+1),0);
    lazy.resize(4*(n+1),0);
 
    forn(i,n) cin>>v[i+1];
    vi org=v;
    v[0]=0;
   
    forn(i,n) v[i+1]+=v[i];
    build(1,n,1);
 
    while(q--){
 
        int type;
        cin>>type;
 
        if(type==1){
            int k,u;
            cin>>k>>u;
            update(1,n,k,n,1,u-org[k]);
            org[k]=u;
        }
        else{
            int a,b;
            cin>>a>>b;
            cout<<max(0LL,query(1,n,a,b,1)-(a!=1 ? query(1,n,a-1,a-1,1):0))<<endl;
        }
    }
 
}
signed main() {
    // Your code goes here;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout<<fixed<<setprecision(12);
    int t;
    t=1; 
    while(t--){
        solve();
        cout<<"\n";
    }
    return 0;
}
