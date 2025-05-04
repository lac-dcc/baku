#include<bits/stdc++.h>
#include<fstream>
#include <unordered_map>
#define ll long long
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define vs vector<string>
#define vp vector<pair<int , int>>
#define vvp vector<vp>
#define vc vector<char>
#define F first
#define S second
#define rep(i,a,n) for(ll i=a ; i<n ; i++)
#define pb push_back
using namespace std;
 
 
int main()
{
	ll n , m ;
	cin>>n>>m;
	vvl e;
	
	for(int i=0 ; i<m ; i++)
	{
		ll a , b, c;
		cin>>a>>b>>c;
		e.pb({a , b, c});
	}
	vl dis(n+1 , INT_MAX);
	vl par(n+1 , -1);
	dis[1]=0;
	par[1]=0;
	for(ll i=0 ; i<n ; i++)
	{
		for(auto v :e)
		{
			ll a=v[1], b=v[0], c=v[2];
			if(dis[a]>dis[b]+c)
			{
				par[a]=b;
				dis[a]=dis[b]+c;
			}
		}
	}
	
	
	
	ll f=-1;
	
	for(auto v :e)
		{
			ll a=v[1], b=v[0], c=v[2];
			if(dis[a]>dis[b]+c)
			{
				f=b;
			}
		}
	
	if(f==-1) cout<<"NO\n";
	else 
	{
		cout<<"YES\n";
		vl v;
		vector<bool> vis(n+1, 0);
		while(f!=-1 && vis[f]!=1)
		{
			vis[f]=1;
			v.pb(f);
			f=par[f];
		}
		v.pb(f);
		reverse(v.begin(), v.end());
		for(auto i:v) cout<<i<<" ";
		cout<<endl;
	}
	
	return 0;	
}
