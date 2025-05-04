#include <bits/stdc++.h>
#include <array>
#include <unordered_map>
using namespace std;
template<typename T = int> vector<T> create(size_t n){ return vector<T>(n); }
template<typename T, typename... Args> auto create(size_t n, Args... args){ return vector<decltype(create<T>(args...))>(n, create<T>(args...)); }
unsigned seed = chrono::system_clock::now().time_since_epoch().count();
using ll = long long;
using ull = unsigned long long;
using vpi = vector<pair<int, int>>;
using pii = pair<int, int>;
 
struct forest {
    vector<pair<int,int>> edges;
    vector<vector<int>> to, lg_parents;
    vector<int> sub, color, parent, depth, pre, ord, in, out;
    int comps, n, lgn, C;
    forest(int n): n(n) {
        to.resize(n); 
        sub.assign(n, 0); 
        color.assign(n, 0); 
        parent.resize(n); 
        depth.assign(n, 0);
        in.resize(n);
        out.resize(n);
    }
    void add_edge(int u, int v){
        int id = edges.size();
        assert(id < n - 1);
        edges.push_back(make_pair(u, v));
        to[u].push_back(id);
        to[v].push_back(id);
    }
    inline int adj(int u, int id){ return u ^ edges[id].first ^ edges[id].second; }
    void dfs(int u, int p){
        pre.push_back(u);
        in[u] = C++;
        color[u] = comps;
        parent[u] = p;
        sub[u] = 1;
        for(int id : to[u]){
            int v = adj(u, id);
            if(v == p) continue;
            depth[v] = depth[u] + 1;
            dfs(v, u);
            sub[u] += sub[v];
        }
        out[u] = C;
        ord.push_back(u);
    }
    bool is_ancestor(int u, int v){
        return in[u] <= in[v] && out[v] <= out[u];
    }
    void dfs_all(){
        comps = 0;
        C = 0;
        for(int i = 0; i < n; i++){
            if(!color[i]){
                ++comps;
                dfs(i, -1);
            }
        }
    }
    void build_parents(){
        lgn = 0;
        while((1<<lgn) <= n) lgn++;
        lg_parents.assign(lgn, vector<int>(n, -1));
        for(int i = 0; i < n; i++)
            lg_parents[0][i] = parent[i];
        for(int i = 1; i < lgn; i++){
            for(int j = 0; j < n; j++){
                if(~lg_parents[i - 1][j]){
                    lg_parents[i][j] = lg_parents[i - 1][lg_parents[i - 1][j]];
                }
            }
        }
    }
    int jump(int u, int k){
        for(int i = lgn - 1; i >= 0; i--) if(k&(1<<i)) u = lg_parents[i][u];
        return u;
    }
    int lca(int u, int v){
        if(depth[u] < depth[v]) swap(u, v);
        for(int i = lgn - 1; i >= 0; i--)
            if((depth[u] - depth[v])&(1<<i))
                u = lg_parents[i][u];
        if(u == v)
            return u;
        for(int i = lgn - 1; i >= 0; i--)
            if(lg_parents[i][u] != lg_parents[i][v]){
                u = lg_parents[i][u];
                v = lg_parents[i][v];
            }
        return lg_parents[0][u];
    }
    int dist(int u, int v){
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }
};
 
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  forest fo(n);
  for(int i = 1; i < n; i++){
    int u; cin >> u;
    fo.add_edge(u - 1, i);
  }
  fo.dfs_all();
  for(int i = 0; i < n; i++) cout << fo.sub[i] - 1 << ' ';
  return 0;
}
