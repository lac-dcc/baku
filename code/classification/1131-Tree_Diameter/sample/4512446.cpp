#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>> adj;
vector<int> ans;
vector<int> depth;
int finalans = 0;
void dfs(int node,int par){
    int m1,m2;
    m1 = m2 = -1;
    for(auto &child : adj[node]){
        if(child != par){
            dfs(child,node);
            if(depth[child] >= m1){
                
                m2 = m1;
                m1 = depth[child];
            }
            else if(depth[child] > m2){
                m2 = depth[child];
            }
        }
    }
    ans[node] = m1 + m2 + 2;
    depth[node] = m1 + 1;
    finalans = max(finalans,ans[node]);
}
int32_t main(){
    int n;
    cin>>n;
    adj.resize(n);
    ans.resize(n);
    depth.resize(n);
    for(int i =0;i < n-1; i++){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0,-1);
    cout<<finalans<<" ";
    return 0;
}
