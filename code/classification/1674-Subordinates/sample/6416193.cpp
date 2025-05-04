//Subordinates
//https://cses.fi/problemset/task/1674
#include <bits/stdc++.h>
using ll = long long;
int mod = 1e9+7;
 
void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> directSubordinates(n + 1);
    for (int i = 2; i < n + 1; i++) {
        int boss;
        std::cin >> boss;
        directSubordinates[boss].push_back(i);
    }
 
    //Reverse level order traversal to set up bottom-up dp (bfs via queue and push visited nodes to bottom of stack)
    //Simpler version bc the order at which nodes on a specific level are traversed does not matter
    std::queue<int> toVisit;
    std::vector<bool> visited(n + 1, false);
    std::stack<int> toTraverse;
    toVisit.push(1);
    while (!toVisit.empty()) {
        int v = toVisit.front();
        toVisit.pop();
        visited[v] = true;
        toTraverse.push(v);
        for (int u : directSubordinates[v]) {
            toVisit.push(u);
        }
    }
 
    std::vector<int> traversalOrder;
    while (!toTraverse.empty()) {
        traversalOrder.push_back(toTraverse.top());
        toTraverse.pop();
    }
 
    std::vector<int> totalSubordinates(n + 1, 0);
    for (int i : traversalOrder) {
        for (int j : directSubordinates[i]) {
            totalSubordinates[i] += (totalSubordinates[j] + 1);
        }
    }
 
    for (int i = 1; i < n + 1; i++) {
        std::cout << totalSubordinates[i] << " ";
    }
    std::cout << "\n";
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
}
