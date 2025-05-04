#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define ull unsigned long long
#define f(i,m,n) for(int i=m; i<n;i++)
#define pii pair<int,int>
#define ff first
#define ss second
#define vi vector<int>
#define yup cout<<"hii\n";
#define show(x) for(auto &m:x) cout<<m<<" ";cout<<"\n";
#define all(m) (m).begin(), (m).end()
#define pb push_back
#define mp make_pair
 
int inf = LONG_LONG_MAX;
int mod = 1000000007;
 
int dfs(int node, int par, vi *adj, int &ans)
{
    int mx1=0,mx2=0;
    for(auto &i:adj[node])
    {
        if(i!=par)
        {
            int val=dfs(i,node,adj,ans);
            if(val>mx1)
            {
                mx2=mx1;
                mx1=val;
            }
            else if(val>mx2)
                mx2=val;
        }
    }
 
    ans=max(ans,(mx1+mx2));
    return (1+max(mx1,mx2));
}
 
void tathastu()
{
    int n;
    cin>>n;
    vi adj[n+1];
    f(i,0,n-1)
    {
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int ans=0;
    dfs(1,-1,adj,ans);
    cout<<ans<<"\n";
}
 
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int testcases=1;
    for(int _=1; _<=testcases; _++)
    {
        //cout<<"Case #"<<_<<": ";
        tathastu();
    }
    return 0;
}
