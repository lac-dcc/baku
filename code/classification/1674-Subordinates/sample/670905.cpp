#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define fi first
#define se second
#define vll vector<ll>
#define pii pair<ll,ll>
#define vvll vector< vector<ll> >
#define pb push_back
#define sz(v) (ll)(v).size()
#define inf 1e18
#define md 998244353
#define all(v) (v).begin(),(v).end()
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define tel(a){cout<<a<<"\n";}
#define tell(a,b){cout<<a<<" | "<<b<<"\n";}
#define telll(a,b,c){cout<<a<<" | "<<b<<" | "<<c<<"\n";}
#define teln(v,n){cout<<"v- ";rep(o,0,n)cout<<v[o]<<" ";cout<<"\n";}
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
 
#define M 200010
 
vll g[M];
ll sz[M];
void dfs(ll u,ll pa=-1){
	sz[u]=1;
	for(auto v:g[u]){
		if(v==pa)continue;
		dfs(v,u),sz[u]+=sz[v];
	}
}
 
int main(){
    IOS;
    
    ll n;cin>>n;
    rep(i,2,n+1){
    	ll x;cin>>x;
    	g[x].pb(i);
    }
    dfs(1);
    rep(i,1,n+1)cout<<sz[i]-1<<" ";
    
	    
    
    return 0;
}
