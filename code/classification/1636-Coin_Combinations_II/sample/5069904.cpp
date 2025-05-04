# include <bits/stdc++.h>
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
# define ll long long
# define pb push_back
# define f first
# define s second
# define siz(x) (int)(x).size()
# define vll vector<ll>
# define all(x) (x).begin(), (x).end()
 
using namespace std;
 
const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 9; 
const int N = 2e5 + 1;
 
void setIO(string name) {  
#ifndef ONLINE_JUDGE
    if((int)name.size() > 0){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
#endif
}
 
void solve();
 
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
    setIO("sublime");    //Does not work with Google     
    ll TC = 1;
    //cin >> TC;
    for(int i=0;i<TC;++i){
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}
 
// Do something good 
int dp[101][1000001];
void solve(){
	ll n,x; cin >> n >> x;
	vector<int> coins(n+1);
	for(int i=0;i<n;++i) cin >> coins[i];
	dp[0][0] = 1;
	for(int i=1;i<=n;++i){
		for(int j=0;j<=x;++j){
			if(j==0){
				dp[i][j] = 1;
				continue;
			}
			dp[i][j] = dp[i-1][j]%MOD;
			if(j>=coins[i-1]) dp[i][j] = (dp[i-1][j] + dp[i][j-coins[i-1]])%MOD;
		}	
	}
	cout << dp[n][x] << endl;
}
