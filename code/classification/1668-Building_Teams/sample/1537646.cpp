#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
bool checkEqualTeam(vector<int> graph[], int teams[], int currentVertex) 
{
    for (unsigned int i = 0; i < graph[currentVertex].size(); i++) {
        if (teams[graph[currentVertex][i]] == -1) {
            continue;
        }
 
        if (teams[graph[currentVertex][i]] == teams[currentVertex]) {
            return true;
        }
    }
 
    return false;
}
 
void dfs(vector<int> graph[], bool isVisited[], int teams[], int startVertex, int teamNumber, bool& flag)
{
    isVisited[startVertex] = true;
    teams[startVertex] = teamNumber;
 
    if (checkEqualTeam(graph, teams, startVertex)) {
        // cout << "Friend Found" << endl;
        flag = false;
    }
 
    for (unsigned int i = 0; i < graph[startVertex].size(); i++) {
        if (!isVisited[graph[startVertex][i]]) {
            dfs(
                graph,
                isVisited,
                teams,
                graph[startVertex][i],
                ((teamNumber == 1) ? 2 : 1),
                flag
            );
        }
    }
}
 
void solution()
{
    int n, m;
    cin >> n >> m;
 
    int teams[n + 1];
    bool isVisited[n + 1];
 
    vector<int> graph[n + 1];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
 
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
 
    for (int i = 1; i <= n; i++) {
        isVisited[i] = false;
        teams[i] = -1;
    }
 
    bool flag = true;
 
    for (int i = 1; i <= n; i++) {
        if (!isVisited[i]) {
            // flag = flag && dfs(graph, isVisited, teams, i, 1);
            dfs(graph, isVisited, teams, i, 1, flag);
        }
    }
 
    if (flag) {
        for (int i = 1; i <= n; i++) {
            cout << teams[i] << " ";
        }
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
 
 
 
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    solution();
 
    return 0;
}