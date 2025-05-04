#include <bits/stdc++.h>
using namespace std;
 
const int MEX = 2e5 + 10;
vector<int> ans;
vector<int> tree[MEX];
vector<int> depth;
 
void dfs(int src, int par = -1) {
    for (auto &child : tree[src]) {
        if (child == par) continue;
        depth[child] = depth[src] + 1;
        dfs(child, src);
        ans[child] = max(ans[child], depth[child]);
    }
    ans[src] = max(ans[src], depth[src]);
}
 
int main() {
    int n;
    cin >> n;
    ans.resize(n + 1);  // Resize the vectors to the size of the tree
    depth.resize(n + 1);
 
    for (int i = 2; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
 
    dfs(1, 0);
    int node1 ;
    int diameter_end1 = -1;
    for(int i = 1;i<=n;i++){
       if(diameter_end1 < ans[i]){
           diameter_end1 = ans[i] ;
           node1 = i ;
       }
       depth[i] = 0 ;
    }
    
    dfs(node1) ;
    node1 = -1;
    diameter_end1 = -1;
    
    for(int i = 1;i<=n;i++){
       if(diameter_end1 < ans[i]){
           diameter_end1 = ans[i] ;
           node1 = i ;
       }
       depth[i] = 0 ;
    }
    dfs(node1) ;
    
    for(int i = 1;i<=n;i++)
    cout << ans[i] << ' ' ;
    cout << endl;
   
   
    
 
    // for (int i = 1; i <= n; i++)
    //     cout << ans[i] << ' ';
    // cout << endl;
 
    return 0;
}
