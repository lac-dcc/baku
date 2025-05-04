#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define long long int
//BFS
 
//inisde main
int vis[1000005];
vector<int> adj[1000005];
int storage[1000005];
int trigger = false;
void dfs(int cur, int counter){
	vis[cur] = true;
	
	if(counter %2 == 0) storage[cur] = 1;
	else storage[cur] = 2;
	
	for(int neigh : adj[cur]){
	    if(storage[cur] == storage[neigh]) trigger = true;
		if(not vis[neigh]){
			dfs(neigh, counter+1);
		}
	}
}
 
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //cout << storage[0];
    int n,m;
    cin >> n >>m;
    int a,b;
    
    
    for(int i =0;i<m;i++){
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for(int i =0;i<n;i++){
        if(not vis[i]){
            dfs(i,0);
        }
    }
    if(trigger) cout << "IMPOSSIBLE";
    else{
        for(int i =0;i<n;i++) cout << storage[i] << " ";
    }
}
