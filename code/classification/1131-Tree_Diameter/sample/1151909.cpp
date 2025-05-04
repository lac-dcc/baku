#include<bits/stdc++.h>
using namespace std;
#define tez_chal ios::sync_with_stdio(0),cin.tie(0)
#define ll long long int
#define endl '\n'
#define fs first
#define se second
#define pb push_back
#define setbits(n) __builtin_popcount(n)
#define all(v) v.begin(),v.end()
#define deb(x) cout << #x << "=" << x << endl;
ll inf=(1LL<<63)-1;
const ll MOD=1e9+7;
int solve(){
	ll n;cin>>n;
	vector<vector<ll>>tree(n);
	for(ll i=0;i<n-1;i++){
		ll u,v;cin>>u>>v;
		u--;
		v--;
		tree[u].pb(v);
		tree[v].pb(u);
	}
 
	vector<pair<ll,ll>>dp(n);
	function<void(ll ,ll)> dfs=[&](ll u,ll par){
		dp[u].fs=1;
		dp[u].se=1;
		ll firstmax=0,secondmx=0;
		for(auto adj:tree[u]){
			if(adj==par) continue;
			dfs(adj,u);
			dp[u].fs=max(dp[adj].fs,dp[u].fs);
			dp[u].se=max(dp[adj].se+1,dp[u].se);
			if(dp[adj].se>=firstmax){
				secondmx=firstmax;
				firstmax=dp[adj].se;
			}else if(dp[adj].se>secondmx) secondmx=dp[adj].se;
		}
		dp[u].fs=max(dp[u].fs,firstmax+secondmx+1);
 
	};
	dfs(0,-1);
	cout<<dp[0].fs-1<<endl;
 
    return 0;
}
 
int main(){
    
    tez_chal;
    int t=1;        // cin>>t;
    while(t--) solve();
    
 
}
 
