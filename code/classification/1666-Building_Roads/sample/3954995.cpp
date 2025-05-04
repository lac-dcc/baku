#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define vint vector<int>
#define vll vector<long long>
#define mod 1000000007
 
vector<bool> vis_ver(100005, 0);
vector<ll> adj[100005];
 
void dfs (ll z)
{
	vis_ver[z]=true;
	for (auto x : adj[z])
	{
		if (!vis_ver[x]) dfs(x);
	}
}
 
 
 
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
    ll n, r;
	cin>>n>>r;
	for (ll i=0; i<r; i++) 
	{
		ll v1, v2;
		cin>>v1>>v2;
		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
	}
	vector<ll> city;
	for (ll i=1; i<=n; i++)
	{
		if (!vis_ver[i]){
		    city.push_back(i);
		    dfs(i);
        }
	}
	cout<<(city.size())-1<<"\n";
	if (city.size()>1)
	{
		for (ll i=1; i<city.size(); i++) cout<<city[i-1]<<" "<<city[i]<<"\n";	
	}
 
 
 
}
