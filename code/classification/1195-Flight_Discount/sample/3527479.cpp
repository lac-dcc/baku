#include <iostream>
#include <vector>
#include <queue>
 
struct node {
    int x;
    int bonus;
    long long val;
};
 
bool operator <(const node &x, const node &y) {
    return x.val > y.val;
}
 
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie();
    std::cin.tie();
 
    int n, m;
    std::cin >> n >> m;
 
    std::vector<std::vector<std::pair<int, int> > > graph;
    std::vector<std::pair<int, int> > vec;
    graph.insert(graph.begin(), n + 1, vec);
    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        std::cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
 
    long long dp[n + 1][2];
    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i][1] = 1e18;
    }
 
    std::priority_queue<node> pq;
    pq.push({1, 0, 0});
 
    while (!pq.empty()) {
        node mom = pq.top();
        pq.pop();
 
        if (dp[mom.x][mom.bonus] <= mom.val) {
            continue;
        }
        dp[mom.x][mom.bonus] = mom.val;
        if (mom.x == n) {
            break;
        }
 
        for (auto &p : graph[mom.x]) {
            if (mom.bonus == 0) {
                if (dp[p.first][0] > mom.val + p.second) {
                    pq.push({p.first, 0, mom.val + p.second});
                }
                if (dp[p.first][1] > mom.val + (p.second / 2)) {
                    pq.push({p.first, 1, mom.val + (p.second / 2)});
                }
            } else {
                if (dp[p.first][1] > mom.val + p.second) {
                    pq.push({p.first, 1, mom.val + p.second});
                }
            }
        }
    }
    std::cout << std::min(dp[n][0], dp[n][1]) << '\n';
    return 0;
}
