#include <bits/stdc++.h>
using namespace std;
 
int n, m, q, a, b;
long long c, dis[505][505];
 
int main() {
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            dis[i][j] = LLONG_MAX;
        }
        // distance: i to i is zero
        dis[i][i] = 0;
    }
 
    for (int i = 0; i < m; i++){
        cin >> a >> b >> c;
        // Bad Sample
        // There are mutiple edges between two nodes
        // 2 2 1
        // 1 2 1
        // 1 2 2
        // 1 2
        //
        //       FK........
        //         1
        //       1--->2
        //         2
        dis[b][a] = dis[a][b] = min(dis[a][b], c);
    }
 
    // Folyd-WarShall
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            if (i == k) continue;
            for (int j = i+1; j <= n; j++){
                if (j == k) continue;
                // To prevent LONG LONG overflow
                if (dis[i][j] - dis[i][k] > dis[k][j]){
                    dis[i][j] = dis[i][k] + dis[k][j];
                    dis[j][i] = dis[i][j];
                }
            }
        }
    }
    for (int i = 0; i < q; i++){
        cin >> a >> b;
        if (dis[a][b] == LLONG_MAX) cout << -1 << "\n";
        else cout << dis[a][b] << "\n";
    }
}
