#include <bits/stdc++.h>
using namespace std;
 
vector< vector<int> >adj;
vector<bool> visited;
vector<int> par;
int main(){
	int n, m; cin >> n >> m;
	adj.resize(n); visited.assign(n,false);
	par.assign(n,-1);
	for(int i=0; i<m; i++){
		int a, b; cin >> a >> b;
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
	queue<int> q;
	q.push(0); visited[0] = true;
 	while(!q.empty()){
		int p = q.front(); q.pop();
		for(int i=0; i<adj[p].size(); i++){
			if(visited[adj[p][i]])
				continue;
			visited[adj[p][i]] = true;
			par[adj[p][i]] = p;
			q.push(adj[p][i]);
		}
	}
	if(par[n-1]==-1)
		cout << "IMPOSSIBLE" << endl;
	else{
		vector<int> path;
		int i=n-1;
		while(true){
			path.push_back(i+1);
			if(i==0)
				break;
			i = par[i];
		}
		reverse(path.begin(),path.end());
		cout << path.size() << endl;
		for(int i=0; i<path.size(); i++)
			cout << path[i] << " ";
	}
}
