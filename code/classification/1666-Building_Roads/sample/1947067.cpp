#include<bits/stdc++.h>
using namespace std;
 
//#Rohitpratap311
//#Keep Calm And Stay Happy
//CSES 1666
 
 
using ll = long long;
using ld = long double;
 
ll parent[100001];
 
void make_set(ll i)
{
    parent[i]=i;
}
 
ll find_set(ll v)
{
    if(parent[v]==v) return v;
    else
    {
        return parent[v]=find_set(parent[v]);
    }
}
 
void union_set(ll a,ll b)
{
    a=find_set(a);
    b=find_set(b);
    if(a!=b)
    {
        parent[b]=a;
    }
}
 
void solveCP311()
{
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=n;i++)  { make_set(i); }
    while(m--)
    {
        ll u,v;
        cin>>u>>v;
        union_set(u,v);
    }
    vector<ll> ans;
    for(ll i=1;i<=n;i++)
    {
        if(find_set(i)==i)
        {
            ans.push_back(i);
        }
    }
    cout<<ans.size()-1<<"\n";
    for(ll i=1;i<ans.size();i++)
    {
        cout<<ans[0]<<" "<<ans[i]<<"\n";
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll t=1;
    //cin>>t;
    while(t--)
    {
        solveCP311();
    }
    return 0;
}


