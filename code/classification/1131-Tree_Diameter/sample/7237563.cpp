#include <bits/stdc++.h>
typedef long long int ll;
#define rep(i,n) for(i=0;i<n;++i)
#define re(i,a,n) for(i=a;i<=n;++i)
#define repr(i,a,n) for(i=a;i>=n;--i)
#define sorta(arr,n) sort(arr,arr+n)
#define sortv(v) sort(v.begin(),v.end())
#define reva(arr,n) reverse(arr,arr+n)
#define revv(v) reverse(v.begin(), v.end())
#define pll pair<ll,ll>
#define print(arr) for(auto i:arr){cout<<i<<;}
#define pb push_back
using namespace std;
ll  i, y, x, z, g, key, a, b, c, d, j, q, l, r, n, m, k, p,cnt;
ll t2, t3, t4, t1, t5, t6;
string s, s2, s1, s3;
vector<ll> adj[200005];
ll ans;
ll dfs(ll node=0,ll par=-1)
{
    vector<ll> temp;
    for(auto nbr:adj[node])
    {
        if(nbr==par){continue;}
        temp.push_back(dfs(nbr,node));
    }
    if(temp.size()==0)
    {
        // ans=max(ans,1LL);
        return 0;
    }
    sort(temp.begin(),temp.end());
    if(temp.size()>=2)
    {
        ans=max(ans,2+temp.back()+temp[temp.size()-2]);
    }
    ans=max(ans,1+temp.back());
    // cout<<node<<" "<<1+temp.ba/ck()<<endl;
    return 1+temp.back();
}
void solve()
{
    cin>>n;
    rep(i,n-1)
    {
        cin>>a>>b;
        --a,--b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs();
    cout<<ans;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
}
