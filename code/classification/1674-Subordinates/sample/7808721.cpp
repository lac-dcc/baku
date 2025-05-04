#include <bits/stdc++.h>
 
#define ll long long
#define ull unsigned long long
#define ld long double
#define str string
 
#define nl "\n"
#define sp " "
#define OO (1e16)
#define Max_Int (1e9)
#define Max_LL (1e18)
 
#define sz(x) x.size()
#define fi first
#define se second
#define vec vector
#define pb push_back
 
#define all(p) p.begin(),p.end()
#define Mod(a, b) ((((a) % (b)) + (b)) % (b))
#define fixed(n) fixed << setprecision(n)
#define FastCode ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
 
using namespace std;
 
ll MOD = 1e9 + 7;
ll MOD2 = 998244353;
 
ll gcd(ll a,ll b){return ((a==0||b==0)?a+b:(a%b==0)?b:gcd(b,a%b));}
ll lcm(ll a,ll b){return a/gcd(a,b) * b;}
ll fastPower(ll a, ll b,ll m) {
    if(b==0) return 1;
    ll ans = fastPower(a,b/2,m);ans=((ans%m)*(ans%m))%m;
    return ((b&1)?((a%m)*(ans))%m:ans%m);
}
ll myPower(ll a,ll b){
    if(b==0) return 1;
    int ans = myPower(a,b/2);return ((b&1)? a*ans*ans:ans*ans);
}
ll mod_inv(ll x,ll M = (1e9+7)){return (fastPower(x,M - 2,M))%M;}
 
ll max(ll a,ll b){return (a>=b) ? a : b;}
ll min(ll a,ll b){return (a>=b) ? b : a;}
 
 
 
void Fast_IO(){
    // ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
    #endif
}
 
 
// ----------------------------- --{ code }-- ----------------------------- //
 
vec<int> ans;
vec<vec<int>> arr;
 
void dfs(int nood){
    for(int next_nood : arr[nood]){
        dfs(next_nood);
        ans[nood] += ans[next_nood] + 1;
    }
}
 
void Solve(){
    
    int n;cin>>n;
    arr.assign(n+2,vec<int>(0));
    ans.assign(n+2,0);
    for(int i = 2;i <= n;i++){
        int a;cin>>a;
        arr[a].push_back(i);
    }
    dfs(1);
    for(int i = 1; i <= n; i++){
        cout<<ans[i]<<sp;
    }
 
}
 
 
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    Fast_IO();
    int tc = 1;
    // cin>>tc;
    while(tc--){
        Solve();
    }
 
    return 0;
}
 
 
 
 
 
 
 
