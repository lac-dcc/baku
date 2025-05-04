#include "bits/stdc++.h"
#define ld long double
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define no cout<<"NO\n";
#define yes cout<<"YES\n";
#define nl cout<<"\n";
#define sp <<" "
#define lb lower_bound
#define ub upper_bound
#define ull unsigned long long
#define FAST ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0); srand(time(NULL));
#define MOD 1000000007
#define INF LONG_LONG_MAX
#define MINF LONG_LONG_MIN
#define PI 3.141592653589793
using namespace std;
 
// ####################################################################
 
vector<ll> d;
vector<vector<ll>> gr;
ll mxnode,mxdist=0;
void dfs1(ll node,ll par,ll dist)
{
    for(auto child:gr[node])
    {
        if(child!=par)
        {
            dfs1(child,node,dist+1);
        }
    }
    if(mxdist<dist)
    {
        mxdist=dist;
        mxnode=node;
    }
}
 
void dfs2(ll node,ll par,ll dist)
{
    for(auto child:gr[node])
    {
        if(child!=par)
        {
            dfs2(child,node,dist+1);
        }
    }
    d[node]=max(d[node],dist);
}
 
void solve()
{   
    ll n,i;
    cin>>n;
    
    d.resize(n+5);
    gr.resize(n+5);
    
    if(n==1){ cout<<0; return; }
    ll node1,node2;
    for(i=1;i<n;i++)
    {
        cin>>node1>>node2;
        gr[node1].pb(node2);
        gr[node2].pb(node1);
    }
    
    dfs1(1,-1,1);
    ll nd1=mxnode,nd2; mxdist=0;
    dfs1(mxnode,-1,1);
    nd2=mxnode;
    
    dfs2(nd1,-1,1);
    dfs2(nd2,-1,1);
    
    for(i=1;i<=n;i++) cout<<d[i]-1 sp;
   
    return;
}
 
 
// ####################################################################
 
signed main()
{
    FAST
    ll t = 1;
  //  cin >> t;
   
    while (t--)
        solve();
 
 
    #ifndef ONLINE_JUDGE
        cout << "\nTime Elapsed: " << (1000.0 * clock()) / CLOCKS_PER_SEC << " ms \n";
    #endif 
}
 
// #####################################################################
