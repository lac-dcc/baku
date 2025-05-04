#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds; 
// x^y≡x^(y%(p-1))mod p
// but there is a condition that x needs to be coprime to p
///assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
typedef tree<int, null_type, less<int>, rb_tree_tag, 
             tree_order_statistics_node_update> 
    indexed_set; 
typedef long long int ll;
typedef pair<ll, ll> pii;
typedef vector<pii> vii;
#define  pb push_back
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fo(i,a,b) for(ll i = a; i<=b;i+=1)
#define rf(i,a,b)  for(ll i=a;i>=b;i--)
#define vll vector<ll>
#define tests() int test_cases ; cin >> test_cases ; while(test_cases--)
#define ub upper_bound
#define lb lower_bound
#define all(v) v.begin(),v.end()
#define MAXN 100010
#define MOD 1000000007
#define mod 998244353
#define deb(x) cout << '>' << #x << ':' << x << endl;
#define sp " "
#define MS(x,y) fill_n(*x, sizeof x / sizeof **x, y);
#define mem(x,y) memset(x,y,sizeof(x));
#define INF 1000000000000000000
#define IO                 \
	ios::sync_with_stdio(0); \
	cin.tie(0);              \
	cout.tie(0);
#define debug(x) cerr << (#x) << " is " << (x) << endl;
 
#ifndef ONLINE_JUDGE
#define cerr if(true)cerr
#endif
 
template<int D, typename T>
struct Vec : public vector<Vec<D - 1, T>> {
static_assert(D >= 1, "Vector dimension must be greater than zero!");
template<typename... Args>
	Vec(int n = 0, Args... args) : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...)) {
	}
};
template<typename T>
struct Vec<1, T> : public vector<T> {
	Vec(int n = 0, const T& val = T()) : vector<T>(n, val) {
	}
};
 
ll power(ll x, ll y,ll p) 
{ 
    ll res = 1;     // Initialize result 
    x = x % p;
    if (y==0)return 1;
    if(x==0)return 0;   
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p;    
        y = y>>1; // y = y/2 
        x = (x*x) % p;  // Change x to x^2 
    } 
    return res; 
}
int gcd(int a, int b) { if (a == 0)return b;return gcd(b % a, a);} 
 
ll modinv(ll a,ll p){return power(a,p-2,p);}
vll adj[2*MAXN];
Vec<1,ll> arr(2*MAXN,0);
void dfs(ll s,ll p){
    arr[s] = 1;
    if (adj[s].size()==1&&s!=1)
    {
        return; 
    }
    for (auto v:adj[s]){
        if (v==p)
        {
            continue;
        }
        dfs(v,s);
        arr[s]+=arr[v];
    }
    return;
}
int solve(){
    ll n;
    cin>>n;
    fo(i,2,n){
        ll a,b=i;
        cin>>a;
        // deb(a)deb(b)
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1,-1);
    fo(i,1,n){
        cout<<arr[i]-1<<" ";
    }
    cout<<endl;
    return 0;
}
int main()
 
{
    IO;
    int T=1;
	// cin >> T;
	f(c,0,T){
		solve();
	}
    return 0;
}// make_pair make_tuple  tuple<int,int,int> continue resize insert count size else true isValid second first false erase 
