// Dinar Perseüs 2.0
#include <bits/stdc++.h>
#include <cstdio>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize ("Ofast,unroll-loops,-ffloat-store")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma")
#define ll long long int
#define fo(i, n) for (int i = 0; i < n; i++)
#define cy cout << "YES\n"
#define cn cout << "NO\n"
#define nl cout << '\n'
#define pu push_back
#define po pop_back
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pil pair<int, ll>
#define pli pair<ll, int>
#define in insert
// #define f first
// #define s second
#define dbg1(x) cerr << '#' << #x << " = " << x << '\n'
#define dbg2(x, y) cerr << '#' << #x << " = " << x << "    &    #" << #y << " = " << y << '\n'
#define dbg3(x, y, z) cerr << '#' << #x << " = " << x << "    &    #" << #y << " = " << y << "    &    #" << #z << " = " << z << '\n'
#define all(x) x.begin(), x.end()
using namespace __gnu_pbds;
using namespace std;
template<class T> using  oset= tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
ll left_shift[63]={1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824, 2147483648, 4294967296, 8589934592, 17179869184, 34359738368, 68719476736, 137438953472, 274877906944, 549755813888, 1099511627776, 2199023255552, 4398046511104, 8796093022208, 17592186044416, 35184372088832, 70368744177664, 140737488355328, 281474976710656, 562949953421312, 1125899906842624, 2251799813685248, 4503599627370496, 9007199254740992, 18014398509481984, 36028797018963968, 72057594037927936, 144115188075855872, 288230376151711744, 576460752303423488, 1152921504606846976, 2305843009213693952, 4611686018427387904};
// constant
const int mod = 1e9 + 7;
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
 
void fileio()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
 
 
 
 
bool comp(pii x,pii y){
    return (x.first>y.first)||((x.first==y.first)&&(x.second<y.second));
}
 
 
 
 
// Binary Exponentiation
ll pow(ll a,ll b,ll m){
    ll value=1;
    while (b>0)
    {
        if (b&1)
        {
            value=(value*a)%m;
        }
        a=(a*a)%m;
        b>>=1;
    }
    
    return value;
}
 
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
 
 
 
 
 
 
//segment tree 
ll pre[4*200000];
ll seg[4*200000];
ll lazy[4*200000];
 
//build segment tree 
void build(int p, int a[], int l, int r){
    //lazy[p]=0;
    pre[p]=0;
    if(l==r){
        seg[p]=a[l];
        if(a[l]>0)pre[p]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(2*p, a, l, mid);
    build(2*p+1, a, mid+1, r);
    seg[p]=seg[2*p]+seg[2*p+1];
    pre[p]=max(pre[2*p],seg[2*p]+pre[2*p+1]);
    
 
}
 
//lazy propagation
void propagate(int p,int l,int r){
    int mid=(l+r)>>1;
    lazy[2*p] = lazy[2*p]+lazy[p];
    lazy[2*p+1] = lazy[2*p+1]+lazy[p];
    seg[2*p] = seg[2*p]+lazy[p]*(mid-l+1);
    seg[2*p+1] = seg[2*p+1]+lazy[p]*(r-(mid+1)+1);
    lazy[p] = 0;
    
}
 
//update segment
void update(int p, int l, int r, int s, int e, int v){
    if(s>r||e<l) return;
    if(s<=l&&r<=e) {
        lazy[p]=lazy[p]+v;
        seg[p]=v;
        pre[p]=0;
        if(v>0)pre[p]=v;
        return;
    }
    
    //propagate(p,l,r);
    
    int mid=(l+r)>>1;
    update(2*p, l, mid, s, e, v);
    update(2*p+1, mid+1, r, s, e, v);
    seg[p]=seg[2*p]+seg[2*p+1];
    pre[p]=max(pre[2*p],seg[2*p]+pre[2*p+1]);
    
}
 
//query segment tree
pair<ll,ll> query(int p, int l, int r, int s, int e){
    if(s>r||e<l) return {0,0};
    if(s<=l&&r<=e) return {pre[p],seg[p]};
    
    propagate(p,l,r);
    
    int mid=(l+r)>>1;
    pll x=query(2*p, l, mid, s, e);
    pll y=query(2*p+1, mid+1, r, s, e);
    return {max(x.first,x.second+y.first),x.second+y.second};
 
 
}
 
 
 
 
 
// code gose here
void solve()
{
    int n,q;
    cin>>n>>q;
    int a[n+1];
    fo(i,n)cin>>a[i+1];
    build(1,a,1,n);
    while(q--){
        int op;
        cin>>op;
        if(op&1){
            int p,v;
            cin>>p>>v;
            update(1,1,n,p,p,v);
 
 
 
 
        }else{
            int s,e;
            cin>>s>>e;
            cout<<query(1,1,n,s,e).first;nl;
        }
 
 
 
 
    }
 
 
    
    
}
 
 
 
int main()
{
    //fileio();
    fastio();
 
    // clock_t z = clock();
    int t = 1;
    //cin>>t;
    while (t--)
        solve();
    // cerr<<"Run Time : "<<((double)(clock()-z)/CLOCKS_PER_SEC);
    return 0;
}
