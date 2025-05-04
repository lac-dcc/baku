#include <bits/stdc++.h>
 
using namespace std;
 
#define MAXN 100000
#define ll long long
 
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
bool visited[MAXN];
long long distance_from_start[MAXN];
 
int main() {
    int n, m;
    cin >> n >> m;
 
    //vector<pair<ll, ll>> adjList[n]{};
    vector<pair<long long, long long>> adjList[n]; 
    for (int i=0; i<m; i++) {
        ll a, b, w;
        cin >> a >> b >> w;
 
        a--; b--;
 
        adjList[a].push_back({w, b});
    }
 
 
    long long distance_from_start[n];
    for (int i=0; i<n; i++) distance_from_start[i] = LLONG_MAX;
 
    distance_from_start[0] = 0;
    pq.push({0, 0});
 
    
 
 
    ll curr_weight;
    int curr_node;
 
    while (!pq.empty()) {
        tie(curr_weight, curr_node) = pq.top(); pq.pop();        
        
        if (visited[curr_node]) {
            continue;
        }
 
        for (auto &adj : adjList[curr_node]) {
            ll newWeight = curr_weight+adj.first;
            if (newWeight < distance_from_start[adj.second]) {
                distance_from_start[adj.second] = newWeight;
                pq.push({newWeight, adj.second});
            }
        }
        visited[curr_node] = true;
    }
 
 
    for (auto &a : distance_from_start) {
        cout << a << ' ';
    }
}
