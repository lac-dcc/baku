#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
 
vector<int> list[100001];
bool visited[100001];
 
void dfs(int node)
{
    visited[node] = true;
    for (int j = 0; j < list[node].size(); j++)
    {
        if (!visited[list[node][j]])
        {
            dfs(list[node][j]);
        }
    }
}
 
int main()
{
    //for old usaco:
    //freopen("filename.in", "r", stdin);
    //freopen("filename.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    //n = cities, m = roads
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        list[a].push_back(b);
        list[b].push_back(a);
    }
    
    vector<int> repair;
    
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            repair.push_back(i);
            count++;
            dfs(i);
        }
    }
    cout << count - 1 << endl;
    for (int i = 1; i < count; i++)
    {
        cout << repair[i - 1] << " " << repair[i] << endl;
    }
    return 0;
}
 
