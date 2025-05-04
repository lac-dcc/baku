#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
const int N = 1e5 + 9;
vector <int> G[N];
bool vis[N];
int par[N];
int start_cycle, end_cycle;
 
void dfs(int u){
	vis[u] = true;
	for (int v : G[u]){
		if(v == par[u]) continue;
		if(!vis[v]){
			par[v] = u;
			dfs(v);
		}
		else if(vis[v]){
			start_cycle = u;
			end_cycle = v;
		}
	}
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i ++){
    	int u, v; cin >> u >> v;
    	G[u].push_back(v);
    	G[v].push_back(u);
    }
 
    start_cycle = -1, end_cycle = -1;
    for(int i = 1; i <= n; i ++){
    	if(!vis[i]) dfs(i);
    }
 
    if(start_cycle == -1 and end_cycle == -1){
    	cout << "IMPOSSIBLE\n";
    	return 0;
    }
    vector <int> cycle;
    cycle.push_back(start_cycle);
    int cur = end_cycle;
    while(cur != start_cycle){
    	cycle.push_back(cur);
    	cur = par[cur];
    }
    cycle.push_back(start_cycle);
 
    cout << cycle.size() << '\n';
    for (int v : cycle){
    	cout << v << ' ';
    }
    cout << '\n';
    return 0;
}
