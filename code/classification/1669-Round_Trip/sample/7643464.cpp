#include <bits/stdc++.h>
 
 
#define int long long
 
 
using namespace std;
 
vector<int> col;
vector<int> par;
vector<int> ans;
vector<vector<int>> g;
int flag = 0;
 
void dfs(int node, int parent) {
    col[node] = 2;
    par[node] = parent;
    for (auto v : g[node]) {
        if (v==parent) continue;
        if (col[v]==1) dfs(v, node);
        else if (col[v]==2) {
            if (flag) continue;
            int temp = node;
            int sz = 1;
            ans.push_back(v);
            ans.push_back(temp);
            while (temp!=v) {temp = par[temp]; ans.push_back(temp); sz++;}
            flag=1;
        }
    }
    col[node] = 3;
}
 
 
void solve(){
    int n, m; cin>>n>>m;
    g.resize(n+1);
    col.assign(n+1, 1);
    par.assign(n+1, 0);
    for (int i = 0; i < m; i++) {
        int a, b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (col[i]==1) {
            dfs(i, 0);
            if (flag) {
                cout<<ans.size()<<"\n";
                for (auto v : ans) {
                    cout<<v<<" ";
                }
                return;
            }
        }
    }
    cout<<"IMPOSSIBLE\n";
}
 
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // int _t;cin>>_t;while(_t--)
    solve();
}
