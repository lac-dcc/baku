#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>  
#include <ext/pb_ds/tree_policy.hpp>   
// #include <sys/resource.h>
using namespace std;
using namespace __gnu_pbds;
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
const long long infty = 1e18;
#define num1 1000000007
#define num2 998244353
#define rep(i,a,n) for(ll i=a;i<n;i++)
#define repd(i,a,n) for(ll i=a; i>=n; i--)
#define pb push_back
#define pob pop_back
#define f first
#define s second
#define fix(f,n) std::fixed<<std::setprecision(n)<<f
#define all(x) x.begin(), x.end()
#define M_PI 3.14159265358979323846
#define epsilon (double)(0.000000001)
#define popcount __builtin_popcountll
#define fileio(x) freopen("input.txt", "r", stdin); freopen(x, "w", stdout);
#define out(x) cout << ((x) ? "Yes\n" : "No\n")
#define sz(x) x.size()
#define vvll(vec,n,m) vector<vector<long long>> vec(n, vector<long long> (m))
#define start_clock() auto start_time = std::chrono::high_resolution_clock::now();
#define measure() auto end_time = std::chrono::high_resolution_clock::now(); cerr << (end_time - start_time)/std::chrono::milliseconds(1) << "ms" << endl;
 
 
typedef long long ll;
typedef long double ld;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;
typedef vector<pair<long long, long long>> vpll;
typedef vector<int> vii;
 
void getprime(ll n, vector<bool> &prime){
    // vector<bool> prime (n+1, true);
	prime[0] = prime[1] = false;
	for (ll i=2; i<=n; ++i)
		if (prime[i])
			if (i * 1ll * i <= n)
				for (ll j=i*i; j<=n; j+=i)
					prime[j] = false;
	
	// for(ll i=1; i<=n; i++){
	// 	cout<<i<<" "<<prime[i]<<endl;
	// }
}
 
void reverseVec(vll &v){
    ll n = v.size();
    rep(i, 0, n/2){
        swap(v[i], v[n-1-i]);
    }
}
 
ll sqr(ll x){
    return x*x;
}
 
void solve(){
    ll n, x;
    cin>>n>>x;
    map<ll, ll> mp;
    vpll v(n);
    rep(i, 0, n){
        ll a; cin>>a;
        v[i] = {a, i+1};
    }
    sort(all(v));
    ll l{}, r {n-1};
    while(l<r){
        if(v[l].f+v[r].f == x){
            cout<<v[l].s<<" "<<v[r].s<<endl;
            return;
        }
        else if(v[l].f+v[r].f >x){
            r--;
        }
        else l++;
    }
    cout<<"IMPOSSIBLE"<<endl;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    
    while(t--){
        solve();
    }
}
