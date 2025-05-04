#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef pair <long long, long long> pii;
long long n, m;
void dijkstra(int x, vector<long long>&dist, vector<vector<pii>>&v1){
   dist[x] = 0;
   priority_queue<pii, vector<pii>, greater<pii>> q;
   q.push({0, x});
   while(!q.empty()){
    int pi = q.top().second;
    long long pd = q.top().first;
    q.pop();
    if(pd > dist[pi]){
        continue;
    }
    for(auto c:v1[pi]){
        if(dist[c.first] > dist[pi] + c.second){
            dist[c.first] = dist[pi] + c.second;
            q.push({dist[c.first], c.first});
        }
    }
   }
}
int main(){
    cin>>n>>m;
    vector<vector<pii>> v1(n + 1);
    vector<vector<pii>> v2(n + 1);
    vector<long long> dist(n + 2, LLONG_MAX/2);
    vector<long long> dist2(n + 2, LLONG_MAX/2);
    long long a, b, w;
    for(int i = 1; i <= m; i++){
        cin>>a>>b>>w;
        v1[a].push_back({b, w});
        v2[b].push_back({a, w});
    }
    dijkstra(1, dist, v1);
    dijkstra(n, dist2, v2);
    long long rta = LLONG_MAX/2;
    for(int i = 1; i <= n; i++){
        for(auto c: v1[i]){
            rta = min(rta, dist[i] + dist2[c.first] +(c.second / 2));
        }
    }
    cout<<rta<<endl;
 
 
    return 0;
}
