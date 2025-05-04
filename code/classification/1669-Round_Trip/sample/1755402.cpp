#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define fast ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define scan(a,n) for(long int index=0;index<n;index++) cin>>a[index];
#define print(a,n) for(long int index=0;index<n;index++) cout<<a[index]<<" ";cout<<endl;
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define vli vector<long long>
#define vlli vector<pair<long long int,long long int>>
#define vsi vector<string>
#define test(x) int x; cin>>x; while(x--)
#define mi 1000002
#define fab(i,a,b) for(int i=a;i<b;i++)
#define fabs(i,a,b,c) for(int i=a;i<=b;i+=c)
#define make(T,a,n) T *a=new T[n+1];
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define mt make_tuple
#define all(x) x.begin(),x.end()
#define maxi 1000002
ll sv,ev;
vector<ll> adj[100002];
vector<bool> vis(100002,false);
vector<ll> par(100002,-1);
ll v,e;
 
bool dfs(ll s,ll p)
{
    vis[s]=true;
    par[s]=p;
    for(auto u: adj[s])
    {
        if(u==p) continue;
        else if(vis[u]) {   sv=u; ev=s; return true;}
        else{
            if(dfs(u,s)) return true;
        }
    }
    return false;
}
 
bool check()
{
    fabs(i,1,v,1){
        if(!vis[i])
        {
            if(dfs(i,-1)) return true;
        }
    }
    return false;
}
 
int main()
{
    
    cin>>v>>e;
    sv=ev=-1;
    fab(i,0,e)
    {   ll x,y; cin>>x>>y; adj[x].pb(y); adj[y].pb(x);  }
 
    if(check())
    {
        ll tv=ev;
        vli ans; ans.pb(tv);
        while(tv!=sv)
        {
            ans.pb(par[tv]);
            tv=par[tv];
        }
        ans.pb(ev);
        cout<<ans.size()<<endl;
        for(auto it:ans) cout<<it<<' ';
    }
    else {
        cout<<"IMPOSSIBLE"<<endl;
    }
}   
 
// 5 6
// 1 3
// 1 2
// 5 3
// 1 5
// 2 4
// 4 5
 
 
 
 
