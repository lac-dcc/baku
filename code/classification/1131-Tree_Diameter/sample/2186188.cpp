#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
vector<ll>tree[200001];
vector<ll>h(200001);
 
void f(ll src,ll par)
{
    int leaf=1;
    for(ll i:tree[src])
    {
        if(i!=par)
        {
            leaf=0;
            f(i,src);
            h[src]=max(h[src],h[i]+1);
        }
    }
    if(leaf)
    {
        h[src]=1;
        return ;
    }
}
 
void solve(ll src,ll par,ll &ans)
{
    vector<ll>v;
    
    for(auto i:tree[src])
    {
        if(i!=par)
        {
            solve(i,src,ans);
            v.push_back(h[i]);
        }
    }
    sort(v.begin(),v.end());
    ll mx1=0,mx2=0;
    if(v.size()>=1)
    mx1=v[v.size()-1];
    if(v.size()>=2)
    mx2=v[v.size()-2];
    ans=max(ans,mx1+mx2);
}
int main() {
    ll n;
    cin>>n;
    for(int i=1;i<=n;i++)
    h[i]=1;
    for(int i=1;i<n;i++)
    {
        ll a,b;
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    f(1,0);
    ll ans=0;
    solve(1,0,ans);
    cout<<ans;
	return 0;
}
