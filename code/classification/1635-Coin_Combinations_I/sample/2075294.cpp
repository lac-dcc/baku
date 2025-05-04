#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
 
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long int
#define ld long double
#define vll vector<ll>
#define vpll vector<pair<ll,ll>>
#define pll pair<ll,ll>
#define mll map<ll,ll>
#define umll unordered_map<ll,ll>
#define mmll multimap<ll,ll>
#define sll set<ll>
#define usll unordered_set<ll>
#define msll multiset<ll>
#define is indexed_set
#define mi map<ll,ll> :: iterator
#define umi unordered_map<ll,ll> :: iterator
#define si set<ll> :: iterator
#define usi unordered_set<ll>:: iterator
#define msi multiset<ll>:: iterator
#define vi vector<ll> :: iterator
#define vpi vector<pair<ll,ll>> :: iterator
#define stll stack<ll>
#define qll queue<ll>
#define pqll priority_queue<ll>
#define str string
#define vl(p) vector<p>
#define w while
#define For(i,s,x) for(i=s;i<x;i++)
#define Fore(i,s,x) for(i=s;i<=x;i++)
#define FOR(i,x) for(i=0;i<x;i++)
#define Rof(i,s,x) for(i=s;i>=x;i--)
#define all(v) v.begin(),v.end()
#define it(r,v) for(auto r=v.begin();r!=v.end();r++)
#define lb lower_bound
#define ub upper_bound
#define maxe max_element
#define mine min_element
#define rvs reverse
#define dis distance
#define sp setprecision
#define un unique
#define app append
#define pw pow
#define gtr greater<ll>()
#define fbo find_by_order
#define o2k order_of_key
#define pb push_back
#define in insert
#define sz size()
#define bg begin()
#define ed end()
#define F first
#define S second
#define nl cout<<"\n"
#define pr(a) cout<<a<<" "
#define ip(a) cin>>a
#define ip2(a,b) cin>>a>>b
#define ip3(a,b,c) cin>>a>>b>>c
#define pr2(a,b) cout<<a<<" "<<b
#define pr3(a,b,c) cout<<a<<" "<<b<<" "<<c<<"\n"
#define mod 1000000007
const double PI = 3.141592653589793238;
 
int main()
{
    FASTIO;
    ll n,x;
    ip2(n,x);
    ll p[n];
    for(ll a=0;a<n;a++)
    ip(p[a]);
    //ll dp[x+1]={0};
    vector<ll> dp(x + 1, 0);
    dp[0]=1;
    ll cp=*mine(p,p+n);
    for(ll i=1;i<=x;i++)
    {
            ll ans=0;
            for(ll j=0;j<n;j++){
                if(i>=p[j])
            ans=(ans%mod+dp[i-p[j]]%mod)%mod;
            }
            dp[i]=ans;
    }
    pr(dp[x]);
    nl;
return 0;
}
