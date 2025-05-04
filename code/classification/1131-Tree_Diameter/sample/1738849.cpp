// fuck this man !!
 
#include<bits/stdc++.h> 
#include <iostream> 
#include <vector> 
#include <iterator>
using namespace std;
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define f(i,x,n) for(int i=x;i<(int)n;++i)
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define pq priority_queue<int>
#define pqs priority_queue<int,vi,greater<int>>	
#define vpii vector<pair<int,int>>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define mpi map<int,int>
#define lb lower_bound //lower_bound returns an iterator pointing to the first element in the range [first,last) which has a value not less than ‘val’. 
#define ub upper_bound // upper_bound returns an iterator pointing to the first element ian the range [first,last) which has a value greater than ‘val’. 
 
 
int mod=1e9+7;
const int mxn=210000;
 
vi adj[mxn];
int dp[mxn];
 
int ans=1;
 
void dfs(int s,int p){
	dp[s]=1;
	vi vp;
	for(auto it : adj[s]) if(it!=p) {dfs(it,s); dp[s]=max(dp[s],1+dp[it]); vp.pb(dp[it]);}
	if(sz(vp)>=2){
		sort(all(vp));
		int yy=sz(vp); 
		int here=vp[yy-1] + vp[yy-2];
		ans=max(ans,here+1);		
	}else if(sz(vp)==1){
		ans=max(ans,vp[0]+1);
	}
}
 
void solve(){ 
	int n; cin>>n;
	//int a[n]; f(i,1,n) cin>>a[i]; f(i,1,n) --a[i];
	f(i,1,n){
		int u,v; cin>>u>>v; --u; --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(0,-1);
	//f(i,0,n) cout<<dp[i]<<" "; cout<<"\n";
	cout<<ans-1<<"\n";
}
 
 
int32_t main(){
 	ios_base::sync_with_stdio(false);cin.tie(NULL);	
	srand(time(0));
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int t=1; //cin>>t;
	while(t--) solve();
	return 0;
}
 
 
