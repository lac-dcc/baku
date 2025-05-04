#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define INF (ll)1e18 
 
bool inBounds(vector<string> &mat,pair<ll,ll>cell){
	ll i = cell.first, j = cell.second;
	ll n = mat.size();
	ll m = mat[0].size();
	if((i < 0 || i >=n) || (j < 0 || j >= m) || (mat[i][j] == '#')){
		return false;
	}
	return true;
}
struct Par{
	ll cost;
	ll node;
	ll flag;
};
bool operator>(const Par &a, const Par &b ){
	return a.cost > b.cost;
}
void solve(){
	// struct wtedge {
	// 	ll node;
	// 	ll next;
	// 	ll wt;
	// };
	// ll n,m;
	// cin>>n>>m;
	// vector<wtedge> edges;
	// vector<ll> disc(n+1,INF), ndisc(n + 1, INF);
	// for(ll i = 0; i < m; i++){
	// 	ll a,b,c;
	// 	cin>>a>>b>>c;
	// 	wtedge t = {a,b,-c};
	// 	edges.push_back(t);
	// }
	// for(auto x: edges){
	// 	printf("next%I64d node%I64d wt%I64d \n",x.node,x.next,x.wt);
	// }
	// /* ======== ^ Input Weighted Edge list ^ ======== */
 
 
 
	ll n,m;
	cin>>n>>m;
	vector<vector<pair<ll,ll>>> adj(n+1);
	vector<ll> disc(n+1,INF), ndisc(n + 1, INF);
	for(ll i = 0; i < m; i++){
		ll p , q, r;
		cin>>p>>q>>r;
		adj[p].push_back(make_pair(q,r));
		// adj[q].push_back(p);
	}
	/* ======== ^ Input Adjacency list ^ ======== */
	disc[1] = ndisc[1] = 0;
	priority_queue<Par, vector<Par>, greater<Par> > q;
	q.push(Par{0,1,0});
	while(!q.empty()){
		// for(auto x: disc) cout<<x<<' ';cout<<endl;for(auto x: ndisc) cout<<x<<' ';cout<<endl;
 
		Par top = q.top();
		q.pop();
		if((top.cost > ndisc[top.node]) && top.flag == 0  || (top.cost > disc[top.node]) && top.flag == 1) continue;
		// printf("cost%I64d node%I64d flag%I64d\n", top.cost, top.node, top.flag);
		for(auto x: adj[top.node]){
				if(top.flag == 0){
					if(top.cost + x.second < ndisc[x.first]){
						ndisc[x.first] = top.cost + x.second;
						q.push(Par{ndisc[x.first] , x.first, 0});
					}
 
					if(top.cost  + x.second / 2 < disc[x.first]){
						disc[x.first] = top.cost + x.second/2;
						q.push(Par{disc[x.first] , x.first, 1});
					}
				}
				else if( top.cost  + x.second  < disc[x.first]){
					disc[x.first] = top.cost + x.second;
					q.push(Par{disc[x.first] , x.first, 1});
				}
		}
 
		}
		cout<<disc[n]<<endl;
	// ll n,m,q;
	// cin>>n>>m>>q;
	// vector<vector<ll>> mat(n+1, vector<ll>(n+1 , INF));
	// for(ll i = 0; i < m; i++){
	// 	ll a,b,c;
	// 	cin>>a>>b>>c;
	// 	mat[a][b] = min (mat[a][b] , c);
	// 	mat[b][a] = min (mat[a][b] , c); 
	// }
	// /* ======== ^ Input Adjacency Matrix ^ ======== */
 
	// ll n , m;
	// cin>>n>>m;
	// vector<string> grid(n);
	// vector<vector<ll>> vis(n, vector<ll>(m)), time(n,vector<ll>(m,1e9));
	// for(ll i = 0; i < n; i++){
	// 	cin>>grid[i];
	// }
	// /* ======== ^ Input nxm Grid ^ ======== */
	
}
 
int main(){
	// ll t;
	// cin>>t;
	// while(t--){
		solve();
	// }
}
 
 
 
 
 
 
/*
 
*/
