#include <bits/stdc++.h>
 
const int N = 500 + 10;
const long long INF = 1e17;
#define ll long long
using namespace std;
int n;
ll cost[N][N], m, q;
 
int main() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)cost[i][j] = (i == j ? 0 : INF);
    }
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        cost[a][b] = min(cost[a][b], c);
        cost[b][a] = min(cost[b][a], c);
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (cost[i][k] != INF && cost[k][j] != INF) {
                    cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
                }
                if (cost[i][i] < 0) {
                    //i is part of a negative cycle
                    cout << "Negative Cycle";
                    return 0;
                }
            }
        }
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (cost[a][b] == INF)cout << -1 << '\n';
        else cout << cost[a][b] << '\n';
    }
    return 0;
}
 
 
