// MAIN LIFE : COPY
// Editted by Vim
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
const ll N = 1e7;
const ll MOD = 1e9 + 7;
 
ll n,m;
ll a[N];
ll dp[N];
 
void solve(){
	dp[0] = 1;
	for(int j = 0; j < n;j++){
		for(int i = 1;i <= m;i++){
			if(i >= a[j]){
				dp[i] = (dp[i] + dp[i - a[j]]) % MOD;
			}
		}
	}
	/* for(int i =1;i <= m;i++)cout << dp[i] << " "; */
	cout << dp[m];
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	cin >> n >> m;	
	for(int i = 0;i < n;i++)
		cin >> a[i];
	solve();
	return 0;
}