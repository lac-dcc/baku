#include<bits/stdc++.h>
#include<math.h>
#include<sstream>
using namespace std;
 
#define ll long long
#define ld long double
 
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fb(i,a,b) for(ll i=a;i>=b;i--)
 
#define mp make_pair
#define pb push_back
 
#define ft first
#define sd second
#define endl "\n"
#define all(v) v.begin(),v.end()
 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
#define pll pair<ll,ll>
#define V vector<ll>
#define MP map<ll,ll>
#define S set<ll>
#define VV vector<V> 
 
#define autov V::iterator
#define autos S::iterator
#define automp MP::iterator
 
#define allv(it,A) for(autov it=A.begin();it!=A.end();it++)
#define alls(it,A) for(autos it=A.begin();it!=A.end();it++)
#define allmp(it,A) for(automp it=A.begin();it!=A.end();it++)
 
const ll N = 200005;
const ll M = 1000000007;
#define pi 3.14159265358979
 
ll pow1(ll a,ll b){
    int res=1;
    while(b>0){
        if(b&1){
        	res=(res*a)%M;
		}
        a=(a*a)%M;
        b>>=1;
    }
    return res%M;
}
 
vector<ll>height(N,0);
vector<ll>adj[N];
vector<ll>max_dis(N,0);
 
ll dfs1(ll i,ll par){
	height[i]=0;
	f(j,0,adj[i].size()){
		if(adj[i][j]!=par){
			height[i]=max(dfs1(adj[i][j],i),height[i]);
		}
	}
	height[i]++;
	return height[i];
}
 
void bfs(){
	queue<ll>q;
	q.push(0);
	vector<bool>vis(N,0);
	vis[0]=1;
	while(!q.empty()){
		ll s=q.front();
		q.pop();
		ll mx1=0;
		ll mx2=0;
		f(j,0,adj[s].size()){
			if(vis[adj[s][j]]==0){
				if(height[adj[s][j]]>mx1){
					mx2=mx1;
					mx1=height[adj[s][j]];
				}
				else if(height[adj[s][j]]>mx2){
					mx2=height[adj[s][j]];
				}
			}
		}
		f(j,0,adj[s].size()){
			if(vis[adj[s][j]]==0){
				if(height[adj[s][j]]==mx1){
					max_dis[adj[s][j]]=1+max(1+mx2,max_dis[s]);
				}
				else{
					max_dis[adj[s][j]]=1+max(1+mx1,max_dis[s]);
				}
				q.push(adj[s][j]);
				vis[adj[s][j]]=1;
			}
		}
	}
}
 
int main(){
   fast
   ll T;
   T=1;
   while(T--){
   	ll n;
   	cin>>n;
   	f(i,0,n){
   		adj[i].clear();
   		height[i]=0;
	   }
   	f(i,0,n-1){
   		ll a,b;
   		cin>>a>>b;
        a--;b--;
   		adj[a].pb(b);
   	    adj[b].pb(a);
	   }
	   ll z=dfs1(0,-1);
	   bfs();
	   V ans(n);
	   f(i,0,n){
	   	ans[i]=max(height[i],max_dis[i]);
	   	cout<<ans[i]-1<<" ";
	   }
}
}
