#include <bits/stdc++.h>
using namespace std;
 
#define all(v) v.begin(),v.end()
#define ll long long
#define int ll
#define pb push_back
typedef vector<int> vi;
 
const int inf = 2e5 + 100;
 
void init(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
 
}
 
vector<vi> adjlist;
vector<bool> visited;
vi foredges;
 
void dfs(int node,int parent){
	visited[node] = true;
 
	for (auto x : adjlist[node]){
		if (! visited[x] && x != parent){
			visited[x] = true;
			dfs(x,node);
		}
	}
}
 
 
 
int32_t main()
{
	init();
	
	int n,m;
	cin >> n >> m;
 
	visited.assign(n,false);
	adjlist.assign(n,vi());
 
	for (int i = 0; i < m; ++i)
	{
		int a,b;
		cin >> a >> b;
		a--;b--;
 
		adjlist[a].pb(b);
		adjlist[b].pb(a);
 
	}
	int ans = 0;
 
	for (int i = 0; i < n ; ++i)
	{
		if (! visited[i]){
			ans++;
			foredges.pb(i);
			dfs(i,-1);
		}
	}
 
	cout << ans-1 << endl;
	for (int i = 0; i < ans-1; i++){
		cout << foredges[i]+1 << " " << foredges[i+1]+1 << endl;
	}
 
	return 0;
}
 
