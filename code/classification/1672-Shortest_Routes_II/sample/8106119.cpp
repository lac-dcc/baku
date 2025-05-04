#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 500 + 10;
const int infinito = 1e14 + 10;
int adj[maxn][maxn];
signed main(){
    int n,m,q;
    cin >> n >> m >> q;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            adj[i][j] = infinito;
            if(i == j) adj[i][j] = 0;
        }
    }
    int a,b,c;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        adj[a][b] = min(adj[a][b],c);
        adj[b][a] = adj[a][b];
    }
    for(int k = 1; k <= n; k++){
        for(int j = 1; j <= n; j++){
            for(int i = 1; i <= n; i++){
                adj[i][j] = min(adj[i][j],adj[i][k] + adj[k][j]);
                adj[j][i] = adj[i][j];
            }
        }
    }
    vector<int> resul;
    for(int i = 0; i < q; i++){
        cin >> a >> b;
        if(adj[a][b] >= infinito) resul.push_back(-1);
        else resul.push_back(adj[a][b]);
    }
    for(int i : resul) cout << i << endl;
    return 0;
}
