#include <bits/stdc++.h>
#define ll long long 
#define ff first
#define ss second
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<ll, ll>
#define inf 1e20
#define elif else if
#define all(x) x.begin(),x.end()
#define fore(i,b) for(ll i=0;i<b;i++)
#define FORE(i,a,b) for(ll i=a;i<b;i++)
#define int long long
#define endll "\n"
#define kick(x) cout<<"Case #"<<x<<": "
#define mp make_pair
#define INT_MAX __LONG_LONG_MAX__
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x) //Nope;
#endif
 
 
typedef unsigned long long ull;
typedef long double lld;
 
using namespace std;
 
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
 
 
ll n=0;
const int mod = 1e9+7;
int tt=0;
 
int gcd(int a,int b){
	if(b==0) return a;
	return gcd(b,a%b);
}
 
long long power(long long x,long long y,long long m){
	if(y==0) return 1;
	if(y==1) return x;
	long long cur = power(x,y/2,m);
	cur = (cur%m * cur%m);
	if((y&1)) cur = (cur%m * x%m)%m;
	return cur;
}
 
long long modinv(long long x,long long m){ //M has to be prime, Fermat's Theorem states a^(p-2)==a^-1 (mod p)
	return power(x,m-2,m)%m;
}
 
void pre_solve(){
 
}
 
void sol(int tc){
	int m,k;
	cin>>n>>m>>k;
	int appts[n],des[m];
	fore(i,n) cin>>appts[i];
	fore(i,m) cin>>des[i];
	sort(appts,appts+n);
	sort(des,des+m);
	int i = 0,j=0,ans=0;
	while(i<n && j<m){
		if(abs(appts[i]-des[j])<=k){
			ans++;
			i++; j++;
		} else if(appts[i]<des[j]){
			i++;
		} else j++;
	}
	cout<<ans;
	return;
} 
 
int32_t main()
{  
 
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		freopen("error.txt","w",stderr);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tc=1;
	// cin>>tc;
	// pre_solve();
	while(tc--){
		tt++;
		sol(tc);
	}
 
	return 0;
} 
