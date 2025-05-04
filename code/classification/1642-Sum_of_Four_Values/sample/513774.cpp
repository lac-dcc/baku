#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define all(t) t.begin(), t.end()
#define inrange(i, a, b) (((i)>= min((a), (b))) && ((i) <= max((a), (b))))
typedef vector<ll> vi;
#define fi first
#define se second
#define show(x) cout << #x << " is " << x << "\n";
const ll inf = 9e18;
const ll mod = 1e9 + 7;
const ld pi = 3.141592653589793238462643383279502884;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void print(ll a[], ll n){for(ll i=0;i<n;i++){cout<<a[i]<<" ";}cout<<"\n";}
ll power(ll x, ll y){
    if(y<=0) return 1;
    ll ans = 1;
    x %= mod;
    while(y){
        if(y&1)
            ans = (x * ans) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return ans;
}
ll modInverse(ll n) {return power(n, mod-2);}
inline ll mul(ll a, ll b){ return (a * b) % mod; }
inline ll sub(ll a, ll b){ ll c = a - b; if(c < 0) c += mod; return c; }
inline ll add(ll a, ll b){ ll c = a + b; if(c > mod) c -= mod; return c; }
inline ll divi(ll a, ll b){ return mul(a, modInverse(b)); }
 
//------------------------------------------------------------------------------------------
 
//const ll N = 2e5 + 1;
//vector<ll> adj[N];
//bool visited[N];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout<<fixed<<setprecision(10);
 
	ll n, x;
	cin>>n>>x;
	ll a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	map<ll, pair<int, int> > mp;
    for(int i=0; i<n; i++){
        for (int j = i+1; j<n; j++){
            mp[a[i]+a[j]] = {i, j};
        }
    }
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			ll sum = a[i] + a[j];
            if (mp.find(x - sum) != mp.end()) {
                pair<ll, ll> p = mp[x - sum];
                if (p.fi != i && p.fi != j && p.se != i && p.se != j) {
                    cout<<i+1<<" "<<j+1<<" "<<p.fi+1<<" "<<p.se+1;
                    return 0;
                }
            }
		}
	}
	cout<<"IMPOSSIBLE";
 
 
	return 0;
}
