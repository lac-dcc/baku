#include<iostream>
#include<vector>
using namespace std;
 
 
 
 
 
int main(){
    long long a, b, c, q;
    int n, m;
    
 
 
    cin >> n >> m >> q;
    long long INF = 500000000000;
    vector <vector<long long> >adj(n+1, vector<long long>(n+1,-1));
    vector <vector<long long> >dist(n+1, vector<long long>(n+1, INF));
 
    for (int i = 0; i < m; i++){
        cin >> a >> b >> c;
        if (adj[a][b] == -1 || adj[a][b] > c){
            adj[a][b] = c;
            adj[b][a] = c;
        }
    }
 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
           if (i == j) dist[i][j] = 0;
           else if (adj[i][j] > -1) dist[i][j] = adj[i][j];
           else dist[i][j] = INF;
        }
    }
 
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            } 
        }
    }
 
    for (int i=0; i < q; i++){
        cin >> a >> b;
        if (dist[a][b] < INF){
            cout << dist[a][b] << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
 
 
 
}
