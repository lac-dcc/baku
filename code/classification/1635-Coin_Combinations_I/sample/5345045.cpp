#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(a) sort(a.begin(), a.end() )
#define rrep(a) sort(a.rbegin(), a.rend() )
#define pb push_back
#define endl "\n"
#define MX 500001
#define mkp make_pair
#define all(a) (a.begin(), a.end() )
#define bs binary_search
#define MAX 1005
#define nl "\n"
#define kop(n) for(int i=0; i<n; i++)
#define kop2(n) for(int j=0; j<n; j++)
#define vll vector<ll>
#define vi vector<int>
#define MAXN 100005
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define gap " "
#define ff first
#define ss second
#define pb push_back
#define in insert
#define f0(b) for(int i=0;i<(b);i++)
#define f00(b) for(int j=0;j<(b);j++)
#define f1(b) for(int i=1;i<=(b);i++)
#define f11(b) for(int j=1;j<=(b);j++)
#define f2(a,b) for(int i=(a);i<=(b);i++)
#define f22(a,b) for(int j=(a);j<=(b);j++)
#define sf(a) scanf("%lld",&a)
#define sff(a,b) scanf("%lld %lld", &a , &b)
#define pf(a) printf("%lld\n",a)
#define pff(a,b) printf("%lld %lld\n", a , b)
#define bug printf("**!\n")
#define mem(a , b) memset(a, b ,sizeof(a))
#define front_zero(n) __builtin_clzll(n)
#define back_zero(n) __builtin_ctzll(n)
#define total_one(n) __builtin_popcountll(n)
#define clean fflush(stdout)
#define mod 1000000007
#define N 40010
//const ll mod 1e9;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
void in(vector<ll>&a){for(ll i=0;i<a.size();i++)cin>>a[i];}
vector<bool> prime;
vector<int> primes;
template<class T>void print(T& a) { for(auto x:a)cout<<x<<" "; cout<<"\n";}
int v[101];
int dp[1000001];
ll n;
int func(int x)
{
    if(dp[x]!=-1) return dp[x];
    if(x==0)  return dp[x]=1;
    int xx = 0;
    for(int i=0; i<n; i++)
    {
        if(x-v[i]>=0) xx=(xx+func(x-v[i])%mod)%mod;
    }
    return dp[x]=xx;
}
void solve()
{
    ll x;
    cin>>n>>x;
    for(int i=0; i<n; i++) cin>>v[i];
    for(int i=0; i<1000001; i++) dp[i]=-1;
    cout<<func(x)<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
}
