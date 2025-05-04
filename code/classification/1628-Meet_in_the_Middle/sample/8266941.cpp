// Dinar Perseüs 2.0
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize ("Ofast,unroll-loops,-ffloat-store")
//#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma")
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
#define f first
// #define s second
#define dbg1(x) cerr << '#' << #x << " = " << x << '\n'
#define dbg2(x, y) cerr << '#' << #x << " = " << x << "    &    #" << #y << " = " << y << '\n'
#define dbg3(x, y, z) cerr << '#' << #x << " = " << x << "    &    #" << #y << " = " << y << "    &    #" << #z << " = " << z << '\n'
#define all(x) x.begin(), x.end()
// using namespace __gnu_pbds;
using namespace std;
// template<class T> using  oset= tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
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
 
//graph
class graph
{
    int v;
    list<pair<int,int>> *adj;
public:
    graph(int v){
        this->v=v;
        adj=new list<pair<int,int>>[v];
    }
    void addedge(int u, int v,int w){
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
};
 
 
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
 
 
 
// //segment tree
// vector<ll> seg(4000);
 
// //char lazy[400000+5];
 
 
// void build_segment(int p,int l,int r,int arr[]){
//     if (l==r)
//     {
//         seg[p]=arr[l];
//         return;
//     }
//     int mid=(l+r)/2;
//     build_segment(2*p,l,mid,arr);
//     build_segment(2*p+1,mid+1,r,arr);
//     seg[p]=seg[2*p]+seg[2*p+1];
// }
 
// ll q_segment(int p,int l,int r,int a,int b){
//     if (l>b||r<a)
//     {
//         return 0;
//     }
//     if(a<=l&&r<=b)return seg[p];
    
//     int mid=(l+r)/2;
//     return q_segment(2*p,l,mid,a,b)+q_segment(2*p+1,mid+1,r,a,b);
// }
 
 
 
 
 
 
 
 
// void update_segment(int p,int l,int r,int a,int b){
 
    
//     if(lazy[p]){
//         lazy[p]=0;
 
//         if(l!=r){
//             lazy[2*p]^=1;
//             lazy[2*p+1]^=1;
//         }
//         swap(seg[p][0],seg[p][1]);
//     }
 
//     if (l>b||r<a)
//     {
//         return;
//     }
 
//     if (a<=l&&r<=b)
//     {
//         if(l!=r){
//             lazy[2*p]^=1;
//             lazy[2*p+1]^=1;
//         }
//         swap(seg[p][0],seg[p][1]);
//         return;
        
//     }
//     int mid=(l+r)/2;
//     update_segment(2*p,l,mid,a,b);
//     update_segment(2*p+1,mid+1,r,a,b);
 
//     seg[p][0]=seg[2*p][0]^seg[2*p+1][0];
//     seg[p][1]=seg[2*p][1]^seg[2*p+1][1];
  
 
 
// }
 
 
 
 
// int fn(int a[],int i,int p1,int p2){
//     if (i==-1)
//     {
//         return 0;
//     }else{
//         int x=0,y=0;
 
//         if(p1!=-1&&a[i]<a[p1])x++;
//         if(p2!=-1&&a[i]<a[p2])y++;
//         return min(x+fn(a,i-1,i,p2),y+fn(a,i-1,p1,i));
        
 
        
//     }
    
    
 
// }
 
 
ll max(ll a,ll b){
    if(a>b)return a;
    else
    {
        return b;
    }
    
}
 
void fn(int s,ll &e,vl &mp,vl &v,ll sum,ll &t){
    if(sum>t)return;
    if (s==e)
    {
        mp.push_back(sum);
        
    }else
    {
        fn(s+1,e,mp,v,sum,t);
        fn(s+1,e,mp,v,sum+v[s],t);
    }
 
}
 
 
// code gose here
void solve()
{
    ll n,t;
    cin>>n>>t;
    vl v(n);
    vl a,b;
    fo(i,n)cin>>v[i];
    ll s=n/2;
    fn(0,s,a,v,0,t);
    fn(n/2,n,b,v,0,t);
    sort(all(b),greater<ll>());
    sort(all(a));
 
 
    ll x=0;
    int j=0,i=0;
    while (i<(int)a.size()&&j<(int)b.size())
    {
        ll value=a[i];
        ll cnt =0;
        ll cnt2=0;
        while (a[i]==value&&i<a.size())
        {
            cnt++;
            i++;
 
        }
        while (b[j]>=t-value&&j<b.size())
        {
            if(b[j]==t-value)cnt2++;
            j++;
        }
 
        x+=(cnt*cnt2);
 
        
    }
    
 
    cout<<x;nl;
 
 
 
 
 
    
}
 
 
 
int main()
{
    fileio();
    fastio();
    // clock_t z = clock();
    int t = 1;
    //cin>>t;
    while (t--)
        solve();
    // cerr<<"Run Time : "<<((double)(clock()-z)/CLOCKS_PER_SEC);
    return 0;
}
