#include<bits/stdc++.h>
using namespace std;
 
#define ll long long 
 
const ll INF = 1e17;
const ll NINF = INF*(-1);
 
struct triplet{
	ll u1,v1,c1;
};
 
vector<triplet> edges;
vector<ll>dist;
vector<ll>par;
 
void bellmanFord(ll n)
{
	
	for (int i = 1; i <= n; ++i)
	{
		for (auto e: edges)
		{
			ll u = e.u1;
			ll v = e.v1;
			ll d = e.c1;
 
			//if(dist[u] < INF)	continue;
			dist[v] = min(dist[v], dist[u]+d);
		}
	} //n relaxations
 
	ll nd=-1,cur=0,srt=0;
	for (int i = 1; i <= n; ++i)
	{
		for(auto e: edges)
		{
			ll u = e.u1;
			ll v = e.v1;
			ll d = e.c1;
 
			//debug(dist[u] + d, dist[v]);//!!!!!!!!!!!!!!!!!
			if(dist[u] + d < dist[v])
			{
				dist[v] = dist[u] + d;
				par[v] = u;
				nd = u;
				//debug(nd);//!!!!!!!!!!!!!!!!!
			}
		}
	} // neg cycle
 
	if(nd==-1)
	{
		cout<<"NO"<<endl;
		return;
	}
 
	cur = nd;
 
	set<ll>s;
 
	while(1)
	{
		if(s.count(cur))	break;
		s.insert(cur);
		cur = par[cur];
	}
 
	srt = cur;
 
	vector<ll>path;
 
	while(1)
	{
		path.push_back(cur);
		cur = par[cur];
		if(cur==srt)
		{
			path.push_back(cur);
			break;
		}
	}
 
	reverse(path.begin(), path.end());
 
	cout<<"YES"<<endl;
	for(auto e: path)
	{
		cout<<e<<" ";
	}
	cout<<endl;
}
 
 
int main()
{
	
	ll n,m;		cin>>n>>m;
 
	dist.resize(n+1);
	edges.resize(m);
	par.resize(n+1);
 
	for (int i = 0; i < m; ++i)
	{
		struct triplet s;
 
		cin>>s.u1>>s.v1>>s.c1;
		edges[i] = s;
 
	}
 
	// for(int i = 2; i <= n; ++i)
	// {
	// 	dist[i] = INF;
	// }
 
	bellmanFord(n);
 
	
		
}
