#include <bits/stdc++.h>
using namespace std;
 
const int N = 100005;
 
vector<int> adj_list[N];
bool visited[N];
int parent[N];
vector<int> cycle;
 
void dfs(int current) // function to detect a cycle in a graph.
{
    visited[current] = true;
    // cout << current << " ";
    // cout << "parent of " << current << " is " << parent[current] << "\n";
    // parent[current] = current;
    for (int i = 0; i < adj_list[current].size(); i++)
    {
        if (visited[adj_list[current][i]] == false)
        {
            int vertex = adj_list[current][i];
            parent[vertex] = current;
            if (!cycle.size())
            {
                for (int j = 0; j < adj_list[vertex].size(); j++)
                {
                    if (visited[adj_list[vertex][j]] == true && (adj_list[vertex][j] != parent[vertex]))
                    {
                        int predecessor = vertex;
                        cycle.push_back(adj_list[vertex][j]);
                        while (predecessor != adj_list[vertex][j])
                        {
                            // cout << "value of predecessor is " << predecessor << "\n";
                            cycle.push_back(predecessor);
                            predecessor = parent[predecessor];
                        }
                        cycle.push_back(predecessor);
                        // return;
                    }
                }
            }
            dfs(vertex);
        }
    }
    // return false;
}
 
int main()
{
    int vertices, edges;
    cin >> vertices >> edges;
    int x, y;
    for (int i = 0; i < edges; i++)
    {
        cin >> x >> y;
        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
    }
    parent[1] = -1;
    for(int i=1;i<=vertices;i++)
    {
        if(visited[i] == false)
        {
            dfs(i);
        }
    }
    if (cycle.size() == 0)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    else
    {
        cout<<cycle.size()<<"\n";
        for (int i = 0; i < cycle.size(); i++)
        {
            cout << cycle[i] << " ";
        }
    }
}
