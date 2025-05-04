#include <bits/stdc++.h>
 
using namespace std;
 
const int maxn = 1e5 + 5;
const int maxm = 2e5 + 5;
 
vector<int> g[maxn];
vector<int> cycle;
int color[maxn];
int parent[maxn];
int cs = -1, ce;
 
bool dfs(int u, int p){
	color[u] = 1;
	for(int v : g[u]){
		if(v == p)continue;
		if(color[v] == 0){
			parent[v] = u;
			if(dfs(v, u)){
				return true;
			}
		}
		else if(color[v] == 1){
			cs = v;
			ce = u;
			return true;
		}
	}
	color[u] = 2;
	return false;
}
 
 
int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0 ; i < m ; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i = 1 ; i <= n ; i++){
		parent[i] = -1;
	}
	
	for(int u = 1 ; u <= n ; u++){
		if(dfs(u, 0)){
			break;
		}
	}
	if(cs == -1){
		printf("IMPOSSIBLE\n");
		return 0;
	}
	else{
		cycle.push_back(cs);
		for(int u = ce ; u != cs; u = parent[u]){
			cycle.push_back(u);
		}
		cycle.push_back(cs);
		reverse(cycle.begin(), cycle.end());
		int ret = cycle.size();
		printf("%d\n", ret);
		for(int i = 0 ; i < ret ; i++){
			printf("%d", cycle[i]);
			if(i != ret)printf(" ");
		}
		printf("\n");
	}
	return 0;
}
