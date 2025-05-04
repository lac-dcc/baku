#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll maxd=-1,maxnode;
unordered_map<ll,vector<ll>> m;
void dfs(ll node,ll par,ll d)
{
 
    if(d>maxd)
    {
        maxd=d;
        maxnode=node;
    }
    for(auto p: m[node])
    {
        if(p!=par)
        {
            dfs(p,node,d+1);
        }
    }
}
int main()
{
    ll n;
    cin>>n;
    for(ll i=0;i<n-1;i++)
    {
        ll a,b;
        cin>>a>>b;
        m[a].push_back(b);
        m[b].push_back(a);
    }
    dfs(1,0,0);
    maxd=-1;
    dfs(maxnode,0,0);
    cout<<maxd<<endl;
}
