#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n"
#define pb push_back
#define eb emplace_back
#define Sort(a) sort(a.begin(),a.end())
#define vi vector<int>
#define vll vector<long long>
#define F first
#define S second
#define inf numeric_limits<long long>::max()
#define all(x) x.begin(),x.end()
#define sz(x) ((int)(x).size())
#define yes cout<<"YES"<<nl
#define no cout<<"NO"<<nl
#define f(i,a,b) for(ll i = a; i < b; i++)
#define fr(i,a,b) for(ll i = a; i > b; i--)
void dfs(int v,vector<int> &vis,vector<vector<int>> &adj){
	vis[v]=1;
	for(auto child : adj[v]){
		if(!vis[child]){
			dfs(child,vis,adj);
		}
	}
}
int main(){
	int n,m;
	cin>>n>>m;
    vector<int> vis(n+1,0);
    vector<vector<int>> v(n+1);
    f(i,0,m){
    	int a,b;
    	cin>>a>>b;
    	v[a].pb(b);
    	v[b].pb(a);
    }
    vi ans;
    f(i,1,n+1){
    	if(!vis[i]){
    		ans.pb(i);
    		dfs(i,vis,v);
    	}
    }
    cout<<ans.size()-1<<nl;
    f(i,0,ans.size()-1){
    	cout<<ans[i]<<' '<<ans[i+1]<<nl;
    }
    return 0;
}
