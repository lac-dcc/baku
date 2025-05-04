#include <bits/stdc++.h>
using namespace std;
#define MODS 100005
#define MOD 1000000000000000001
#define all(x) (x).begin(), (x).end()
#define ll long long int
#define ld long double
#define bigint int64_t
#define vll vector<ll>
#define vpll vector<pair<ll,ll>>
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define test ll t;read(t);while(t--)
#define pll pair<ll,ll>
#define vvll vector<vector<ll>>
#define fst first
#define scd second
#define ins insert
#define line "\n"
#define yes "YES"
#define no "NO"
#define tup tuple<ll,ll,ll>
#define min(a,b) ((a<b)?a:b)
#define max(a,b) ((a>b)?a:b)
 
#define debug2(x,y)  cerr << #x <<"="<<x<<" "<<#y<<"="<<y<<line;
#define debug3(x,y,z)cerr << #x <<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<line;
#define forn(i,n) for(ll (i) = 0 ; (i) < (n) ; ++(i))
#define for1(i,n) for(ll (i) = 1 ; (i) <= (n) ; ++(i))
#define forr(i,n) for(ll (i) = (n)-1 ; (i)>=0 ; --(i))
#define forab(i,a,b,c) for(ll (i) = a ; (i) <= (b) ; (i)+=(c))
 
#ifndef ONLINE_JUDGE
#define debug(x)    cerr << #x <<"="; _print(x); cerr << line;
#else
#define debug(x)
#endif
 
template <typename T>                                           void read(T &x){cin >> x;}
template <typename T , typename T0>                             void read(T &x,T0 &y){cin >> x >> y;}
template <typename T , typename T0 , typename T1>               void read(T &x,T0 &y,T1 &z){cin >> x >> y >> z;}
template <typename T , typename T0 , typename T1 , typename T2> void read(T &x,T0 &y,T1 &z,T2 &w){cin >> x >> y >> z >> w;}
template <typename T , typename T0>                             void read(pair< T , T0 > &p){cin >> p.fst >>p.scd;}
template <typename T>                                           void read(vector< T > &oneD,ll n){forn(i,n){T x;read(x);oneD.push_back(x);}}
template <typename T>                                           void read(T oneD[] , ll n){for(ll i=0;i<n;i++){read(oneD[i]);}}
template <typename T>                                           void write(T &x){cout << x << " ";}
template <typename T>                                           void wrtline(T &x){cout << x << line;}
template <typename T , typename T0>                             void write(T &x,T0 &y){cout << x << " " << y << "\n";}
template <typename T , typename T0 , typename T1>               void write(T &x,T0 &y,T1 &z){cout << x << " " << y << " " << z << "\n";}
template <typename T , typename T0 , typename T1 , typename T2> void write(T &x,T0 &y,T1 &z,T2 &w){cout << x << " " << y << " " << z << " " << w << "\n";}
template <typename T , typename T0>                             void write(pair< T , T0 > &p){write(p.fst);write(p.scd);cout << line;}
template <typename T>                                           void write(vector< T > &oneD,ll n){for(ll i=0;i<n;i++){cout<<oneD[i]<<" ";}cout << line;}
template <typename T>                                           void write(T oneD[] ,int &n){for(ll i=0;i<n;i++){write(oneD[i]);}cout <<line;}
template <typename T , typename T0>                             void write(map< T , T0 > &mpp){for(auto it : mpp){write(it.fst);cout << ": ";write(it.scd);cout << "\n";}cout<<line;}
template <typename T>                                           void write(vector<vector<T>> &rc,T &n,T &m){forn(i,n){forn(j,m){cout<<rc[i][j]<<" ";}cout<<line;}}
template <typename T>                                           void _print(T &t) {cerr << t;}
template <class T, class V>                                     void _print(pair <T, V> &p);
template <class T>                                              void _print(vector <T> &v);
template <class T>                                              void _print(set <T> &v);
template <class T, class V>                                     void _print(map <T, V> &v);
template <class T>                                              void _print(multiset <T> &v);
template <class T, class V>                                     void _print(pair <T, V> &p) {cerr << "{"; _print(p.fst); cerr << ","; _print(p.scd); cerr << "}";}
template <class T>                                              void _print(vector <T> &v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T>                                              void _print(set <T> &v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T>                                              void _print(multiset <T> &v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V>                                     void _print(map <T, V> &v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
// ll diff(ll a,ll b)
// {
//     ll k=(((a%MOD)-(b%MOD))+MOD)%MOD;
//     return k;
// }
// bool check(ll &prod,ll x)
// {
//     ll temp=prod;
//     prod*=x;
//     prod+=MOD;
//     prod%=MOD;
//     if(prod<=temp)
//         return 0;
//     return 1;
// }
void solve()
{
    ll n,k;
    read(n,k);
    vll c;
    read(c,k);
    sort(all(c));
    vll storeContri(k+1,0);
    ll ans=0;
    for(ll i=1;i<(1<<k);i++)
    {
        ll j=i,indx=0,temp=n;
        bool flag=1;
        while(j)
        {
            if(j&1)
                temp/=c[indx];
            j/=2;
            indx++;
        }
        storeContri[__builtin_popcount(i)]+=temp;
    }
    forn(i,k+1)
    {
        if(i&1)
            ans+=storeContri[i];
        else
            ans-=storeContri[i];
    }
    write(ans);
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stderr);
#endif
ios_base::sync_with_stdio(false);
cin.tie(NULL);
//*******************************************************//
// test
solve();
 
return 0;
}