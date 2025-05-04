#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
 
using namespace std;
 
const int NMAX = 1e5;
 
vector <pair <int, int>> g[NMAX + 1];
long long d[NMAX + 1];
priority_queue <pair <long long, int>, vector <pair <long long, int>>, greater <pair <long long, int>>> q;
bitset <NMAX + 1> seen;
 
void dijkstra(int x){
 
    q.push({0, 1});
    d[x] = 0;
 
    while(!q.empty()){
 
        pair <long long, int> x = q.top();
        q.pop();
 
        if(seen[x.second])
            continue;
 
        seen[x.second] = 1;
 
        for(auto e : g[x.second]){
 
            int vecin = e.first;
            int cost = e.second;
 
            if(d[vecin] > d[x.second] + cost){
 
                d[vecin] = d[x.second] + cost;
                q.push({d[vecin], vecin});
 
            }
 
        }
 
    }
 
}
 
int main(){
 
    ios :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int n = 0, m = 0;
    cin >> n >> m;
 
    for(int i = 1; i <= n; i++)
        d[i] = 2e18;
 
    int x = 0, y = 0, c = 0;
    for(int i = 0; i < m; i++){
 
        cin >> x >> y >> c;
        g[x].push_back({y, c});
 
    }
 
    dijkstra(1);
 
    for(int i = 1; i <= n; i++)
        cout << d[i] * (i != 1) << " ";
 
 
    return 0;
}
