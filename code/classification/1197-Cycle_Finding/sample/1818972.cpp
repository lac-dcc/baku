#include <iostream>
#include <vector>
#include <utility>
using namespace std;
 
#define MAXN 2500000000000
long long int dist[2500];
int parent[2500];
bool visited[2500];
 
int find_begin(int node)
{
    if (visited[node]) return node;
    visited[node] = true;
    return find_begin(parent[node]);
}
 
void print_sol(int cur, int stop)
{
    if (parent[cur] != stop)
        print_sol(parent[cur], stop);
    else cout << stop+1;
    cout << " " << cur+1;
}
 
void solve(vector<pair<pair<int, int>, long long int>> &edges, int n)
{
    for (int i = 0; i < n; i++)
    {
        dist[i] = MAXN;
        parent[i] = i;
    }
 
    dist[0] = 0;
 
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < edges.size(); j++)
        {
            int a = edges[j].first.first;
            int b = edges[j].first.second;
            long long int w = edges[j].second;
            if (dist[a] + w < dist[b])
            {
                dist[b] = dist[a] + w;
                parent[b] = a;
            }
        }
    }
 
    int begin = n;
    for(int j = 0; j < edges.size(); j++)
    {
        int a = edges[j].first.first;
        int b = edges[j].first.second;
        long long int w = edges[j].second;
        if (dist[a] + w < dist[b])
        {
            dist[b] = dist[a] + w;
            parent[b] = a;
            begin = find_begin(a);
            break;
        }
    }
    if (begin == n)
        cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        begin = find_begin(begin);
        print_sol(begin, begin);
        cout << endl;
    }
    return;
}
 
 
int main()
{
    int n, m;
    int a, b;
    long long int c;
    vector<pair<pair<int, int>, long long int>> edges;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        edges.push_back(make_pair(make_pair(a - 1, b - 1), c));
    }
    solve(edges, n);
    return 0;
}
 
