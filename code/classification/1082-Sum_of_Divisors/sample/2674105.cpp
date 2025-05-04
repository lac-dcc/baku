#include<bits/stdc++.h>
#include<algorithm>
#include<string>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;
 
#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pi acos(-1.0)
 
#define sf(a) scanf("%lld",&a)
#define sff(a,b) scanf("%lld %lld",&a,&b)
#define sfff(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define pf(a) printf("%lld\n",a)
 
#define stll(a) stoll(a,nullptr,10)
#define all(a) a.begin(),a.end()
#define PII pair<ll,ll>
#define PDD pair<double,double>
#define MP(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define EL printf("\n")
#define ff first
#define ss second
#define rev(a) reverse(all(a))
#define endl "\n"
 
#define mem(ar,val) memset(ar,val,sizeof(ar))
#define csort(ar,comp) sort(ar.begin(),ar.end(),comp)
 
#define bug1(a) cerr<<"test "<<a<<endl;
#define bug2(a,b) cerr<<"test "<<a<<" "<<b<<endl;
#define bug3(a,b,c) cerr<<"test "<<a<<" "<<b<<" "<<c<<endl;
#define bug4(a,b,c,d) cerr<<"test "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
 
#define fout freopen("output.txt","w",stdout)
#define fin  freopen("input.txt","r",stdin)
 
///inline char nc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
///template <class T>inline bool scan_d(T & x){char c=nc();x=0;if(c==EOF)return false;for(; c>'9'|c<'0'; c=nc());for(; c>='0'&&c<='9'; x=x*10+c-'0',c=nc());return true;}
 
///priority_queue <int, vector<int>, greater<int> > pq;
 
/// unordered_map<int,int>mp;
/// mp.reserve(1024);
/// mp.max_load_factor(0.25);
 
/// pbds
/// *find_by_order(k) - return k th largest element.. 0 based
/// order_of_key(k) - number of items strictly smaller than k
 
/*
ll Set(ll n, ll pos){return n | (1<<pos);}
ll reset(ll n,ll pos){return n & (~(1<<pos));}
ll check(ll n,ll pos){return n&(1<<pos);}
*/
 
 
/*
struct HASH{
  size_t operator()(const pair<int,int>&x)const{
    return (size_t) x.first * 37U + (size_t) x.second;
  }
};
*/
 
typedef long long ll;
typedef unsigned long long ull;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
 
ll mod = 1e9 +7;
 
int main()
{
    FASTER;
    ll n,p,a,b;
    cin>>n;
    ll ans =0;
    for(ll i=1,j;i<=n;i=j+1)
    {
        j = n/(n/i);
        a = j-i+1;
        b = i+j;
        if((j-i+1)%2==0)a/=2;
        else b/=2;
        p = ((a%mod)*(b%mod))%mod;
        p = (p *(n/i))%mod;
        ans=(ans+p)%mod;
    }
    cout<<ans<<endl;
}
