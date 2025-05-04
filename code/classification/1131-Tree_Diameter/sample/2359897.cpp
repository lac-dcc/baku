#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
 
using namespace std;
 
vector<vector<int> > graph;
vector<bool> vis;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; 
    cin >> n;
    graph = vector<vector<int> >(n+1);
    vis = vector<bool> (n+1);
    for(int i = 0; i < n-1; i++){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    queue<pair<int,int> > q;
    q.push(make_pair(1,0));
    vis[1] = true;
    int deepestNode = 0;
    int deepNode = 1;
 
    while(q.size()!=0){
        pair<int,int> now = q.front();
        q.pop();
        if(now.second>deepestNode){
            deepestNode = now.second;
            deepNode = now.first;
        }
        for(int i = 0; i < graph[now.first].size(); i++){
            if(vis[graph[now.first][i]]==true){
                continue;
            }
            vis[graph[now.first][i]] = true;
            q.push(make_pair(graph[now.first][i], now.second+1));
        }
    }
 
    q.push(make_pair(deepNode, 0));
    vis = vector<bool> (n+1);
    vis[deepNode] = true;
    deepestNode = 0;
    while(q.size()>0){
        pair<int,int> now = q.front();
        q.pop();
        if(now.second>deepestNode){
            deepestNode = now.second;
        }
        for(int i = 0; i < graph[now.first].size(); i++){
            if(vis[graph[now.first][i]]==true){
                continue;
            }
            vis[graph[now.first][i]] = true;
            q.push(make_pair(graph[now.first][i], now.second+1));
        }
    }
 
    cout << deepestNode;
    return 0;
}
