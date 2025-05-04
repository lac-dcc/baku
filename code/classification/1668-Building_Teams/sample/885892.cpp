#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod 			1000000007
#define tc(t) 			int t;cin >> t;while(t--)
#define for0(i , n)		for(int i=0;i<n;i++)
#define loop(i , a, b)	for(int i=a;i<=b;i++)
#define endl 			'\n'
#define inf 			1e18
#define fi 				first
#define se 				second
 
int XX[8]={+1, +1, +1, 0, 0, -1, -1, -1};
int YY[8]={+1, 0, -1, +1, -1, +1, 0, -1};
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};
 
vector<int> adj[200005];
int color[200005],vis[200005];
int n,m,fl=1;
 
void dfs(int node,int par=-1,int col=0){
	vis[node]=1;
	color[node]=col;
	for(auto it: adj[node]){
		if(!vis[it]){
			dfs(it,node,!col);
		}else if(it!=par && color[node]==color[it]){
			fl=0;
		}
	}
}
 
 
signed main() {
 
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt" , "r" , stdin);
// 	freopen("output.txt" , "w" , stdout);
// #endif
 
	cin>>n>>m;
 
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
 
	memset(vis,0,sizeof(vis));
 
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i);
		}
	}
 
	if(fl){
		for(int i=1;i<=n;i++){
			cout<<color[i]+1<<" ";
		}		
	}else{
		cout<<"IMPOSSIBLE"<<endl;
	}
 
	return 0;
}
