/*Program by
     author: StartupCoder
*/
 
#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define rep(i,n) for(int i = 0; i < n; i++)
#define repa(i,a,n) for(int i = a; i < n; i++)
#define repl(i,n) for(ll i = 0; i < n; i++)
#define repla(i,a,n) for(ll i = a; i < n; i++)
#define ff first
#define ss second
#define ones __builtin_popcountll
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a/__gcd(a,b) * b
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const ll M = 1e9+7;
const ll MOD2 = 998244353;
const ll LINF = LLONG_MAX;
const ll INF = INT_MAX;
const double pi=3.1415926536;
const string alpha="abcdefghijklmnopqrstuvwxyz";
const string calpha="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
 
/*-----------------------------------FUNCTIONS-START-------------------------------------------------------------*/
ll sumn(ll n){ll sum=n*(n+1)/2; return sum;}
ll bipowm(ll n, ll p){if(p==0) return 1; ll ans=bipowm(n, p/2); ans*=ans; ans%=MOD2; if(p%2)ans*=n; return ans%MOD2;}
ll bipow(ll n, ll p){if(p==0) return 1; ll ans=bipow(n, p/2); ans*=ans; if(p%2)ans*=n; return ans;}
ll fact(ll n){if(n==0) return 1; ll num=1; while(n--){num*=(n+1); num%=MOD2;} return num;}
ll choose(ll n, ll c){ll num = fact(n); num/=fact(c); num/=fact(n-c); return num;}
/*------------------------------------FUNCTIONS-END--------------------------------------------------------------*/
 
//Set false when no test case input is there
bool flag=false;
 
void solve(){
    ll n,x; cin>>n>>x;
    ll arr[n];
    rep(i,n) cin>>arr[i];
    sort(arr,arr+n);
    vector<ll> ans(x+1,0);
    ans[0] = 1;
    repa(i,1,x+1){
        rep(j,n){
            if(i-arr[j]<0) break; 
            ans[i]+=ans[i-arr[j]];
            ans[i]%=M;
        }
    }
    // rep(i,x+1) cout<<ans[i]<<" ";
    // cout<<'\n';
    cout<<ans[x]<<'\n';
}
 
int main() {
 
    fastio
    int t=1; 
    if(flag)cin>>t;
    while(t--){solve();}
 
    return 0;
}