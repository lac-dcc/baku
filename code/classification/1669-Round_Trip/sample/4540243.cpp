#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
int n,m;
vector<int> ans;
bool found = false;
void dfs(int node, vector<int> &curr, vector<int> &vis, int parent){
    if (found) return;
    for (auto x: graph[node]){
        if (found) break;
        if (x == parent) continue;
        if (vis[x] == 0){
            vis[x] = 1;
            curr.push_back(x);
            dfs(x, curr, vis, node);
            curr.pop_back();
        }
        else{
            found = true;
            // cout<<"Cycle found "<<node<<" "<<x<<endl;
            curr.push_back(x);
            ans = curr;
            return;
        }
    }
}
int main(){
    cin>>n>>m;
    for (int i = 0; i <= n; i++){
        graph.push_back({});
    }
    for (int i = 0; i < m; i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> vis (n+1, 0);
    vector<int> curr;
    for (int i = 1; i <= n; i++){
        if (found) break;
        if (vis[i] == 0){
            curr.push_back(i);
            vis[i] = 1;
            dfs(i, curr, vis, -1);
        }
        curr.clear();
    }
    if (ans.size() == 0){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    int left = 0, right = ans.size() - 1;
    while(ans[left] != ans[right]){
        left++;
    }
    cout<<right - left + 1<<endl;
 
    for (int i = left; i <= right; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
