#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define pb push_back
#define vll vector<ll>
#define pll pair<ll,ll>
#define size(v) (v.empty() ? 0 : v.size())
#define memf(a) memset(a,false,sizeof(a))
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define fr(i,n) for(ll i=0;i<n;i++)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define tr(v) for(auto it=v.begin();it!=v.end();it++)
const ll inf = 1e17 ;
const ll ninf = inf * -1;
ll n,m;
vector<vector<ll>>e;
vector<ll>d;
std::vector<ll> path;
// void belman_ford(){
// }
 
void solve()
{
	cin>>n>>m;
	d.assign(n,inf);
	path.resize(n);
	fr(i,m){
		ll a,b,c;
		cin>>a>>b>>c;
		a--;
		b--;
		e.pb({a,b,c});
	}
	d[0] = 0;
	ll x = -1;
	fr(i,n){
		x = -1;
		for(auto it:e){
			int v = it[1];
			int u = it[0];
			int cost = it[2];
			// if(d[u] == inf){
				// continue;
			// }
			if(d[v] > d[u] + cost){
				d[v] = d[u] + cost;
				path[v] = u;
				x = v;
			}
			// d[v] = min(d[v],d[u] + cost);
			// d[v] = max(d[v],ninf);
		}
	}
	// fr(i,n)
	// cout<<d[i]<<" ";
	// cout<<endl;
 
	if(x == -1){
		cout<<"NO\n";
	}
	else{
		cout<<"YES\n";
		ll y = x;
		fr(i,n){
			y = path[y];
		}
		vll p;
		for(ll curr = y;;curr = path[curr]){
			p.pb(curr);
			if(curr == y && size(p) > 1){
				break;
			}
		}
		reverse(all(p));
		for(auto it:p)
			cout<<it+1<<" ";
		cout<<endl;
 
	}
 
}
 
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll t;
    t =1;
    // cin>>t;
    while(t--)
        solve();
}
