#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5; const int inf=1e18;
//const int mod = 998244353;
const int mod = 1e9+7;
#define pb push_back
#define mp make_pair
#define sz size
#define fi first
#define se second
#define nl "\n"
#define ps(x) fixed<<setprecision(x)
#define all(x) (x).begin(), (x).end()
int gcd(int a, int b) { return b?gcd(b,a%b):a; }
//*****************************************************************************************//
 
void code(){	
	int n, m; cin>>n>>m;
	multiset<int, greater<int>>st;
	for(int i=0; i<n; i++){
		int a; cin>>a;
		st.insert(a);
	}
	vector<int>res;
	while(m--){
		int x; cin>>x;
		auto it=st.lower_bound(x);
		if(it==st.end())
			res.pb(-1);
		else{
			res.pb(*it);
			st.erase(it);
		}
	}
	for(auto u:res) cout<<u<<nl;
}
//How You Look at it is Petty Much How You'll See it!.
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	#ifndef ONLINE_JUDGE
	  freopen("input.txt", "r", stdin);
	  	freopen("output.txt", "w", stdout);
	#endif
 
	int T=1; //cin>>T;
	for(int i=1; i<=T; i++) code();
	
	#ifndef ONLINE_JUDGE
    	cerr<<"Actual : "<<1.0*clock()/CLOCKS_PER_SEC<<" sec\n";
	#endif
	return 0;
}
