/*lucifer__99 */
#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define ld long double
#define endl '\n'
#define pb push_back
#define sz(c) (ll)c.size()
#define mp make_pair
#define all(v) v.begin(),v.end()
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define F first
#define S second
#define M 1000000007
#define PI 3.1415926535897932384
#define pii pair<ll,ll>
 
const ll INF=1e18;
const ll N=1e5+5;
ll mod=998244353;
typedef pair<ll,ll> pi;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<pair<ll,ll>> vp;
typedef vector<vector<ll>> vvi;
typedef vector<vector<bool>> vvb;
typedef vector<vector<char>> vvc;
 
 
//bool isPrime(ll n){
//	if(n<=1)
//	return false;
//	if(n<=3)
//	return true;
//	if(n%2==0 || n%3==0)
//	return false;
//	for(ll i=5;i*i<=n;i=i+6)
//	{
//		if(n%i==0 || n%(i+2)==0)
//		return false;
//	}
//	return true;
//}
//ll fact(ll n) 
//{
//    ll ans=1;
//    for(ll i=1;i<=n;i++)
//	ans=(ans*i)%M ;
//	return ans;
//} 
//
//  
//
// 
//ll exp(ll x,ll n){
//	
//	ll res=1;
//	while(n>0){
//		if(n%2==1)
//		res=(res*x)%M;
//		x=(x*x)%M;
//		n=n/2;
//	}
//	return res;
//}
//
//
 
//ll nCr(ll n, ll k) 
//{ 
//    ll res = 1; 
//  
//    // Since C(n, k) = C(n, n-k) 
//    if(k>n-k){
//    	k=n-k;
//	}
//	
//    // Calculate value of 
//    // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1] 
//    for (ll i=0;i<k;i++) { 
//        res *= (n - i); 
//        res /= (i + 1); 
//    } 
//  
//    return res; 
//}
 
// nCr
 
//vector<ll> fact(N,0),invfact(N,0);
//void fac_init(){
// 	fact[0]=1;
//	fact[1]=1;
//	for(ll i=2;i<N;i++){
//		fact[i] = (fact[i-1]*i)%M;
// 	}
//	invfact[N-1]=exp(fact[N-1],M-2);
//	for(ll i=N-2;i>=0;i--){
//		invfact[i]= (invfact[i+1]*(i+1))%M;
//	}
//}
//ll ncr(ll n,ll r){
//	if(n<0 or r<0 or n<r)
// 	return 0;
//	return ((fact[n]*invfact[r])%M * invfact[n-r])%M;
//}
 
ll eval_dep(ll node,ll par,vvi &g,vi &dep){
    ll ans=0;
    // cout<<"f\n";
    for(auto &nbr:g[node]){
        if(nbr==par)
        continue;
        ans=max(ans,1+eval_dep(nbr,node,g,dep));
    }
    return dep[node]=ans;
}
ll solve(ll node,ll par,vi &dep,vi &dp,vvi &g){
    vi best;
    ll ans=0;
    if(dp[node]!=-1)
    return dp[node];
    for(auto &nbr:g[node]){
        if(nbr==par)
        continue;
        ans=max(ans,solve(nbr,node,dep,dp,g));
        best.pb(dep[nbr]);
    }
    sort(all(best));
    if(sz(best)==1){
        ans=max(ans,1+best[0]);
    }
    else if(sz(best)>=2){
        ans=max(ans,2+best[sz(best)-1]+best[sz(best)-2]);
    }
    return dp[node]=ans;
}
 
void null(){
    ll n;
    cin>>n;
    vvi g(n+1);
    rep(i,0,n-1){
        ll u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vi dep(n+1,0),dp(n+1,-1);
    eval_dep(1,0,g,dep);
    // cout<<"F";
    solve(1,0,dep,dp,g);
    cout<<*max_element(all(dp));
 
 
}
 
 
signed main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);    
    cout<<setprecision(4);
    cout<<fixed;
    ll t = 1;
    clock_t start, end; 
    start = clock(); 
//    fac_init();
 
    
//    #ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin); 
//    freopen("output.txt", "w", stdout);
//    freopen("error.txt", "w", stderr);
//    #endif
    // cin>>t;
//    compute();
    while(t--){
        null();
    }
 
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
    //cerr<<time_taken;
}
