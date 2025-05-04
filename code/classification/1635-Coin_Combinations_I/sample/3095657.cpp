#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(ll i=0;i<n;i++)
#define Fo(i,k,n) for(ll i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll  int
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define debv(x) cout<<#x<<" "; for(auto val: x) {cout<<val<<" ";} cout<<endl;
#define debm(x) cout<<#x<<endl; tr(it,x){cout<<it->first<<"-->"<<it->second<<endl;}
#define deba(x,n) cout<<#x<<" ";fo(i,n){cout<<x[i]<<" ";}cout<<endl;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define sortallr(x) sort(x.rbegin(),x.rend())
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
 
const int mod = 1'000'000'007;
const int N = 3e5, M = N;
//=======================
 
 
 
 
ll n, m;
 
ll fast_pow(ll a, ll p) {
  ll res = 1;
  while (p) {
    if (p % 2 == 0) {
      a = a * 1ll * a % mod;
      p /= 2;
    } else {
      res = res * 1ll * a % mod;
      p--;
    }
  }
  return res;
}
 
ll fact(ll n) {
  ll res = 1;
  for (ll i = 1; i <= n; i++) {
    res = res * 1ll * i % mod;
  }
  return res;
}
 
ll C(ll n, ll k) {
  return fact(n) * 1ll * fast_pow(fact(k), mod - 2) % mod * 1ll * fast_pow(fact(n - k), mod - 2) % mod;
}
 
 
ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
 
 
 
// ll dp(ll index,ll sum,ll ar[]){
// 	if(sum==0){
// 		return 1;
// 	}
// 	if(index==n){
// 		return 0;
// 	}
	
 
	
// 	if(mem[index][sum]!=-1){
// 		return mem[index][sum];
// 	}
// 	ll ans=0;
 
// 	ans+=dp(index+1,sum,ar);
 
// 	if(sum>=ar[index]){
		
// 		ans+=dp(index,sum-ar[index],ar);
// 	}
// 	ans%=mod;
	
// 	return  mem[index][sum] = ans;
// }
 
void solve() {
  
	cin>>n>>m;
	ll dp[m+1];
	memset(dp,0,sizeof(dp));
	ll ar[n+1];
	Fo(i,1,n+1){
		cin>>ar[i];
	}
	dp[0] = 1;
	Fo(i,1,m+1){
		Fo(j,1,n+1){
			if(i>=ar[j]){
				dp[i]+=dp[i-ar[j]];
				dp[i]%=mod;
			}
		}
	}
 
	cout<<dp[m]<<endl;
	
 
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
 
    #ifndef ONLINE_JUDGE
 
			freopen("inputf.txt", "r" , stdin);
			freopen("outputf.txt" , "w" , stdout);
			
		#endif
 
    ll t = 1;
    // cin>>t;
    while(t--) {
      solve();
    }
 
    return 0;
}
 
 