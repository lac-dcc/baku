// @Author by : hyxinchou
#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
 
using i64 = long long;
 
int main() {
    std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);
    // Insert your code
 
    int n, m; std::cin >> n >> m;
 
    std::vector<std::vector<int>> edges(n);
    for (int i = 0; i < m; ++i) {
        int u, v; std::cin >> u >> v;
        --u, --v;
 
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
 
    std::vector<int> col(n, -1);
    std::vector<int> par(n, -1);
    std::vector<int> T(n, 0);
 
    auto dfs = [&](auto self, int u, int p) -> void {
        for (auto v : edges[u]) {
            if (col[v] == 1 && T[u] - T[v] >= 2) {
                // std::cerr << u << " " << v << "\n";
                // std::cerr << T[u] << " " << T[v] << "\n";
 
                std::vector<int> path;
                int curr = u;
 
                path.push_back(v);
 
                while (curr != v) {
                    if (curr == -1) {
                        break;
                    }
 
                    path.push_back(curr);
 
                    curr = par[curr];
                }
 
                // curr = v;
 
                // // std::cerr << par[v] << "\n\n";
 
                std::vector<int> path2;
 
                // while (curr != path.back()) {
                //     if (curr == -1) {
                //         break;
                //     }
 
                //     path2.push_back(curr);
 
                //     curr = par[curr];
                // }
 
                path.push_back(v);
 
                std::reverse(all(path));
                // std::reverse(all(path2));
 
                std::cout << int(path.size()) + int(path2.size()) << "\n";
 
                // for (auto v : path2) {
                //     std::cout << v + 1 << " ";
                // }
 
                for (auto v : path) {
                    std::cout << v + 1 << " ";
                }
 
                std::cout << "\n";
 
                exit(0);
            }
 
            if (v != p) {
                if (col[v] == -1) {
                    col[v] = 1;
                    T[v] = T[u] + 1;
                    par[v] = u; // ?
 
                    // if (v == 9) {
                    //     std::cout << u << "\n";
                    // }
 
                    self(self, v, u);
                }
            }
        }
    };
 
    for (int i = 0; i < n; ++i) {
        if (col[i] == -1) {
            // std::cerr << i << "\n";
 
            col[i] = 1;
 
            dfs(dfs, i, -1);
        }
    }
 
    std::cout << "IMPOSSIBLE\n";
 
    return 0;
}
