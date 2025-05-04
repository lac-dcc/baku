#include <bits/stdc++.h>
using namespace std;
 
int dfs(int start, vector<vector<int>> &roads, vector<int> &path, vector<bool> &visited)
{
    visited[start] = true;
    for (int neighbors : roads[start])
    {
        if (neighbors == path[start])
        {
            continue;
        }
        if (visited[neighbors])
        {
            path[neighbors] = start;
            return neighbors;
        }
        else
        {
            path[neighbors] = start;
            int temp = dfs(neighbors, roads, path, visited);
            if (temp > 0)
            {
                return temp;
            }
        }
    }
    return -1;
}
 
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> roads(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        roads[a].push_back(b);
        roads[b].push_back(a);
    }
    vector<int> path(n + 1, -1);
    vector<bool> visited(n + 1, false);
    bool flag = false;
    int final;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            final = dfs(i, roads, path, visited);
            if (final > 0)
            {
                flag = true;
                break;
            }
        }
    }
    if (!flag)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    deque<int> parents;
    int itr = final;
    parents.push_front(final);
    itr = path[itr];
    while (itr != final)
    {
        parents.push_front(itr);
        itr = path[itr];
    }
    parents.push_front(final);
    cout << parents.size() << endl;
    while (!parents.empty())
    {
        cout << parents.front() << " ";
        parents.pop_front();
    }
    return 0;
}
