/*
  Author - KISHAN TIWARI
  Dream bigger. Do bigger.
  Wake up with determination. Go to bed with satisfaction.
*/
//Sometimes later becomes never. Do it now.
#include<bits/stdc++.h>
using namespace std;
#define ll           long long
#define f(i,a,b)     for(ll i=a;i<b;i++)
#define mod          1000000007
#define fi           first
#define se           second
#define pa           pair <ll,ll>
#define mp           make_pair
#define pb           push_back
#define ve           vector<ll>
#define vep          vector< pa >
#define all(a)       a.begin(), a.end()
#define sz(x)        (ll)x.size()
#define c(t)         cout<<t<<"\n"
using namespace std;
vector<ll> color(100001,0);
vector<ll> parent(100001);
vector <ll> adj[100001];
ll start,ending;
bool dfs(ll v,ll par)
{
    color[v]=1;
    f(i,0,adj[v].size())
    {
        if(adj[v][i]==par)
            continue;
        if(color[adj[v][i]]==0)
        {
            parent[adj[v][i]]=v;
            if(dfs(adj[v][i],v))
                return true;
        }
        else if(color[adj[v][i]]==1)
        {
            start=adj[v][i];
            ending=v;
            return true;
        }
    }
   color[v]=2;
   return false;
}
 
void solve()
{
ll n,m;
cin>>n>>m;
parent.assign(n+1,-1);
f(i,0,m)
{
    ll u,v;
    cin>>u>>v;
    adj[u].pb(v);
    adj[v].pb(u);
}
start=-1;
f(i,1,n+1)
    if(color[i]==0&&dfs(i,parent[i]))
            break;
if(start==-1)
    cout<<"IMPOSSIBLE\n";
else
{
    vector<ll> path;
    path.pb(start);
    for(ll v=ending;v!=start;v=parent[v])
        path.pb(v);
    path.pb(start);
    reverse(path.begin(),path.end());
    c(path.size());
    f(i,0,path.size())
    cout<<path[i]<<" ";
}
}
int main()
{
    ios::sync_with_stdio(true);
    /*#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif*/
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
return 0;
}
