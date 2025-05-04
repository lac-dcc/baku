#include <bits/stdc++.h>
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define INF  (ll)1e18 + 5    /// 10^18 + 5
#define all(a)  a.begin(),a.end()
#define bitOn(i,j) ((i)&((ll)1<<j))
#define setBit(i,j) i=((i)|((ll)1<<j))
#define forn(i,n) for(int i=0;i<n;i++)
#define dbg(x) cout << #x"=" << x << '\n';
#define dbg2(x,y) cout << #x"=" << x << " " << #y"=" << y << '\n';
#define dbg3(x,y,z) cout << #x"=" << x << " " << #y"=" << y << " " << #z"=" << z << '\n';
const int MOD = 1e9 + 7;
const int mod = 998244353;
//更新前缀最大值
typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector < vi > vvi;
typedef vector < vll > vvll;
typedef pair <int,int> pii;
typedef pair <ll,ll> pll;
typedef vector < pii > vpii;
typedef vector < pll > vpll;
ll mo(ll x){ return x%MOD; }
 
ll t,n,k,m,h,m2;
 
struct custom_hash {
    static ll splitmix64(ll x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(ll x) const {
        static const ll FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>k;
	vi v(n);
	forn(i,n){ 
		cin>>v[i]; 
	}
	m = n/2;
	unordered_map<ll,int,custom_hash> m1;
	
	for(int i = 0; i < (1<<m); i++){
		int mask = i;
		int ind = 0;
		ll val = 0;
		while(mask){
			if(mask & 1) val+=v[ind];
			mask>>=1; ind++;
		}
		m1[val]++;
	}
	
	ll ans = 0;
	for(int i = 0; i < (1<<(n-m)); i++){
		int mask = i;
		int ind = m;
		ll val = 0;
		while(mask){
			if(mask & 1) val+=v[ind];
			mask>>=1; ind++;
		}	
		if( m1.count(k - val))
			ans+=m1[k - val];
	}
	cout<<ans<<'\n';
	
}
 
