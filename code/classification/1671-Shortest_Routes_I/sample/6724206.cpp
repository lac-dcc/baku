// Problem: Shortest Routes I
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1671
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
#include<bits/stdc++.h>
 
using namespace std;
#define int long long 
#define vi vector<int>
#define pb push_back
#define vvii vector<vector<int>>
#define vpii vector<pair<int,int>>
#define f first
#define s second
#define FOR(i,a,b) for (int (i) = (a); (i) < (b); ++(i))
#define REP(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int (i) = (b)-1; (i) >= (a); --(i))
#define PER(i,a) ROF(i,0,a)
#define rep(a) REP(_,a)
#define each(a,x) for (auto& a: x)
#define all(x) begin(x), end(x)
 
const int N = 2e5+3;
const int inf = 1e18;
vector<vector<pair<int,int>>> adj(N, vector<pair<int,int>>());
vector<int> dist(N, inf);
 
void dijkstra() {
	dist[1] = 0;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({0, 1});
	while(!pq.empty()) {
		int d = pq.top().first; 
		int u = pq.top().second; 
		pq.pop();
		if(dist[u] < d)
			continue;
		for(auto e : adj[u]) {
			int v = e.second; 
			int c = e.first; 
			if(dist[v] <= c+d) 
				continue;
			else {
				dist[v] = c+d;
				pq.push({dist[v], v});
			}
		}
	}
}
 
 
void solve(){
    int n,m;
    cin>>n>>m;
    
    REP(i,m){
    	int a,b,c;
    	cin>>a>>b>>c;
    	adj[a].pb({c,b});
    }
    dijkstra();
    for(int i=1;i<n+1;i++){
    	cout<<dist[i]<<" ";
    }
    cout<<endl;    
}
 
int32_t main(){
   int t=1;
   //cin>>t;
   while(t--){
   	solve();
   }
}
 
