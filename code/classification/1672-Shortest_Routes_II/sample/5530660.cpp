//Floyd-Warshall Algorithm
#include<iostream>
using namespace std;
#define N 505
#define ll long long
#define INF (ll)(1e12+5)
ll dis[N][N];
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i == j)
                dis[i][j] = 0;
            else
                dis[i][j] = INF;
        }
    }
    for(int i=0; i<m; i++){
        int a, b;
        ll val;
        cin >> a >> b >> val;
        dis[a][b] = min(dis[a][b], val);
        dis[b][a] = min(dis[b][a], val);
    }
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        }
    }
    while(q--){
        int a, b;
        cin >> a >> b;
        if(dis[a][b] == INF)
            cout << "-1\n";
        else
            cout << dis[a][b] << "\n";
    }
    return 0;
}
