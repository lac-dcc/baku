#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long int li;
typedef unsigned long long int ulli;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
void init_code(){
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
int dfs(int node,vector<int> adj[],vector<bool> &visited,vector<int> &dp){
	visited[node]=true;
	int count=0;
	for(auto it: adj[node]){
		if(!visited[it]){
			count+=dfs(it,adj,visited,dp);
		}
	}
	dp[node]=count;
	return count+1;
}
int main(){
    init_code();
    int n;
    cin>>n;
    vector<int> adj[n+1];
    for(int i=2;i<=n;i++){
    	int x;
    	cin>>x;
    	adj[x].push_back(i);
    }
    vector<bool> visited(n+1,false);
    vector<int> dp(n+1,0);
    for(int i=1;i<=n;i++){
    	if(visited[i]) continue;
		dfs(i,adj,visited,dp);
    }
    for(int i=1;i<=n;i++){
    	cout<<dp[i]<<" ";
    }
	
}
