#include <bits/stdc++.h>
using namespace std;
 
int n,m;
vector<int> graph[100005];
int color[100005]; //0: unvisited //1: visiting //2: visited
int parent[100005];
int cycle=0;
vector<int> out;
 
void dfs(int node)
{
    if (cycle) return;
 
    //cerr<<node<<"\n";
    color[node] = 1;
 
    for (int i : graph[node])
    {
        if (cycle) return;
        if (parent[node] == i) continue;
        parent[i] = node;
        if (color[i] == 1)
        {
            cycle = node;
            return;
        }
        if (!color[i]) dfs(i);
    }
 
    color[node] = 2;
}
 
void print()
{
    for (int i=1; i<=n; i++) cerr << i << ' ' << parent[i] << endl;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> n >> m;
    for (int i=0; i<m; i++)
    {
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
 
    for (int i=1; i<=n; i++)
    {
        if (color[i] == 2) continue;
        dfs(i);
 
        if (cycle) break;
    }
 
    //cout << endl << cycle << endl;
 
    //print();
 
    if (!cycle)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
 
    int node = cycle;
    do
    {
        out.push_back(node);
        node = parent[node];
    } while (node != cycle);
    out.push_back(cycle);
 
    cout << out.size() << endl;
    for (int i : out) cout << i << ' ';
 
}
 
