#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define pb push_back
#define fri(n) for(ll i=0;i<n;i++)
#define frj(n) for(ll j=0;j<n;j++)
#define frri(n) for(ll i=n-1;i>=0;i--)
#define frrj(n) for(ll j=n-1;j>=0;j--)
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
const ll mm=1e9+7;
void dfs(int i,vector<int> *g,vector<int> &vis)
{
    vis[i]=1;
    for(auto y : g[i])
    {
        if(vis[y]) continue;
        dfs(y,g,vis);
    }
}
void solve()
{
    ll n,m;
    cin>>n>>m;
    ll x,y;
    vector<int> g[n+1];
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> vis(n+1,0);
    vector<pair<int,int>> ans;
    int prev=1;
    dfs(1,g,vis);
    for(int i=2;i<=n;i++)
    {
        if(!vis[i])
        {
            ans.push_back({prev,i});
            dfs(i,g,vis);
            prev=i;
        }
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
}
int main() {
	ll n;
   n=1;
	while(n--) solve();
	return 0;
 
}
