#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define z (1000000000+7)
#define ld long double
#define ui unsigned int
#define ull unsigned ll
#define mp                   make_pair
#define eb                   emplace_back
#define pb                   push_back
#define pf                   push_front
#define popb                 pop_back
#define popf                 pop_front
#define hashmap              unordered_map
#define hashset              unordered_set
#define lb                   lower_bound
#define ub                   upper_bound
#define all(a)               (a).begin(), (a).end()
#define rall(a)              (a).rbegin(), (a).rend()
#define ff                   first
#define ss                   second
#define foi(n) for(ll i=0;i<n;i++)
#define foj(n) for(ll j=0;j<n;j++)
#define fok(n) for(ll k=0;k<n;k++)
#define forr(i,a,b) for(ll i=a;i<b;i++)
#define forrr(i,b,a) for(ll i=b;i>=a;i--)
#define forrrr(i,a,b,k) for(ll i=a;i<b;i=i+k)
#define graph          vector<vector<int>>
#define sz(v) v.size()
const ull mod=1e9+7;
typedef pair<int, int> pii;
typedef pair<ll, ll>   pll;
typedef vector<int>         vi;
typedef vector<ll>          vll;
typedef vector<string>      vs;
typedef vector<double>      vd;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;
typedef pair<ll, pll>      plll;
typedef vector<plll>      vplll;
typedef  vector<string> 	     vs;
typedef  vector<char>	         vc;
typedef  vector<bool>            vb;
typedef  map<string, int>         msi;
typedef  map<int, int>	         mii;
typedef  map<ll, ll>             mll;
typedef  map<char, int>           mci;
typedef  map<int, string>	     mis;
typedef  pair<string, int>       psi;
typedef  pair<string, string>    pss;
typedef priority_queue<pii, vector<pii>, greater<pii> > pqq;
void solve();
//ull findgcd(ull *, ull);
//ull gcd(ull, ull);
int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(NULL);
 
//#ifndef ONLINE_JUDGE
//	freopen("input1.txt", "r", stdin);
//	freopen("error1.txt", "w", stderr);
//	freopen("output1.txt", "w", stdout);
//#endif
	ll t;
	cin>>t;
	while(t--){	
		solve();
		cout<<endl;
	}
//	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
void solve(){
	ll y,x,sum;
	cin>>x>>y;
	if(y>=x){
		if(y%2==0){
			sum=(y-1)*(y-1)+x;
		}
		else{
			sum=y*y+1-x;
		}
	}
	else{
		if(x%2==0){
			sum=x*x-y+1;
		}
		else{
			sum=(x-1)*(x-1)+y;
		}
	}
	cout<<sum;
}
