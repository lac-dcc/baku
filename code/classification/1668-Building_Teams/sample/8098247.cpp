#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>> rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
typedef long long int ll;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<ld> vd;
typedef vector<vd> vvd;
typedef vector<bool> vb;
typedef pair<ll, ll> pll;
typedef map<ll, ll> mll;
 
const double PI = 3.141592653589793;
const int M = 1e9+7;
const int mod = 998244353;
const int inf = INT_MAX;
const ll INF = LLONG_MAX;
 
#define f(i,a,b,d) for(ll i=a;i<b;i+=d)
#define rf(i,a,b,d) for(ll i=a;i>=b;i-=d)
 
map<ll,vl> graph;
vb vis;
vl team;
bool f=0;
 
 
 
void dfs(ll node, ll tm)
{
	vis[node]=true;
	team[node]=tm;
	for(auto c:graph[node])
	{
		if(!vis[c])
		{
			dfs(c,1-tm);
		}
		else
		{
			if(team[c]==tm)
			f=1;
		}
	}
}
 
 
void solve()
{
	ll n,m;
	cin>>n>>m;
 
	graph.clear();
	vis.clear();
	vis.resize(n+1,false);
	team.clear();
	team.resize(n+1,0);
 
	f(i,0,m,1)
	{
		ll x,y;
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
 
	f(i,1,n+1,1)
	{
		if(!vis[i])
		{
			dfs(i,1);
		}
	}
	
	if(f)
	cout<<"IMPOSSIBLE";
	else
	f(i,1,n+1,1)
	cout<<team[i]+1<<" ";
	cout<<endl;
 
}
 
 
int main() {
	fastio
    #ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
	ll t=1;
	// cin>>t;
	while(t--)
	{
		// cout<<solve()<<endl;
		solve();
	}
	
	return 0;
}
 
