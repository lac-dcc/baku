#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp> 
#include<ext/pb_ds/tree_policy.hpp> 
#define ll long long int
#define inc(v) sort((v).begin(),(v).end());
#define dec(v) sort((v).rbegin(),(v).rend());
#define ssd ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define ordered_set tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define trace(x) cerr<<#x<<" : "<<x<<endl;
#define en "\n"
using namespace std;
using namespace __gnu_pbds;
 
vector<int> adj[100005];
bool vis[100005];
 
void dfs(int s)
{
    vis[s]=1;
    for(int i:adj[s])
    {
        if(!vis[i]) dfs(i);
    }
}
signed main() 
{
    ssd
    int i,j,k,n,m;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>j>>k;
        adj[j].push_back(k);
        adj[k].push_back(j);
    }
    vector<int> ans;
    for(i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs(i);
            ans.push_back(i);
        }
    }
    cout<<ans.size()-1<<en;
    for(i=1;i<ans.size();i++)
    {
        cout<<ans[i-1]<<" "<<ans[i]<<en;
    }
    return 0; 
} 
