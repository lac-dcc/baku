#include <iostream>
#include <vector>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define int long long
#define $AzH_TxdmN$ ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
 
#define ep emplace_back
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>__indexed_set;
const int N = 3e5+9;
const int MOD = 1e9+7;
vector<int>v[N];
int used[N],color[N];
 
int n,m,u,p,f = 1;
 
void dfs(int node)
{
    used[node] = 1;
    for(int i : v[node])
    {
        if (!used[i])
        {
            color[i] = (color[node] == 1 ? 2 : 1);
            dfs(i);
        }
        else if (i != node && color[i] == color[node])
        {
            f = 0;
            return;
        }
    }
}
 
void solve()
{
    cin>>n>>m;
    while(m--)
    {
        cin>>u>>p;
        v[u].ep(p);
        v[p].ep(u);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!used[i])
        {
            color[i] = 1;
            dfs(i);
        }
    }
    if (!f)
    {
        cout<<"IMPOSSIBLE\n";
        return;
    }
    for (int i = 1; i <= n; ++i)
    {
        cout<<color[i]<<' ';
    }
    cout<<endl;
}
 
signed main()
{
    $AzH_TxdmN$
    int t = 1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
}