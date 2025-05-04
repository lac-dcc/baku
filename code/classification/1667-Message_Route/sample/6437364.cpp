#include<bits/stdc++.h>
using namespace std;
typedef long long int       ll;
 
 
typedef vector < ll >                     vll;
typedef vector < int >                    vli;
typedef stack < int >                     stk;
typedef set < int >                       sli;
typedef set < ll >                        sll;
typedef pair < int, int >                 pii;
typedef pair < ll, ll >              	  pll;
typedef map < int,int >                   mli;
typedef map < ll,ll >                 	  mll;
typedef vector < pair < int, int > >  	  vpi;
typedef vector < pair < ll, ll > >   	  vpl;
 
#define cin(vec)                  for(auto& i : vec) cin >> i
#define cout(vec)                 for(auto& i : vec) cout << i << " "
#define fixed(x)                  fixed<<setprecision(x)
#define srt(h)                    (h).begin(), (h).end()
 
const int N = 1e5 + 9;
vli g[N];
bool vis[N];
int dis[N], par[N];
queue<int> qu;
void bfs(){
	vis[1] = true;
	qu.push(1);
	dis[1] = 0;
	while(!qu.empty()){
		int u = qu.front();
		qu.pop();
		for(auto v : g[u]){
			if(!vis[v]){
				qu.push(v);
				dis[v] = dis[u] + 1;
				par[v] = u;
				vis[v] = true;
			}
		}
	}
}
 
void solve(){
	int n, m;	cin >> n >> m;
	for(ll i = 0; i < m ; i++){
		int u, v;	cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	bfs();
	if(dis[n] == 0){
		cout << "IMPOSSIBLE" << '\n';
	}
	else{
		cout << dis[n]+1 << '\n';	
		vli path;
		int x = n;
		while(x != 1){
			path.push_back(x);
			x = par[x];
		}
		path.push_back(1);
		
		reverse(srt(path));
		for(ll i = 0; i < path.size() ; i++){
			if(i != path.size()-1) cout << path[i] << ' ';
			else cout << path[i] << '\n'; 
		}
	}
	
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
  	int t = 1;	//cin>>t;
  	while(t--){
  		solve();
  	}
	return 0;
}
