#include <bits/stdc++.h>
using namespace std;
 
#ifdef LOCAL
#include "/tmp/debug.h"
#else
#define debug(...) 42
#endif
 
#define int long long
int32_t main(){
    int n; cin>>n;
    vector<vector<int>> edges(n);
    for(int i = 0; i < n - 1; i++){
        int x, y; cin>>x>>y;
        x--; y--;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    pair<int, int> best = {0, 0};
    function<void(int, int, int)> dfs = [&](int u, int par, int len){
            best = max(best, {len, u});
            for(int nxt: edges[u]){
                if(nxt == par) continue;
                dfs(nxt, u, len + 1);
            }
    };
    dfs(0, -1, 0);
    int start = best.second;
    dfs(start, -1, 0);
    cout<<best.first<<'\n';
    return 0;
}
 
