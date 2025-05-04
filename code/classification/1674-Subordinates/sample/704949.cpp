#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp> 
#include<ext/pb_ds/tree_policy.hpp> 
#define ll long long int
#define all(v) (v).begin(),(v).end()
#define rev(v) (v).rbegin(),(v).rend()
#define ssd ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define ordered_set tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define trace(x) cerr<<#x<<" : "<<x<<endl;
#define en "\n"
using namespace std;
using namespace __gnu_pbds;
 
vector<int> adj[200005],child(200005,0);
bool vis[200005];
void dfs(int s)
{
    vis[s]=1;
    for(int i:adj[s])
    {
        if(!vis[i])
        {
            dfs(i);
            child[s] += (child[i]+1);
        }
    }
}
signed main() 
{
    ssd
    int i,j,k,n,m;
    cin>>n;
    for(i=2;i<=n;i++)
    {
        cin>>j;
        adj[j].push_back(i);
    }
    dfs(1);
    for(i=1;i<=n;i++) cout<<child[i]<<" ";
    return 0;
} 
