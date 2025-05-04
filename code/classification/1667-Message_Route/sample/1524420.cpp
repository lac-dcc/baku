#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define INF 999999999
typedef int ii;
typedef long long ll;
 
ll n, m, a, b, dist[110000], ant[110000];
vector<ll> edge[110000];
queue<ll> que;
 
void bfs(ll ini) {
    que.push(ini);
    dist[ini] = 0;
 
    while(!que.empty()) {
        ll act = que.front();
        que.pop();
 
        for(ll i = 0; i < edge[act].size(); i++) {
            if(dist[edge[act][i]] == -1) {
                que.push(edge[act][i]);
                dist[edge[act][i]] = dist[act] + 1;
                ant[edge[act][i]] = act;
            }
 
            if(edge[act][i] == 1)
                return;
        }
    }
}
 
int main() {
    cin >> n >> m;
 
    for(ll i = 0; i < m; i++) {
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
 
    memset(dist, -1, sizeof(dist));
 
    bfs(n);
 
    if(dist[1] == -1) {
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        cout << dist[1]+1 << endl;
 
        a = 1;
 
        cout << 1 << ' ';
        while(a != n) {
            cout << ant[a] << ' ';
 
            a = ant[a];
        }
    }
 
    return 0;
}
