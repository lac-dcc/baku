#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
 
 
int n,m;
vector<vector<int>> adj;
vector<bool> visited;
 
int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
		
	cin >> n >> m;
	adj.resize(n + 1);
	visited.resize(n + 1);
 
	for(int i = 0; i<m;i++){
		int x,y;
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
 
	queue<int> q;
 
	q.push(1);
	visited[1] = true;
 
	vector<int> path (n + 1);
 
	while(!q.empty()){
		
		int k = q.front();
		q.pop();
		for(auto a : adj[k]){
			if(visited[a]) continue;	
			visited[a] = true;
			q.push(a);
			path[a]  = k;
		
		}
	
	}
 
	if(!visited[n]){
		
		cout << "IMPOSSIBLE";
		return 0;
	}
	
	
	vector<int> ans = {n};
	int pos = n;
		
//	for(auto i : path){
//		cout << i << " ";
//	}
 
	while(pos != 1){
	//	cout << path[pos] << " ";
		ans.pb(path[pos]);
		pos = ans.back();
//	cout << "POS: " << pos << endl;	
	}
 
	reverse(ans.begin(),ans.end());
	cout << ans.size() << endl;
	
	for(auto a : ans) cout << a << " ";
 
	
		
 
 
}
