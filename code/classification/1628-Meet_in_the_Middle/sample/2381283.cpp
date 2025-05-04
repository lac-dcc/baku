#include<bits/stdc++.h>
using namespace std;
 
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
 
/* // Ordered Set
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define os_find(k) find_by_order(k)
#define os_order(k) order_of_key(k)
*/
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
#define f0(i,a,b) for(int i=a;i<b;i++)
#define f1(i,a,b) for(int i=a;i<=b;i++)
#define f2(i,a,b) for(int i=a;i>b;i--)
#define f3(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
// or add ll at the end for long long
#define cntleadz(x) __builtin_clz(x)
#define cnttrailz(x) __builtin_ctz(x)
#define cntpop(x) __builtin_popcountll(x)
#define binparity(x) __builtin_parity(x)
#define pb push_back
#define pii pair<int,int>
#define int long long
#define fi first
#define se second
#define debug_vector(v)			\
	for(auto x : v)             \
		cout<<x<<' ';           \
	cout<<'\n'
#define debug_pvector(v)        \
    for (auto x : v)            \
        cout<<x.fi<<' '<<x.se<<'\n';
#define debug(x) cout<<#x<<" = "<<x<<'\n'
#define mod 1000000007
// #define mod 998244353
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define make_graph(k) int x,y; f0(i,0,k){cin>>x>>y; adj[x].pb(y); adj[y].pb(x);}
#define test int t;cin>>t;while(t--)
 
ll binExp(ll x,ll n,ll m)
{
    ll res=1;
    while(n)
    {
        if(n&1) res=(res*x)%m;
        x=(x*x)%m;
        n>>=1;
    }
    return res;
}
 
ll modInv(ll i, ll m) {return binExp(i,m-2,m);}
ll add(ll a, ll b) {ll res = a+b; if(res >= mod) res -= mod; if(res < 0) res += mod; return res;}
ll mul(ll a, ll b) {ll res = (a)*(b); res %= mod; if(res < 0) res += mod; return res;}
// ll fact[1000006];
// ll ncr(int n,int r) {return (n>=r?(fact[n]*modInv(fact[r],mod))%mod*modInv(fact[n-r],mod)%mod:0);}
 
 
 
void solve()
{
    int n,x;
    cin>>n>>x;
 
    int t[n];
    f0(i,0,n) cin>>t[i];
 
    vector<int> one, two;
 
    int ans = 0;
    f0(z,1,1<<(n/2))
    {
        int cur = 0;
        f0(j,0,n/2)
        {
            if((z>>j)&1) cur += t[j];
        }
        one.pb(cur);
        if(cur == x) ans++;
        // cout<<cur<<endl;
    }
 
    f0(z,1,1<<(n-n/2))
    {
        int cur = 0;
        f0(j,0,n-n/2)
        {
            if((z>>j)&1) cur += t[n/2+j];
        }
        two.pb(cur);
        if(cur == x) ans++;
        // cout<<cur<<endl;
    }
 
    sort(all(one));
    sort(all(two));
 
    // for(pii i : one) cout<<i<<' '; cout<<'\n';
    // for(pii i : two) cout<<i<<' '; cout<<'\n';
 
    for(int i : one)
    {
        ans += upper_bound(all(two),x-i) - lower_bound(all(two),x-i);
    }
 
    cout<<ans<<'\n';
}
 
signed main()
{
    fast
 
    clock_t start,end;
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    start = clock();
 
    
 
    int tc;
    tc = 1;
    // cin>>tc;
    f1(i,1,tc)
        solve();
 
    end = clock();
    double time_taken = double(end-start) / double(CLOCKS_PER_SEC);
    // cout<<time_taken<<" sec";
}
