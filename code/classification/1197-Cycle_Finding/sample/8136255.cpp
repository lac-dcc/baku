#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
 
#define endl "\n"
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define ppb pop_back
#define mk make_pair
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define rfr(i,a,b) for(ll i=a;i>=b;i--)
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define PI 3.141592653589793238462
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define set_bits __builtin_popcount
#define pp pair<int,int>
#define yes cout<<"YES"<<'\n'
#define no cout<<"NO"<<'\n'
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
const ll mod = 1e9 + 7;
//const ll mod = 998244353;
 
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;} //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;}//o(sqrt n)
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
ll pwr(ll a, ll b) {a %= mod; ll res = 1; while (b > 0) {if (b & 1) res = res * a % mod; a = a * a % mod; b >>= 1;} return res;}
ll numprime(ll n){int count=0; while(n%2==0){n/=2;count++;} for(int i=3;i*i<=n;i+=2){while(n%i==0){n=n/i;count++;}}if(n>1){count++;}return count;}//2 2 3 5 5 7->6
 
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
 
#define int long long
//vector<multiset<int>>vt(n+5);vt[i].insert(x);y=*vt[a[i]].lower_bound(x);vt[a[i]].erase(vt[a[i]].find(x));
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, //order_of_key//YO:dec->greater<int>
//auto check= [&](vector<int>&x/*parameter*/){ };
//vector<ll>stk;vector<ll>left(n,-1);vector<ll>right(n,-1);for(ll i=0;i<n;i++){while(!stk.empty() && v[i]>v[stk.back()]){right[stk.back()]=i;stk.pop_back();}if(!stk.empty()){left[i]=stk.back();}stk.push_back(i);}//YO:next grt prev grt
const int N=2505;
const int M=5005;
vvi edges(M,vi(3));
vector<pp> adj[N];
vi dist(N,0);
vi par(N,-1);
 
void solve(){
    int n,m;
    cin>>n>>m;
    fr(i,1,m+1){
        int a,b,c;
        cin>>a>>b>>c;
        edges[i][0]=a;
        edges[i][1]=b;
        edges[i][2]=c;
        adj[a].pb({b,c});
    }
    fr(i,1,n+1){
        par[i]=i;
    }
    fr(i,0,n-1){
        for(auto &e: edges){
            int u=e[0],v=e[1],wt=e[2];
            if((dist[u] + wt) < dist[v]){
                dist[v]= dist[u] + wt;
                par[v]=u;
            }
        }
    }
    for(auto &e: edges){
        int u=e[0],v=e[1],wt=e[2];
        if((dist[u] + wt) < dist[v]){
            debug(u);
            debug(v);
            fr(i,0,n-1){
                v=par[v];
            }
            int start=par[v];
            int end=v;
            debug(start);
            debug(end);
            vi res;
            res.pb(start);
            while(start != end){
                start=par[start];
                res.pb(start);
            }
            reverse(all(res));
            res.pb(res[0]);
            yes;
            for(auto &ans: res){
                cout<<ans<<" ";
            }
            cout<<endl;
            return;
        }
    }
    no;return;
}
 
signed main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    fastio();//>>Don't use in interactive Question
    //pbds A;//A.insert(1);//for (auto i : A) cout << i << " ";//"0th element: " << *A.find_by_order(0) << endl;//"No. of elems smaller than 6: " << A.order_of_key(6)//A.erase(1);
    //Lower Bound of X = first element >= X in the set//Upper Bound of X = first element > X in the set//"Lower Bound of 6: " << *A.lower_bound(6)//"Upper Bound of 6: " << *A.upper_bound(6)
    // int t;
    // cin>>t;
    // while(t--){
    solve();
    //}
}
