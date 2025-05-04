#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define MP make_pair
#define S second
#define F first
 
using namespace std;
using ii = pair<int, int>;
 
const int MOD = 1e9+7;
const int INF = 1e18;
 
int n; 
vector<int> g[200100];
 
int dep[200100];
int par[200100];
 
void dfs(int node, int depth, int parent){
    dep[node] = depth;
    par[node] = parent;
    for(auto v: g[node]){
        if(v!=parent){
            dfs(v, depth+1, node);
        }
    }
}
 
void solve(){
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
 
    dfs(1,0,0);
 
    int x = max_element(dep+1, dep+n+1) - dep;
 
    // for(int i=1;i<=n;i++)cout<<dep[i]<<' ';
    // cout<<endl;
 
    dfs(x,0,0);
 
    // for(int i=1;i<=n;i++)cout<<dep[i]<<' ';
    // cout<<endl;
 
    cout<<*max_element(dep+1, dep+n+1)<<endl;
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
 
    int t = 1;
    // cin>>t;
    while(t--)solve();
}
