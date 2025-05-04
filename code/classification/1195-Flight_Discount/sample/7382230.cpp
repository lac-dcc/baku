#include<bits/stdc++.h>
using namespace std;
 
 
  
// Optimizations
// #pragma GCC optimize("PUSSY CHAT")
 #pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("bmi,bmi2,lzcnt,popcnt")
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("tune=native")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

#pragma GCC optimize ("Os")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("fast-math")
//#define _FORTIFY_SOURCE 0 
#pragma GCC optimize("no-stack-protector")
//  
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
#define int long long
 #define endl "\n"
void Dijkstra(int s, int n, vector<int> &dist, vector<int> &parent, vector<pair<int, int>>adj[]) {
	
	dist[s] = 0;
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({0, s});
	while (!q.empty()) {
		pair<int, int> here = q.top();
		q.pop();
		debug(here);
		int v = here.ss;
		int d_v = here.ff;
		if (d_v != dist[v])
			continue;
			
		for (auto edge : adj[v]) {
			
			if (dist[v] + edge.ss < dist[edge.ff]) {
				dist[edge.ff] = dist[v] + edge.ss;
				parent[edge.ff] = v;
				q.push({dist[edge.ff], edge.ff});
			}
		}
	}
}
	void path(int dest, int src, vector<int>&parent){
	vector<int>path;
	while(dest!=src){
		path.push_back(dest);
		dest=parent[dest];
		
	}
	path.push_back(dest);
	reverse(all(path));
	// print path;
	for(auto &x:path){
		cout<<x+1<<" ";
	}cout<<endl;
}
	
 
void solve(){
	int n;
	cin>>n;
	int m;
	cin>>m;
	vector<pair<int,int>>edges[n];
	vector<pair<int,int>>edges2[n];
	vector<pair<pair<int,int>,int>>v;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		a--;
		b--;
		v.pb({{a,b},{c}});
		
		edges[a].pb({b,c});
		edges2[b].pb({a,c});
	}
	
	//debug(edges);
	// src=0;
	vector<int>dis(n,INF);
	vector<int>par(n,-1);
Dijkstra(0,n,dis,par,edges);
vector<int>dis2(n,INF);
vector<int>par2(n,-1);
int y=INF;
 
	Dijkstra(n-1,n,dis2,par2,edges2);
	for(auto &x:v){
		auto x1=x.first;
		auto x2=x.second;
		auto l1=x1.first;
		auto l2=x1.second;
		debug(l1);
		debug(l2);
		debug(x2);
		int disx=dis[l1]+dis2[l2]+(x2/2);
		debug(disx);
		y=min(y,disx);
	}
	cout<<y<<endl;
}   
 
   
  
    
  
	
	
	
	
	
	
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
int t=1;
 
 
	while(t--){
	//	pfactor.clear();
	solve();
}
//}
}
