#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> routes(n+1);
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        routes[x].push_back(y);
        routes[y].push_back(x);
    }
    vector<bool> vis(n+1);
    queue<pair<int, int>> q;
    vector<int> prev(n+1);
    q.push({1, 0});
    vis[1] = 1;
    while(!q.empty()){
        pair<int, int> computer = q.front();
        q.pop();
        for(int next: routes[computer.first]){
            if(!vis[next]){
                vis[next] = 1;
                prev[next] = computer.first;
                q.push({next, computer.first});
            }
        }
    }
    vector<int> ans;
    if(!vis[n]){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    while(n){
        ans.push_back(n);
        n = prev[n];
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(int computer : ans){
        cout << computer << " ";
    }
}
