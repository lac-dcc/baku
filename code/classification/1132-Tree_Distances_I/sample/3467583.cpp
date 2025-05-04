#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define w(t) int t; cin>>t; while(t--)
#define U unsigned
#define A auto
// #define int long long int
#define I int32_t
#define asc(i,a,n) for(int i=a;i<n;i++)
#define dsc(i,n,a) for(int i=n;i>=a;i--)
#define forw(it,x) for(A it=(x).begin();it!=(x).end();it++)
#define bacw(it,x) for(A it=(x).rbegin();it!=(x).rend();it++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound
#define ook order_of_key
#define fbo find_by_order
#define V(x) vector<x>
#define P(x,y) pair<x,y>
#define OS(x) set<x>
#define US(x) unordered_set<x>
#define OMS(x) multiset<x>
#define UMS(x) unordered_multiset<x>
#define OM(x,y) map<x,y>
#define UM(x,y) unordered_map<x,y>
#define PBS(x) tree<x,null_type,less<x>,rb_tree_tag,tree_order_statistics_node_update>
#define PBM(x,y) tree<P(x,y),null_type,less<P(x,y)>,rb_tree_tag,tree_order_statistics_node_update>
#define MOD 1000000007
#define pi (long double)acos(-1)
 
int modInv(int a,int b){if(b==0){return 1;}int k=modInv(a,b/2);
if(b&1){return (((a*k)%MOD)*k)%MOD;}return (k*k)%MOD;}
 
V(V(int))adj;
V(int) dist;
int node1,maxi,depth;
void dfs(int node,int parent){
    dist[node]=max(dist[node],depth);
    if(depth>maxi){
        maxi=depth;
        node1=node;
    }
    for(A it:adj[node]){
        if(it!=parent){
            depth++;
            dfs(it,node);
            depth--;
        }
    }
}
I main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin>>n;
    adj.resize(n+1);
    asc(i,0,n-1){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dist.resize(n+1,INT_MIN);
    depth=0;
    maxi=INT_MIN;
    dfs(1,1);
    depth=0;
    maxi=INT_MIN;
    dfs(node1,node1);
    depth=0;
    dfs(node1,node1);
    asc(i,1,n+1){
        cout<<dist[i]<<" ";
    }
}
