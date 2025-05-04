#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define db souble
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
 
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n,m;cin>>n>>m;
	vector<pll> adj[n+1];
	for(int i=0;i<m;i++)
	{
		ll a,b,c;cin>>a>>b>>c;
		adj[a].pb(mp(b,c));
	}
	priority_queue<pair<ll,pll> > pq;
	ll dist[2][n+1];
	for(int i=0;i<n+1;i++) dist[0][i]=1e18;
	for(int i=0;i<n+1;i++) dist[1][i]=1e18;
	dist[0][1]=0,dist[1][1]=0;
	bool vis[100005][2];
	memset(vis,0,sizeof(vis));
	pq.push(mp(0,mp(1,0)));
	while(!pq.empty())
	{
		pair<ll,pll> cur=pq.top();
		pq.pop();
		if(vis[cur.se.fi][cur.se.se]) continue;
		vis[cur.se.fi][cur.se.se]=1;
		for(int i=0;i<adj[cur.se.fi].size();i++)
		{
			pll nb=adj[cur.se.fi][i];
			if(dist[0][nb.fi]>nb.se-cur.fi)
			{
				if(!cur.se.se)
				{
					dist[0][nb.fi]=nb.se-cur.fi;
					pq.push(mp(-dist[0][nb.fi],mp(nb.fi,0)));
					if(dist[1][nb.fi]>nb.se/2-cur.fi)
					{
						dist[1][nb.fi]=nb.se/2-cur.fi;
						pq.push(mp(-dist[1][nb.fi],mp(nb.fi,1)));
					}
				}
				else if(dist[1][nb.fi]>nb.se-cur.fi)
				{
					dist[1][nb.fi]=nb.se-cur.fi;
					pq.push(mp(-dist[1][nb.fi],mp(nb.fi,1)));
				}
			}
		}
	}
	// for(int i=1;i<=n;i++) cout<<dist[0][i]<<" ";
	// cout<<endl;
	// for(int i=1;i<=n;i++) cout<<dist[1][i]<<" ";
	// cout<<endl;
	cout<<dist[1][n]<<endl;
	return 0;
}
