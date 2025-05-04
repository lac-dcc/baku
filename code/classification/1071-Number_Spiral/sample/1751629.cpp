#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using ll=long long;
using db=double;
 
///***************************************************** CONSTANTS ******************************************************///
 
int const N=1e6+3;
ll MOD=1e9+7,fact[N];
const long long inf=(long long)1e18;
const long double PI=3.14159265358979;
 
///************************************************ CONTAINER DEFINITIONS ***********************************************///
 
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef set<int> si;
typedef set<ll> sl;
typedef map<int,int> mii;
typedef map<ll,ll> mll;
 
///************************************************ SHORT FORM KEYWORDS *************************************************///
 
#define PB push_back
#define F first
#define S second
#define MP make_pair
#define I insert
#define lb lower_bound
#define ub upper_bound
#define endl '\n'
 
///************************************************ SHORT FORM FUNCTIONS ************************************************///
 
#define loop(i,a,b) for(ll i=a;i<b;i++)
#define loopr(i,a,b) for(ll i=a-1;i>=b;i--)
#define afor(x, y) for (auto x : y)
#define mem(a,b) memset(a, b, sizeof(a) )
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define sa(v) sort(v.begin(),v.end())
#define sd(v) sort(v.begin(),v.end(),greater<>())
#define rev(s) reverse(s.begin(),s.end())
#define stll(x) stoll(x, nullptr, 10);
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define mx(a) *max_element(all(a))
#define mn(a) *min_element(all(a))
#define all(a) a.begin(),a.end()
#define mxa(a,N) *max_element(a,a+N)
#define mna(a,N) *min_element(a,a+N)
#define print(a) {for(auto x:a)cout<<x<<" ";cout<<endl;}
 
///******************************************** FAST IO $ FILE INPUT ****************************************************///
 
#define io() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define fio() freopen("input_file_name","r",stdin);freopen("output_file_name","w",stdout);
 
///********************************************* REQUIRED FUNCTIONS *****************************************************///
 
ll powmod(ll a,ll b){ll p=MOD;a%=p;if(!a) return 0;ll pr=1;while(b>0){if(b&1){pr*=a;pr%=p;--b;}a*=a;a%=p;b/=2;}return pr;}
ll inv(ll a,ll p){return powmod(a,p-2);}
ll nCr(ll n,ll k,ll p){fact[0]=1;loop(i,1,n+1) fact[i]=fact[i-1]*i;return ((fact[n]*inv(fact[k],p)%p)*inv(fact[n-k],p))%p;}
bool isPrime(ll n){ if(n<=1)return false;if(n<=3)return true;if(n%2==0 or n%3==0)return false;for(ll i=5;i*i<=n;i+=6){if(n%i==0|n%(i+2)==0)return false;}return true;}
 
///######################################################################################################################///
 
typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
///************************************************ SOLUTION STARTS HERE ************************************************///
///======================================================================================================================///
 
 
void solve()
{
    ll x,y;
    cin>>y>>x;
    unsigned long long sq = max(x,y);
    ll k=sq;
    sq*=sq;
    if(k%2){
        sq-=y-1;
        if(x<y){
            sq-=y-x;
        }
    }else{
       sq-=x-1;
        if(y<x){
            sq-=x-y;
        }
    }
    cout<<sq<<endl;
}
 
int main()
{
    io();
    int $=1;cin>>$;
    while($--) solve();
    return 0;
}
