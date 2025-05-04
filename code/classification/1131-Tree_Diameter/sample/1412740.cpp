#include <bits/stdc++.h>
using namespace std;
#define int long long
 
vector<vector<int>>adj;
 
vector<int>dp;
vector<int>dia;
 
 
void solve(int src, int par)
{
    int ans = 0;
    vector<int> vect;
    for(int child : adj[src])
    {
        if(child != par)
        {
            solve(child, src);
            vect.push_back(dp[child]);
            ans = max(ans, dia[child]);
        }
    }
    int n = vect.size();
    sort(vect.begin(),vect.end());
 
    if(n == 0)dia[src] = 0;
    else if(n == 1)dia[src] = 1 + vect[0];
    else dia[src] = 2+vect[n - 1]+vect[n - 2];
 
    dia[src] = max(dia[src], ans);
}
 
void downPath(int u,int par){
 
	int bestChildPath = 0;
	int leaf = 1;
 
	for(auto v : adj[u]){
		
		if(v != par){
			leaf = 0;
			downPath(v,u);
			bestChildPath = max(bestChildPath,dp[v]);
		}
 
	}
 
	if(leaf){
		dp[u] = 0;
	}else{
		dp[u] = 1 + bestChildPath;
	}
}
 
int32_t main(){
 
	int n; cin >> n;
	adj.resize(n+1);
	dp.resize(n+1);
	dia.resize(n+1);
 
 
	for(int i = 1; i < n; i++){
 
		int u,v; cin >> u >> v;
 
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
 
	downPath(1,0);
	
	solve(1,0);
 
	cout << dia[1] << endl;
 
}
