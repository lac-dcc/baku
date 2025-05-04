#include <iostream>
#include <vector>
#include <algorithm>
 
const int N = 2e5 + 10;
std::vector<std::vector<int>> tree(N);
int height[N][2], back_dist[N];
 
void find_heights(int v, int p) {
    std::vector<int> heights;
    for (int child : tree[v]) {
        if (child == p) continue;
        find_heights(child, v);
        heights.push_back(height[child][0] + 1);
    }
    std::sort(heights.rbegin(), heights.rend());
    if (heights.size() > 0) height[v][0] = heights[0];
    if (heights.size() > 1) height[v][1] = heights[1];
}
 
void find_dists(int v, int p) {
    if (back_dist[p] >= height[p][0]) {
        back_dist[v] = back_dist[p] + 1;
    } else {
        if (height[v][0] == height[p][0] - 1) {
            back_dist[v] = std::max(height[p][1], back_dist[p]) + 1;
        } else {
            back_dist[v] = height[p][0] + 1;
        }
    }
    for (int child : tree[v]) {
        if (child == p) continue;
        find_dists(child, v);
    }
}
 
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
 
    int n;
    std::cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        std::cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    find_heights(1, 0);
    back_dist[0] = height[0][0] = height[0][1] = -1;
    find_dists(1, 0);
    for (int i = 1; i <= n; ++i) {
        std::cout << std::max(height[i][0], back_dist[i]) << ' ';
    }
    std::cout << std::endl;
}
