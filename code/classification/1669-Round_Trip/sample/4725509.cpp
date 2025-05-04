/*
    author:    Newplayers12
    created:   Saturday 01-10-2022  18:17:21
*/
#include <bits/stdc++.h>
using namespace std;
 
#define all(X) X.begin(), X.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
 
const int MXN = 1e5;
int n, m;
int color[MXN + 2];
bool can = false;
vector<int> graph[MXN + 2];
vector<int> ans;
vector<int> path;
void dfs(int par, int u){
    color[u] = 1;
    path.push_back(u);
    for(int v:graph[u]){
        if (color[v] == 1){
            int len = path.size();
            if (len >= 2){
                if (path[len - 2] != v ){
                    can = true;
                    bool flag = false;
                    for(int x:path){
                        if (x == v) flag = true;
                        if (flag) ans.push_back(x);
                    }
                    return;
                }
            }
            
        } else 
        if (color[v] == 0){
            dfs(u, v);
            if (can) return;
        }
    }
    path.pop_back();
    color[u] = 2;
}
 
int main()
{
    fastio;
    cin >> n >> m;
    memset(color, 0, sizeof(color));
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }    
    for(int i = 0; i < n; ++i){
        if (color[i] == 0){
            dfs(-1, i);
        }
        if (can) break;
    }
    if (ans.empty()) {
        cout << "IMPOSSIBLE";
    } else {
        cout << ans.size() + 1 << '\n';
        for(int x:ans) cout << x + 1 << ' ';
        cout << ans[0] + 1;    
    }
    
    return 0;
}
