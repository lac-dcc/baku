// Problem: Edit Distance
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1639
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
#include <bits/stdc++.h>
#include <algorithm>
#define ll long long
#define all(n) (n).begin(), (n).end()
#define endl "\n"
#define MOD 1000000007
#define printv(a) {for(auto u:a) cout<<u<<" "; cout<<endl;}
#define rall(a) (a).rbegin(),(a).rend()
using namespace std;
 
 
 
void solve(){
	string a,b;
	cin>>a>>b;
	ll n = a.length();
	ll m = b.length();
	vector<vector<ll>> dp(n+1,vector<ll>(m+1,0));
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0){
				dp[i][j]=j;
			}
			else if(j==0){
				dp[i][j]=i;
			}else if(a[i-1] == b[j-1]){
				dp[i][j] = dp[i-1][j-1];
			}else{
				dp[i][j] = min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]})+1;
			}
		}
	}
	// for(auto& x:dp){
		// for(auto& y:x){
			// cout << y << " ";
		// }
		// cout << endl;
	// }
	cout << dp[n][m] << endl;
}
 
 
 
int32_t main() 
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	clock_t z = clock();
	int tc=1;
	//cin >> tc;
	while (tc--) solve();
	cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
	return 0;
}
