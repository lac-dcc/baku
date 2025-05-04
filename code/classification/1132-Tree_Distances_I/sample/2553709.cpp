#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pb push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
const int MOD = 1000000007;
#define PI = acos(-1)
using namespace std ;
const int N = 2e5 + 5 ;
int n ;
vector<int> adj[N] , par(N) , in(N) , out(N) , vis(N);
void dfs(int node , int p){
	vis[node] = 1 ;
	par[node] = p;
	int ans = 0 ;
	bool flag  = 0 ;
	for(auto x : adj[node]){
		 if(!vis[x]){
		 	 flag = 1 ;
		 	 dfs(x , node);
		 	 ans = max(ans , in[x]);
		 }
	}
	
	if(flag){
	   in[node] = 1 + ans ;
	}
}
void dfs2(int node){
	vis[node] = 1 ;
	vector<int> ans ;
	for(auto x : adj[node]){
		  if(x != par[node]){
		  	  ans.pb(in[x]);
		  }
	}
	sort(ans.begin() , ans.end() , greater<int>());
	int mx1 = -1,mx2 = -1 ;
	if(ans.size() >= 2){
		 mx1 = ans[0];
		 mx2 = ans[1];
	}
	else if(ans.size() == 1){
		  mx1 = ans[0];
     }   
	for(auto x : adj[node]){
		 int u = mx1 ;
		 if(!vis[x]){
		 	 if(in[x] == mx1){
		 	 	 u = mx2 ;
			  }
		 	 out[x] = max(u + 2 , 1 + out[node]);
		 	 dfs2(x);
		 }
	}
	
}
signed main(){
   fastio ;
   cin >> n ; 
   int m = n-1 ;
   while(m--){
   	 int a , b ;
   	 cin >> a >> b ;
   	 adj[a].pb(b);
   	 adj[b].pb(a);
   }
   
   dfs(1, 0);
   for(int i = 1 ; i <= n ; i++) vis[i]  = 0;
   out[1]  = 0;
   dfs2(1);
    for(int i = 1 ; i <= n ; i++){
    	 cout << max(in[i] , out[i]) << " ";
	}
}
 
 
