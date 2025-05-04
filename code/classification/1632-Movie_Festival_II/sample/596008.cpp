#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define all(t) t.begin(), t.end()
#define inrange(i, a, b) (((i)>= min((a), (b))) && ((i) <= max((a), (b))))
typedef vector<ll> vi;
typedef pair<ll, ll> pii;
#define fi first
#define se second
#define show(x) cout << #x << " is " << x << "\n";
const ll inf = 2e18;
const ll mod = 1e9 + 7;
const ld pi = 3.141592653589793238462643383279502884;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void print(ll a[], ll n){for(ll i=0;i<n;i++){cout<<a[i]<<" ";}cout<<"\n";}
ll power(ll x, ll y, ll M = inf){
	if(y<=0) return 1;
    ll ans = 1;
    x %= M;
    while(y){
        if(y&1)
            ans = (x * ans) % M;
 
        x = (x * x) % M;
        y >>= 1;
    }
    return ans;
}
ll modInverse(ll n) {return power(n, mod-2, mod);}
inline ll mul(ll a, ll b){ return (a * b) % mod; }
inline ll sub(ll a, ll b){ ll c = a - b; if(c < 0) c += mod; return c; }
inline ll add(ll a, ll b){ ll c = a + b; if(c >= mod) c -= mod; return c; }
inline ll divi(ll a, ll b){ return mul(a, modInverse(b)); }
 
//------------------------------------------------------------------------------------------
 
//const ll N = 2e5 + 1;
//vector<ll> adj[N];
//bool visited[N];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout<<fixed<<setprecision(10);
 
	ll n, k;
	cin>>n>>k;
	pii a[n];
	for(int i=0;i<n;i++){
		cin>>a[i].se>>a[i].fi;
	}
	sort(a, a+n);
	ll ans=0;
	multiset<int> mst;
	for(int i=0;i<k;i++){
		mst.insert(0);
	}
	for(int i=0;i<n;i++){
		auto it = mst.upper_bound(a[i].se);
		if(it==mst.begin()) continue;
		mst.erase(prev(it));
		mst.insert(a[i].fi);
		ans++;
	}
	cout<<ans;
	return 0;
}
