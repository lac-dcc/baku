#include <bits/stdc++.h>
 
using namespace std;
 
int n;
vector<int> adj[200001];
vector<int> dp(200001,-1);
int dfs(int u){
	if(dp[u]!=-1) return dp[u];
	dp[u]=0;
	for(auto k:adj[u]){
		dp[u]+=dfs(k)+1; 
	}
	return dp[u];	
}
 
int main(){
	cin>>n;
	for(int i=2;i<=n;i++){
		int a;
		cin>>a;
		adj[a].push_back(i);
	}
	for(int i=1;i<=n;i++){
		cout << dfs(i) << endl;
	}
	return 0;
}
 
