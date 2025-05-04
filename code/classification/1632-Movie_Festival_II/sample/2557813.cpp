#include <bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define mod 1000000007
#define inf 1e18
#define endl "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rep(i, init, n) for (int i = init; i < (int)n; i++)
#define rev(i, n, init) for (int i = (int)n; i >= init; i--)
#define V vector<int>
#define VV vector<V>
#define Vll vector<ll>
#define VVll vector<Vll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Vpii vector<pii>
// template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key
#ifndef anurag203
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
 
//vector<bool> isprime;
vector<bool> SieveOfEratosthenes(ll n){
vector<bool> prime(n + 1, 1); for (ll p = 2; p * p <= n; p++)
if (prime[p] == true) for (ll i = p * p; i <= n; i += p)
prime[i] = false; return prime;}
 
ll powe(ll x,ll y, ll p=mod){
ll res = 1; x = x % p;
while (y > 0){ if (y & 1) res = (res * x) % p;
y = y >> 1; x = (x * x) % p;} return res;}
 
ll inverse_modulo(ll a, ll p = mod)
{return powe(a, p - 2, p);}
////factorial vector
// Vll fact(200000, 1);
// void fill_fact(ll p = mod){rep(i, 1, 200000){fact[i] = (fact[i - 1] * i) % p;}}
////nCr fermat
// ll C(ll n,ll r,ll p=mod)
// {return ((fact[n]*inverse_modulo(fact[n-r]))%mod*inverse_modulo(fact[r]))%mod;}
 
template <class T, class vv> void _print(pair <T, vv> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class vv> void _print(map <T, vv> v);
template <class T> void _print(multiset <T> v);
template <class T, class vv> void _print(pair <T, vv> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class vv> void _print(map <T, vv> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*----------------------------------------------------------------------------------------------------------------------------------------------------*/
bool comp(pii p1,pii p2)
{
    return p1.ss<p2.ss;
}
int main() {
#ifndef anurag203
    freopen("Error.txt", "w", stderr);
#endif
    fastio();
    // freopen("output.in", "r", stdin);
    // freopen("output.out", "w", stdout);
 
    int tt = 1;
    // cin>>tt;
    while (tt--)
    {
        int n,k;
        cin >> n >> k;
        multiset<int> s;
        rep(i,0,k)
        {
            s.insert(0);
        }
        Vpii a;
        int x,y;
        rep(i,0,n)
        {
            cin>>x>>y;
            a.pb(mp(x,y));
        }
        sort(all(a),comp);
        // debug(a)
        int ans=0;
        rep(i,0,n)
        {
            // if (a[i].ff > *s.begin())
            // {
            //     s.erase(s.begin());
            //     s.insert(a[i].ss);
            //     ans++;
            // }
            auto it=s.upper_bound(a[i].ff);
            if(it!= s.begin())
            {
                it--;
                s.erase(it);
                s.insert(a[i].ss);
                ans++;
            }
        }
        cout<<ans;
 
    }       
    return 0;
}
