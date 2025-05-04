#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vint;
typedef vector<vint> vvint;
typedef vector<bool> vbool;
typedef vector<vbool> vvbool;
typedef pair<ll, ll> pll;
#define ff first
#define ss second
#define FAST_IO	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fileInput freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#ifdef largeInteger
	#include <boost/multiprecision/cpp_int.hpp>
	using namespace boost::multiprecision;
	// Use 'cpp_int' instead of 'int'
#endif
#ifdef useOrderedSet
	#include <ext/pb_ds/assoc_container.hpp>
	#include <ext/pb_ds/tree_policy.hpp>
	using namespace __gnu_pbds;
	#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
	// os.find_by_order(int order), os.order_of_key(int val)
#endif
 
int main(){
	FAST_IO
	
	int n;
	cin >> n;
	vint a(n + 1), b(n + 1), c(n + 1);
	map<ll, ll> dayIdx; // map from day to its corresponding index.
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> b[i] >> c[i];
		dayIdx[a[i]], dayIdx[b[i]];
	}
	int m = 1;
	for(auto& i:dayIdx){
		i.ss = m++;
	}
	m--;
	vector<vector<pll>> projects(m + 1);
	for(int i = 1; i <= n; i++){
		projects[dayIdx[b[i]]].push_back({dayIdx[a[i]], c[i]});
	}
	vint dp(m + 1, 0); // dp[i] = max money that can be earned till the day corresponding to the index i;
	dp[0] = 0; // No project has begun yet
	for(int i = 1; i <= m; i++){
		dp[i] = dp[i - 1]; // You did nothing on day i
		for(auto& p:projects[i]){ // Among the projects ending on day i, choose the best one.
			dp[i] = max(dp[i], dp[p.ff - 1] + p.ss);
		}
	}
	cout << dp[m];
	
	return 0;
}