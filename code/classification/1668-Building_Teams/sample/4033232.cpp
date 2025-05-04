#include<bits/stdc++.h>
 
using namespace std;
 
// This is Bipartite graph problem.
 
const int N = 1e5 + 1;
 
vector<int> adj[N];
 
int bp[N];
bool visited[N];
 
void dfs(int u, int mask = 0) { 
	if( bp[u] != -1) { return; }
	
	bp[u] = mask;	
	for(int v : adj[u]) { 
	   dfs(v, mask^1);
	}
}
 
void dfs2(int u, bool& flag) { 
   if(flag) return;
   visited[u] = 1;
   for(int v : adj[u]) { 
      if(bp[u] == bp[v]) {
      	flag = 1;
      	return;
      } else if(!visited[v]){
      	 dfs2(v, flag);
      }
   }
}
 
int main() {
	int n,m;
	memset(bp, -1, sizeof bp);
	cin >> n >> m;
	
	for(int i = 0, u, v; i < m ; i++) { 
		
		cin >> u >> v; u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	for(int i = 0; i < n; i++) { 
		if(bp[i] < 0) { 
		   dfs(i);
		}
	}
	
	memset(visited, 0, sizeof visited);
	
	bool flag = 0;
	
	for(int i = 0; i < n; i++) { 
		if(!visited[i])
		 dfs2(i, flag);
	}
	
	if(flag){
		cout<<"IMPOSSIBLE\n";
	} else {
		for(int i = 0; i < n; i++) { 
	   		cout<< bp[i] + 1 <<" ";
		}
		cout<<endl;
   }
	
}
