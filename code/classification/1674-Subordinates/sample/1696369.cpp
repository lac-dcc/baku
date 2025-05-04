#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
vector<ll>a[200005];
ll sub[200005]={0};
 
void dfs(ll x,ll p)
{
    sub[x]=1;
    for(ll i : a[x])
    {
        if(i!=p)
        {
            dfs(i,x);
            sub[x]+=sub[i];
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    ll n;
    cin>>n;
    for(ll i=2;i<=n;i++)
    {
        ll aa;
        cin>>aa;
        a[aa].push_back(i);
        a[i].push_back(aa);
    }
    dfs(1,1);
    for(ll i=1;i<=n;i++)
    cout<<sub[i]-1<<" ";
}
