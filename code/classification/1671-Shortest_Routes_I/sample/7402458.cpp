#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;   
    vector<vector<pair<int,long long>>> adj (n+1,vector<pair<int,long long>>());
    vector<long long> dis (n+1);
    for(int i = 0; i < m; i++){
        int a,b;
        long long w;
        cin >> a >> b >> w;
        adj[a].push_back(make_pair(b,w));
    }
    for(int i = 2; i <=n; i++){
        dis[i] = LLONG_MAX;
    }
    dis[1]=0;
    vector<bool> visited (n+1,false);
    priority_queue<pair<long long,int>> q;
    q.push(make_pair(0,1));
    while(!q.empty()){
        int a = q.top().second;
        q.pop();
        if(visited[a]){
            continue;
        }
        visited[a]=true;
        for(int i = 0; i < adj[a].size(); i++){
            if(adj[a][i].second+dis[a]<dis[adj[a][i].first]){
                dis[adj[a][i].first]=adj[a][i].second+dis[a];
                q.push(make_pair(-1*dis[adj[a][i].first],adj[a][i].first));
            }
        }
    }
    for(int i = 1; i <=n ; i++){
        cout << dis[i] << " ";
    }
    cout << "\n";
    return 0;
}
