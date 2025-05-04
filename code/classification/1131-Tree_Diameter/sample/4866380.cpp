#include <bits/stdc++.h>
using namespace std;
void fast(){ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
 
vector<int> a[200005];
int idx, ans=0;
void bfs(int node){
	queue<tuple<int,int,int>> q;
	q.push({node, 0, 0}); //node, par, dist
	while(!q.empty()){
		auto[u, p, d]=q.front(); q.pop();
		if(d>ans){
			ans=d;
			idx=u;
		}
		for(auto i:a[u]){
			if(i==p) continue;
			q.push({i, u, d+1});
		}
	}
}
int main(){
	fast();
	int n; cin>>n;
	for(int i=1; i<n; i++){
		int x, y; cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	bfs(1);
	bfs(idx);
	cout<<ans;
}
 
/*
vector<int> a[200005];
int dp[200005][2];
void dfs(int node, int par){
	for(auto i:a[node]){
		if(i==par) continue;
		dfs(i, node);
	}
	for(auto i:a[node]){
		if(i==par) continue;
		dp[node][0]+=max(dp[i][0], dp[i][1]);
	}
	for(auto i:a[node]){
		if(i==par) continue;
		dp[node][1]=max(dp[node][1], 1+dp[i][0]+(dp[node][0]-max(dp[i][0], dp[i][1])));
	}
}
int main(){
	fast();
	int n; cin>>n;
	for(int i=1; i<n; i++){
		int x, y; cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1, 0);
	cout<<max(dp[1][0], dp[1][1]);
}
*/
/*
vector<int> a[200005];
int child[200005];
void dfs(int x){
	int sum=0;
	for(auto i:a[x]){
		dfs(i);
		sum+=1+child[i];
	}
	child[x]=sum;
}
int main(){
	fast();
	int n; cin>>n;
	for(int i=2; i<=n; i++){
		int x; cin>>x;
		a[x].push_back(i);
	}
	dfs(1);
	for(int i=1; i<=n; i++) cout<<child[i]<<' ';
}
*/
