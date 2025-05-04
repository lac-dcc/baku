#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<queue>
#include<cmath>
#include<iomanip>
#include<set>
#include<map>
using namespace std;
#define ll long long
#define pb push_back
#define pll pair<ll,ll> 
#define mll map<ll,ll>
#define pii pair<int,int>
#define vpii vector<pii>
#define rep(i,n) for(int i=0; i<n; i++)
#define All(x,v) for(auto x:v)
#define arrin(a,n) ll a[n]; rep(i,n) cin>>a[i]
#define vi vector<int>
#define vll vector<ll>
#define nl "\n"
#define print(arr) All(x,arr) cout<<x<<" "; cout<<nl
#define sz(x) (int)x.size()
#define all(v) v.begin(),v.end()
#define ing(m,ad) rep(i,m){ int u,v; cin>>u>>v; u--;v--; ad[u].pb(v); ad[v].pb(u);}
#define vdsort(v) sort(v.begin(),v.end(),greater<int>())
#define F first
#define S second
#define mod 1000000007
const int MAXN=100005;
int spf[MAXN];
ll fac1[MAXN],fac2[MAXN],inv[MAXN];
ll gcd(ll x, ll y){ return y?gcd(y,x%y):x; }
 
template <typename C, typename T = std::decay_t<decltype(*begin(std::declval<C>()))>, typename std::enable_if<!std::is_same<C, std::string>::value>::type * = nullptr>
std::ostream &operator<<(std::ostream &os, const C &container)
{
	bool first = true;
	std::stringstream ss;
	ss << '[';
	for (const auto &x : container)
	{
		if (!first)
		{
			ss << ", ";
		}
		first = false;
		ss << x;
	}
	ss << ']';
	return os << ss.str();
}
template <class T1, class T2>
std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &p)
{
	os << '{' << p.first << ", " << p.second << '}';
	return os;
}
vector<string> vec_splitter(string S)
{
	S += ',';
	vector<string> res;
	while (!S.empty())
	{
		res.push_back(S.substr(0, S.find(',')));
		S = S.substr(S.find(',') + 1);
	}
	return res;
}
void debug_out(vector<string> __attribute__((unused)) args, __attribute__((unused)) int idx, __attribute__((unused)) int LINE_NUM)
{
	cerr << "\n";
}
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T)
{
	if (idx > 0)
		cerr << ", ";
	else
		cerr << "Line(" << LINE_NUM << ") ";
	stringstream ss;
	ss << H;
	cerr << args[idx] << " = " << ss.str();
	debug_out(args, idx + 1, LINE_NUM, T...);
}
#ifdef DEBUG
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif
 
void sieve(){  
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++)  spf[i] = i; 
    for (int i=4; i<MAXN; i+=2) spf[i] = 2; 
    for (int i=3; i*i<MAXN; i++) { 
        if (spf[i] == i) 
            for (int j=i*i; j<MAXN; j+=i) 
                if (spf[j]==j)  spf[j] = i; 
    } 
} 
vector<int> getFactorization(int x){
    vector<int> ret; 
    while (x != 1) { 
        ret.push_back(spf[x]); 
        x = x / spf[x]; 
    } 
    return ret; 
}
 
ll exp(ll n, ll m){
    ll a = 1;
    while (m){
        if (m & 1) a = (a * n % mod) % mod;
        m /= 2;
        n = (n*n) % mod;
    }
    return a;
}
 
void pre(){
    fac1[0]=fac2[0]=inv[1]=1;
    for(int i=1;i<MAXN;i++){
        fac1[i]=(fac1[i-1]*i)%mod;
        if(i>1) inv[i]=( mod - ((ll)(mod/i)*inv[mod%i])%mod ) %mod;
    }
    for(int i=1;i<MAXN;i++) fac2[i]=(fac2[i-1]*inv[i])%mod;
}
ll C(int n,int k){
    if(n<k) return 0;
    return ((fac1[n]*fac2[n-k]%mod)*fac2[k]%mod);
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    int n, m, tt=1;
    string s,t;
    // cin>>t;
    while(tt--){
        cin>>s>>t;
        n = sz(s), m = sz(t);
        ll dp[n+1][m+1];
        dp[0][0] = 0;
        rep(i,n) dp[i+1][0] = i+1;
        rep(i,m) dp[0][i+1] = i+1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                dp[i][j] = min({dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + (s[i-1] != t[j-1])});
            }
        }
        // rep(i,n+1) {rep(j, m+1) cout<<dp[i][j]<<" "; cout<<nl;}
        cout<<dp[n][m]<<nl;
    }
    return 0;
}
