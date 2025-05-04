#include <bits/stdc++.h>
#define FOR(ii,aa,bb) for(int ii=aa;ii<bb;ii++)
#define for0(ii,bb) FOR(ii,0,bb)
#define for1(ii,bb) FOR(ii,1,bb+1)
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define st first
#define nd second
#define pii pair<int,int>
#define piii pair<int,pii>
#define pdi pair<double,int>
#define sp " "
#define nl "\n"
#define all(x) x.begin(),x.end()
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
 
using namespace std;
 
const int N = 2e5+5;
const int INF = 1e9+5;
const int mod = 1e9+7;
 
int n,dp1[N],dp2[N],ans[N];
vector<int> g[N];
 
void dfs1(int v,int p=-1){
	for(int u:g[v]){
		if(u==p)continue;
		dfs1(u,v);
		if(dp1[u]+1>dp1[v]){
			dp2[v]=dp1[v];
			dp1[v]=dp1[u]+1;
		}
		else if(dp1[u]+1>dp2[v])
			dp2[v]=dp1[u]+1;
	}
}
 
void dfs2(int v,int p=-1,int x=0){
	ans[v]=max(dp1[v],x);
	for(int u:g[v]){
		if(u==p)continue;
		if(dp1[u]+1==dp1[v])
			dfs2(u,v,max(x,dp2[v])+1);
		else
			dfs2(u,v,max(x,dp1[v])+1);
	}
}
 
signed main()
{	
  	#ifndef ONLINE_JUDGE
    	freopen("in.txt","r",stdin);
    	freopen("out.txt","w",stdout);
  	#endif
    fastio()   
    cin >> n;
    for(int i=1;i<n;i++){
    	int v,u;
    	cin >> v >> u;
    	g[u].pb(v);
    	g[v].pb(u);
    }
    dfs1(1);
    dfs2(1);
    for(int i=1;i<=n;i++)
    	cout << ans[i] << sp;
}
