#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#define int long long
using namespace std;
 
bool comp(pair<int, int> a, pair<int, int> b){
    return a.second<b.second;
}
 
 
int32_t main(){
    int n, m;
    cin >> n >> m;
    vector<int> ans(n+1, INT64_MAX);
    vector<bool> visited(n+1, false);
    ans[1] = 0;
    vector<pair<int, int> > edges[n+1];
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back({b, c});
    }
 
    priority_queue<pair<int, int> > pq;
    pq.push({0, 1});
    int count = 0;
    while(!pq.empty() && count<n){
        int current_node = pq.top().second;
        pq.pop();
        if(visited[current_node]) continue;
        count++;
        visited[current_node] = true;
 
        for(auto i: edges[current_node]){
            if(ans[i.first]>(ans[current_node]+i.second)){
                ans[i.first] = ans[current_node] + i.second;
                pq.push({-ans[i.first], i.first});
            }
        }
    } 
 
    for(int i=1; i<n+1; i++){
        cout << ans[i] << " ";
    }
    
 
}
