/**************************
*                         *
*    Author: Sukesh       *
*                         *
***************************/
#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define int long long int
using namespace std;
 
const int N = 1e5+10;
vector<int> graph[N];
vector<bool> visited(N,0);
vector<int> parent(N,-1);
 
bool cycleDetectionUndirectedGraph(int node, int par){
    parent[node] = par;
    visited[node] = 1;
 
    for(auto it : graph[node]){
        if(!visited[it])
            cycleDetectionUndirectedGraph(it, node);
        else if(it!=par){
            vector<int> cyc;
 
            int cur = node;
 
            cyc.emplace_back(node);
 
            while(parent[cur] != it){
               cur = parent[cur];
               cyc.emplace_back(cur);
            }
 
            cyc.emplace_back(it);
            cyc.emplace_back(node);
 
            cout << cyc.size() << '\n';
 
            for(auto x : cyc) cout << x <<" ";
            exit(0);
        }
    }
    return 0; 
}
 
void solve(){
    FIO;
    int n, e; cin >> n >> e;
    for(int i = 0; i<e;i++){
	    int u, v;
	    cin >> u >> v;
	    graph[u].push_back(v); 
	    graph[v].push_back(u); 
	}
 
    for(int i = 1; i<=n; i++)
        if(!visited[i])
            cycleDetectionUndirectedGraph(i,-1);
 
    cout << "IMPOSSIBLE\n";
 
    return;
}
 
signed main(){
    FIO;
    
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
 
    int t=1;
    while(t--)
        solve();
        
    return 0;
}
