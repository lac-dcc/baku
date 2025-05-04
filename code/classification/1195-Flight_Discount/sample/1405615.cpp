#include <bits/stdc++.h>
#define int long long
#define f(i,a,n) for(int i=a;i<n;i++)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL);
#define w1 solve();
#define mod (int)(1e9+7)
#define sz(x) (int)x.size()
#define w(t) int t ; cin>>t ; while(t--){solve();}
 
using namespace std;
 
 
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpi;
 
const int INF = (int)1e17;
const int NINF = -1*INF;
 
 
 
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
string path = "URDL";
 
struct edge
{
	int a,b,w;
};
 
void solve(){
	int n,m,a,b,c;
	cin>>n>>m;
	vpi arr[n+1];
	vpi tr[n+1];
	edge adj[m];
	vi dis(n+1,INF);
	vi dis1(n+1,INF);
	f(i,0,m) cin>>a>>b>>c , arr[a].pb(mp(b,c)) ,tr[b].pb(mp(a,c)) , adj[i].a=a,adj[i].b=b,adj[i].w=c;
	dis[1]=0,dis1[n]=0;
 
	priority_queue<pii,vpi,greater<pii>> pq;
	pq.push(mp(0,1));
	while(!pq.empty()){
		int dis_u=pq.top().ff;
		int u=pq.top().ss;
		pq.pop();
		if(dis_u != dis[u]) continue;
		for(auto v:arr[u]){
			int ver=v.ff;
			int wt=v.ss;
			if(dis[ver] > dis[u] + wt){
				dis[ver]= dis[u]+wt;
				pq.push(mp(dis[ver],ver));
			}
		}
 
	}
	
	priority_queue<pii,vpi,greater<pii>> pq1;
	pq1.push(mp(0,n));
	while(!pq1.empty()){
		int u=pq1.top().ss;
		int dis_u=pq1.top().ff;
		pq1.pop();
		if(dis_u != dis1[u]) continue;
		for(auto e: tr[u]){
			int ver = e.ff;
			int wt = e.ss;
			if(dis1[ver] > dis1[u]+wt){
				dis1[ver] = dis1[u]+wt;
				pq1.push(mp(dis1[ver] , ver));
			}
		} 
	}
 
int ans=LLONG_MAX;
f(i,0,m){
	ans=min(ans , dis[adj[i].a] + adj[i].w/2 + dis1[adj[i].b]);
}
 
cout<<ans<<"\n";
 
 
}
 
 
int32_t main(){
	fastio
	int t=1;
	while(t--)
	solve();
}
