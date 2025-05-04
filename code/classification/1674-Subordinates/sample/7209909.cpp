#include <bits/stdc++.h>
using namespace std;
int dfs(int node,vector<int> adj[],vector<int> &ans){
    for(auto it: adj[node]){
        ans[node]+=dfs(it,adj,ans);
    }
    return 1+ans[node];
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin>>n;
    vector<int> adj[n+1],ans(n+1,0);
    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        adj[x].push_back(i);
    }
    dfs(1,adj,ans);
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    cout<<endl;
    return  0;
}
