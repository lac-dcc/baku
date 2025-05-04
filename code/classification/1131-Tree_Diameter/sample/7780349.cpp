#include <iostream>
#include <vector>
#include <climits>
using namespace std;
 
vector<vector<int>> tree;
 
pair<int, int> dfs(int u, int p)
{
    if (tree[u].empty())
    {
        return {0, 0};
    }
    int d = INT_MIN, a = INT_MIN;
    for (int v : tree[u])
    {
        if (v == p)
            continue;
        auto [an, de] = dfs(v, u);
        a = max(a, an);
        a = max(a, d + de + 1);
        d = max(d, de + 1);
    }
    return {a, d};
}
 
int main()
{
    int n;
    cin >> n;
    tree.resize(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        tree[u - 1].push_back(v - 1);
        tree[v - 1].push_back(u - 1);
    }
    cout << dfs(0, -1).first;
}
