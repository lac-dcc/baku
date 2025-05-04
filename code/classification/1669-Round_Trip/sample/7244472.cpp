#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define ar array
#define vvl vector<ll> v
#define vl vector<ll> 
#define pb push_back
#define vvi vector<int> v
#define vi vector<int> 
#define f(n) for(int i=0;i<n;i++)
#define rf(n) for(int i=n-1;i<=0;i++)
#define ios ios::sync_with_stdio(0);cin.tie(0)
#define mv(x, a) for (auto& x: a)
#define endl "\n"
#define all(n) (n).begin(),(n).end()
 
 
template <class T> void get(T& a){cin>>a;}
template <class T> void prints(T& a){cout<<a<<" ";}
template <class T> void println(T& a){cout<<a<<endl;}
template <class T> void println(vector<T>& a){for(auto itt:a){cout<<itt<<endl;}}
template <class T> void prints(vector<T>& a){for(auto itt:a){cout<<itt<<" ";}}
template <class T,class... A> void prints(T& a,A&... b){prints(a);prints(b...);}
template <class T,class... A> void println(T& a,A&... b){println(a);println(b...);}
template <class T,class... A> void get(T& a,A&... b){get(a);get(b...);}
template <class A, class T> void get(A& n,vector<T>& vec){for(int i=0;i<n;i++){ll qa;cin>>qa;vec.pb(qa);}}
template <class T> void sop(T& vec){for(auto it:vec){cout<<it<<" ";}}
#ifdef _ADB
#include "debug.h"
#else
#define debug(...)22
#endif
const ll INF=1e18,MOD=1e9+7,MAX=1e5;
int w=1;
ll n,m;
vector<vector<ll>> g(MAX+1);
vl ans;
vector<bool> vis(MAX+1);
 
 
int dfs(int i,int par){
	
	vis[i]=true;
 
	for (int ii:g[i]){
		debug(i,ii,par);
			if(!vis[ii]){
				int a=dfs(ii,i);
				if(a==0){ans.pb(ii);return 0;}
			}
			else if(ii!=par){ans.pb(ii);debug(w,ii);return 0;};
			
		}
		return 1;
		
}
 
 
void code(){
		
		get(n,m);
		vvl;
		for (ll i=0;i<m;i++){
			ll a,b;
			cin>>a>>b;
				g[a].pb(b);
				g[b].pb(a);
			}
		
		for (ll i=1;i<=n;i++){
				if(!vis[i]){
					
					int a=dfs(i,0);
					if(a!=1){
						
						a=1;
						while(ans[a]!=ans[0]&&a<ans.size()){
							a++;
						}
						cout<<a+1<<endl;
			
			        for (ll i=0;i<a;i++){
					cout<<ans[i]<<" ";
					if(ans[i]==ans[0]&&i!=0){return;}
				};
				cout<<ans[0];
				
				
				return;
				
					}
					
				}
			}
			
			cout<<"IMPOSSIBLE";
			
}
 
int main(){
	ios;
	// cin>>w;
	while(w--){code();}
}
