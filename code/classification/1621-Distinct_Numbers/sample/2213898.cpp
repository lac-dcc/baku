  //*************************//
 // LET THE LIGHT GUIDE YOU //
//*************************//
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
 
#define rep(i,a,b) for(int i=int(a);i<=int(b);++i)
#define nrep(i,a,b) for(int i=int(a);i>=int(b);--i)
#define trv(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
 
#define err() cout<<"------------O_o------------"<<endl;
#define errA(A) for(const auto &i:A)   cout<<i<<" ";cout<<endl;
#define errAA(A) for(const auto &i:A) {for(const auto &j:i) cout<<j<<" ";cout<<endl;}
#define err1(a) cout<<#a<<" "<<a<<endl
#define err2(a,b) cout<<#a<<" "<<a<<" |"<<#b<<" "<<b<<endl
#define err3(a,b,c) cout<<#a<<" "<<a<<" |"<<#b<<" "<<b<<" |"<<#c<<" "<<c<<endl
#define err4(a,b,c,d) cout<<#a<<" "<<a<<" |"<<#b<<" "<<b<<" |"<<#c<<" "<<c<<" |"<<#d<<" "<<d<<endl
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define pb push_back
#define mt make_tuple
#define eb emplace_back
#define all(A) A.begin(),A.end()
#define chkbit(s, b) (s & (1<<b))
#define ZERO(A) memset(A,0,sizeof(A))
#define leadzero(a) __builtin_clz(a) // count leading zeroes
#define trailzero(a) __builtin_ctz(a) // count trailing zeroes
#define bitcount(a) __builtin_popcount(a) // count set bits (add ll)
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<pi> vpi;
typedef vector<string> vs;
typedef vector<vi> vvi;
const long long int mod = 1e9+7;
// const long long int mod = 998244353;
// mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
const string ln = "\n";
 
ll lpow(ll a, ll x, ll M = mod){
    if(a==0) return 0LL;
    if(x==0) return 1LL;
    ll res=1;a = (a%M+M)%M;
    while(x>0){ if(x&1LL) res = (res*a)%M; a= (a*a)%M; x = x>>1LL;}
    return res;
}
 
ll extendedEuler(ll a, ll b, ll *x, ll *y) { 
    if (a == 0) { *x = 0, *y = 1;return b;} 
    ll x1, y1, gcd = extendedEuler(b%a, a, &x1, &y1); 
    *x = y1 - (b/a) * x1; *y = x1; return gcd; 
}
 
ll modInverse(ll a, ll M=mod){
    ll x, y, g = extendedEuler(a, M, &x, &y); 
    if (g != 1) return -1; 
    else return (x%M + M) % M;
}
 
 
void solve(){
	int n; cin>>n;
	vector<int> a = vi(n);
	for(auto &c: a) cin>>c;
	sort(a.begin(), a.end());
	int ans = 1;
	for(int i=1;i<n;i++){
		if(a[i] != a[i-1]) ans++;
	}
	cout<<ans<<"\n";
	
}
 
 
int main(){
	int t=1;
	//cin>>t;
    // clock_t time_req;
    // time_req = clock();
	while(t--){ solve(); }
    // time_req = clock()-time_req;
    // cout<<"Time taken: "<<((float)time_req/CLOCKS_PER_SEC)*1000<<"ms"<<endl;
	
}
/*input
 
*/