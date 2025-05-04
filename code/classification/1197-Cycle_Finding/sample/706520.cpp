#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long int ull;
#define endl "\n"
#define pb push_back
#define sq(a) (a)*(a)
#define all(x) (x).begin(), (x).end()
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define MOD 1000000007
#define PI 3.141592653589793238
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
 
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
 
ll exp(ll x,ll n,ll mod)
{
    ll result=1;
    while(n)
    {
        if(n & 1)
            result=(result * x)%mod;
        x=(x*x)%mod;
        n>>=1;
    }
    return result;
}
 
const ll INF=1e15+1;
 
int32_t main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    IOS
 
    ll n,m;
    cin>>n>>m;
    vector<pair<pair<ll,ll>,ll>> edge(m);
    vector<ll> p(n,-1);
 
    for(ll i=0;i<m;i++)
    {
    	ll a,b,x;
    	cin>>a>>b>>x;
    	a--;b--;
    	edge[i]={{a,b},x};
    }
 
    ll dist[n];
    for(ll i=0;i<n;i++)
    	dist[i]=INF;
 
    dist[0]=0;
 	ll x;
 	
    for(ll i=0;i<n;i++)
    {
    	x=-1;
    	for(ll j=0;j<m;j++)
    	{
    		ll u=edge[j].first.first,v=edge[j].first.second;
    		ll w=edge[j].second;
    		if(dist[u]+w<dist[v])
    		{
    			dist[v]=dist[u]+w;
    			p[v]=u;
    			x=v;
    		}
    	}
    }
 
    if(x==-1)
    {
    	cout<<"NO"<<endl;
    	return 0;
    }
    
	for(ll i=0;i<n;i++)
		x=p[x];
 
	vector<ll> cycle;
	for(ll i=x;;i=p[i])
	{
		cycle.pb(i+1);
		if(i==x && cycle.size()>1)
			break;
	} 
 
	reverse(all(cycle));
 
	cout<<"YES"<<endl;
	for(auto k:cycle)
		cout<<k<<" ";
	cout<<endl;
    
    return 0;
}
