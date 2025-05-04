/*--ILRS-- sr4saurabh  */
#include <bits/stdc++.h>
using namespace std; 
typedef long long int ll;
#define pb push_back 
#define popb pop_back
#define mp make_pair
#define ve vector
#define vii vector < int >
#define vll vector < ll > 
#define pii pair < int , int >
#define pll pair < ll , ll >
#define vpl vector < pll >
#define fi first
#define sz size 
#define len length 
#define se second 
//const ll mod=998244353;
const ll mod = 1000000000+7;
const ll N=10000000+6;
#define M_PI           3.14159265358979323846
//--------------------------------------------
ll n,m;
vpl adj[100001];
vpl adj2[100001];
vll dist(100001,1e17);
vll distb(100001,1e17);
vii vis(100001);
ll ans = (ll)(1e18);
std::vector<pair<pll,ll>> edge;
//--------------------------------------------
void dijkstra(){
 
	multiset<pll> s;
	s.insert(mp(0,1));
	
	while(!s.empty()){
 
		pll p = *s.begin();
		s.erase(s.begin());
		
 
		if(p.fi != dist[p.se]) continue;
		ll node = p.se;
		ll cost = p.fi;
		
 
		for(pll curr : adj[node]){
 
			if(curr.se + dist[node] < dist[curr.fi]){
 
				dist[curr.fi] = curr.se + dist[node];
				s.insert(mp(dist[curr.fi],curr.fi));
			}
			
 
		}
 
	}
 
}
//-------------------------------------------
void dijkstraback(){
 
	multiset<pll> s;
	s.insert(mp(0,n));
	
	while(!s.empty()){
		
		pll p = *s.begin();
		s.erase(s.begin());
		
		if(p.fi != distb[p.se]) continue;
		ll node = p.se;
		ll cost = p.fi;
	
 
		for(pll curr : adj2[node]){
 
			if(curr.se + distb[node] < distb[curr.fi]){
 
				distb[curr.fi] = curr.se + distb[node];
				s.insert(mp(distb[curr.fi],curr.fi));
			}
			
 
		}
 
	}
 
}
//-----------------------------------------
/*void dfs(int v){
	vis[v] = 1;
 
	for(pll p : adj[v]){
		ans = min(ans,hmap[mp(v,p.fi)]/2 + distb[p.fi]+dist[v]);
		if(!vis[p.fi])
			dfs(p.fi);
	}
*/
//------------------------------------------
/*void dfs2(int v){
	vis[v] = 1;
 
	for(pll p : adj2[v]){
		ans = min(ans,p.se/2 + distb[p.fi]+dist[v]);
		if(!vis[p.fi])
			dfs2(p.fi);
	}	
}*/
 
 
//============================================
int main() {
    ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
    #ifndef ONLINE_JUDGE
       freopen ("INPUT.txt" , "r" , stdin);
       freopen ("OUTPUT.txt", "w" , stdout);
    #endif
 
	//THE WATER WAS DEEP, I DROWNED AND THEN CAME FLOATING UP,DEAD!!
 
 		cin>>n>>m;
 
  		while(m--){
  			ll u,v,c;
  			cin>>u>>v>>c;
  			adj[u].pb(mp(v,c));
  			adj2[v].pb(mp(u,c));
  			edge.pb(mp(mp(u,v),c));
  		}      
 
  		dist[1] = 0;
  		dijkstra();
  		
  		vis.assign(100001,0);
 
  		distb[n] = 0;
  		dijkstraback();
  		vis.assign(100001,0);
 
  		//dfs(1);
  		ans = dist[n];
  		for(auto it : edge){
  			int u = it.fi.fi;
  			int v = it.fi.se;
  			int rel_cost = it.se;
  			ans = min(ans,dist[u]+distb[v]+rel_cost/2);
  		}
  		
  		cout<<ans;
 
return 0;
}
