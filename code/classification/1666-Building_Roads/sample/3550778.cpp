// Author: it_aint_me
// Created: 2022-02-16	18:20:26
 
#include <bits/stdc++.h>
using namespace std;
 
// 1666 - Building Roads
class DSU {
    std::vector<int> root;
    std::vector<int> rank;
public:
    DSU() : root(std::vector<int>()), rank(std::vector<int>()) {}
 
    DSU(int size) {
        rank = std::vector<int>(size, 1);
        root = std::vector<int>(size, 0);
        for (int i = 0; i < size; i++)
            root[i] = i;
    }
 
    int find(int x) {
        // O(alpha(N)) -> Constant time on average
        assert(x >= 0 && x < root.size());
        if (x == root[x])
            return root[x];
 
        return root[x] = find(root[x]);
    }
 
    void union_set(int x, int y) {
        // O(alpha(N)) -> Constant time on average
        assert(x >= 0 && x < root.size());
        assert(y >= 0 && y < root.size());
        
        // Merge the shorter tree into longer for optimal height
        int root_x = find(x);
        int root_y = find(y);
        if (root_x != root_y) {
            if (rank[root_x] > rank[root_y]) {
                root[root_y] = root_x;
            } else if (rank[root_y] > rank[root_x]) {
                root[root_x] = root_y;
            } else {
                // Here either way height increases by 1
                root[root_y] = root_x;
                rank[root_x]++;
            }
        }
    }
 
    bool is_connected(int x, int y) {
        // O(alpha(N)) -> Constant time on average
        assert(x >= 0 && x < root.size());
        assert(y >= 0 && y < root.size());    
        return find(x) == find(y);
    }
};
 
void run_case() {
    int n, m;   cin >> n >> m;
    DSU dsu(n);
 
    for (int i = 0; i < m; i++) {
        int u, v;   cin >> u >> v;  u--, v--;
        dsu.union_set(u, v);
    }
 
    unordered_set<int> components;
    for (int i = 0; i < n; i++)
        components.insert(dsu.find(i));
 
    cout << components.size() - 1 << '\n';
    int u = *components.begin();    components.erase(u);
    while (!components.empty()) {
        int v = *components.begin();
        cout << u + 1 << ' ' << v + 1 << '\n';
        components.erase(v);
    }
}
 
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
 
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    // int _;  cin >> _;  
    // while (_--)
        run_case();
 
    return 0;
}
 
