#include <bits/stdc++.h>
using namespace std;
 
// typedef long long LL;
typedef vector<int> vi;
#define int long long
typedef pair<int, int> pi;
typedef pair<long long, long long> pL;
typedef vector<long long> vL;
typedef vector<vector<int>> vvi;
typedef vector<pair<int,int>> vpi;
typedef vector<vector<pair<int,int>>> vvpi;
#define LL long long
#define f first
#define s second
#define sz size()
#define pb emplace_back
#define pbs push_back
#define pops pop_back
#define mk make_pair
#define gcd __gcd
#define rep(i,n) for(LL i = 0; i < n; ++i)
#define REP(i,k,n) for(LL i = k; i <= n; ++i)
#define REPR(i,k,n) for(LL i = k; i >= n; --i)
#define all(a) a.begin(),a.end()
#define sett(a, x) memset((a), (x), sizeof(a))
#define show(a)  cout<<(a)<<endl
#define showv(v) rep(i,v.sz){cout<<v[i]<<" ";}; enter;
#define enter cout<<endl
 
//Constants
const int mod = 998244353 ;
const char nm = '\n';
 
//Mafs and funx
LL factorial(LL n) {
	return (n == 1 || n == 0) ? 1 : (n * factorial(n - 1)) % mod;
}
 
LL lcm(LL a, LL b) {
	return (a * b) / gcd(a, b);
}
 
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
 
int binary_search(vi vec, int x) {
	int k = 0, a = 0, b = vec.size() - 1 ;
	while (a <= b) {
		k = a + ( b - a) / 2;
		if (vec[k] == x) {
			return k;
		}
		if (vec[k] <  x) a = k + 1 ;
		else b = k - 1;
	}
	return k;
}
 
void solve() ;
int solve(string s);
signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	// your code goes here
 
	int q = 1;
	// cin >> q;
 
	while (q--) {
		solve();
	}
	return 0;
}
// LL comb(int n,int r){
// 	LL t=factorial(n)/factorial(r);
// 	return t/factorial(n-r);
// }
 
  long long power(  long long x,
                                  int y, int p)
{
      long long res = 1; // Initialize result
 
    x = x % p; // Update x if it is more than or
    // equal to p
 
    while (y > 0)
    {
     
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;
 
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
 
// Returns n^(-1) mod p
  long long modInverse(  long long n, 
                                            int p)
{
    return power(n, p - 2, p);
}
 
// Returns nCr % p using Fermat's little
// theorem.
  long long comb(  long long n,
                                 int r, int p)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;
 
    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
      long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;
 
 
    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)
           % p;
}
 
 
int n;
void solve(){
	 int m,q;
	 cin>>n>>m>>q;
	 vector<vector<LL>> dist(n,vL (n,LLONG_MAX));
	 // vector<vector<LL>> ans(n);
	 rep(i,m){
	 	LL x,y,z;
	 	cin>>x>>y>>z;
	 	dist[x-1][y-1]=min(dist[x-1][y-1],z);
	 	dist[y-1][x-1]=min(dist[y-1][x-1],z);
	 }
 
	 rep(i,n) dist[i][i]=0;
	 rep(k,n){
	 	rep(j,n){
	 		rep(i,n){
	 			if(dist[i][k]==LLONG_MAX or dist[k][j]==LLONG_MAX){
	 				continue;
	 			}
	 			dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
 
	 		}
	 	}
	 }
	 
	 while(q--){
	 	int src,dest;
	 	cin>>src>>dest;
	 	// dij(src-1,dest-1);
	 	if(src>dest) swap(src,dest);
	 	cout<<(abs(dist[src-1][dest-1])>=LLONG_MAX?-1:dist[src-1][dest-1])<<endl;
	 }
	 
 
}
