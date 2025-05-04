#include <bits/stdc++.h>
using namespace std;
#define N 100005
 
int vis[N];
vector<int> g[N];
vector<int> ans;
vector<int> res_ans;
bool ok = false;
 
void dfs(int node, int par) {
    if(vis[node] == 2) {
        ans.push_back(node);
        ok = true;
        return;
    }
    vis[node] = 2;
    ans.push_back(node);
    for(auto v: g[node]) {
        if(ok){
            return;
        }
        if(v == par)
            continue;
        dfs(v, node);
    }
    if(!ok){
        vis[node] = 1;
        ans.pop_back();
    }
}
 
int main() {
    int n,m;
    cin>>n>>m;
    vector<pair<int,int> > edges;
    for(int i = 0;i<m;i++) {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
        edges.push_back(make_pair(a,b));
    }
    for(int i = 1;i<=n;i++) {
        if(!ok) {
            if(vis[i] == 0){
                dfs(i, 0);
            }
        }
    }
    if(!ok){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    bool flag = 0;
    for(auto v: ans){
        if(!flag){
            if(v != ans[ans.size()-1]) {
                continue;
            }
            else{
                flag=1;
            }
        }
        if(flag){
             res_ans.push_back(v);
        }
    }
    cout<<res_ans.size()<<endl;
    for(auto v: res_ans){
        cout<<v<<" ";
    }
    // your code goes here
    return 0;
}
