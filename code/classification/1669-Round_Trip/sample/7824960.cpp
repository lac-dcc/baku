/*And if we meet forever now
pull the blackout curtains down*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(x) x.begin(),x.end()
#define eb emplace_back
#define pb push_back
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define need_for_speed() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const ll mod = 1e9 + 7;
vector<int>adj[100005];
bool vis[100005];
int dis[100005],color[100005];
int n,m;
void dfs(int node,int parent)
{
	vis[node]=true;
	dis[node]=parent;
	color[node]=1;
	for(int c:adj[node])
	{
		if(c!=parent){
			if(color[c]==1)
			{
				vector<int>res;
				int x=node;
				while(x!=c)
				{
					res.push_back(x);
					x=dis[x];
				}
				res.push_back(x);
				res.push_back(res[0]);
				cout<<res.size()<<'\n';
				for(auto x:res) cout<<x<<' ';
				exit(0);
			}
		
		else{
			dfs(c,node);
		}
	}
	}
	color[node]=2;
	//return false;
}
void test_case(void){}
int main(){
	cin>>n>>m;
	while(m--)
	{
		int u,v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	memset(vis,false,sizeof vis);
	for(int i=1;i<=n;i++)
	{
		if(!vis[i]) dfs(i,0);
	}
	cout<<"IMPOSSIBLE\n";
}
