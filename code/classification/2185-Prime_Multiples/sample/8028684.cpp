#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pi 3.141592653589793238462
#define inf 1000000000000000000
#define ff first
#define ss second
#define pb push_back
#define mod 1000000007
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
 
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<pair<long long, long long>> vpll;
typedef map<ll,ll> mpll;
 
//-------------------------------------------------------------------------------------------------------------------------------
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
//------------------------------------------------------------------------------------------------------------------------------
 
#define setbits(x) __builtin_popcountll(x)
#define in insert
#define all(x) x.begin(), x.end()
#define rep(i,a,n) for(ll i=a;i<n;i++)
#define repd(i,a,n) for(ll i=a;i>=n;i--)
//----------------------------------------------------------------------------------------------------------------------------
 
ll ways=0;
 
void f(ll i, ll prod, ll n, vll &a, ll k, ll sz){
    if(i==k-1){
        if(n/prod>=a[i]){
            sz++;
            if(sz%2==1) ways+=n/(prod*a[i]);
            else ways-=n/(prod*a[i]);
            sz--;
        }
        if(prod>1){
            if(sz%2==1) ways+=n/prod;
            else ways-=n/prod;
        }
        return;
    }
    if(n/prod>=a[i]) f(i+1,prod*a[i],n,a,k,sz+1);
    f(i+1,prod,n,a,k,sz);
}
 
 
void solve(){
    ll n,k;
    cin>>n>>k;
    vll a(k);
    rep(i,0,k) cin>>a[i];
    f(0,1,n,a,k,0);
    cout<<ways<<'\n';
}
 
 
int main(){
    fastio
    #ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    cout<<setprecision(16);
 
    ll t=1;
    // cin>>t;
    for(ll i=1;i<=t;i++){
        // cout<<"Case #"<<i<<": ";
        solve();
    }
}
 
/*
    1 .use sqrtl
    2 .use (1LL<<k)
    3 .for sets,multisets,maps use containername.lower_bound(value)
    4 .erase using iterator in multisets
*/