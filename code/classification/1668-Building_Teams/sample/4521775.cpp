#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 
const int N = 1e5 + 10, OO = 0x3f3f3f3f;
 
 
int col[N];
vector < int > adj[N];
bool vis[N];
bool hasCycle;
 
void dfs(int src){
	vis[src] = 1;
	for(auto ch : adj[src]){
		if(col[ch] == OO){
			col[ch] = 1 - col[src];
			dfs(ch);
		}
		else if(col[ch] == col[src]){
			hasCycle = 1;
			return;
		}
	}
}
 
 
int main(){
	
	//freopen("haybales.in", "r", stdin);
	//freopen("haybales.out", "w", stdout);
	
	
	memset(col, OO, sizeof col);
	int n , m;
	cin >> n >> m;
	for(int i = 0 ; i < m; ++i){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	for(int i = 1; i <= n ; ++i){
		if(!vis[i]){
			col[i] = 0;
			dfs(i);
		}
	}
	if(hasCycle) cout << "IMPOSSIBLE\n";
	else{
		for(int i = 1 ; i <= n; ++i)
			cout << col[i] + 1 << " ";
		cout << "\n";
	}
 
 
 
	return 0;	
}
