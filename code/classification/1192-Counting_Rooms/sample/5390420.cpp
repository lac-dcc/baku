#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define oo 1e9+7
#define FOR(i, a, b) for (int i = a; i<=b; i++)
#define el cout<<'\n'
#define FOD(i, a, b) for (int i = a; i>=b; i--)
#define N 100005
#define name "cses1192"
using namespace std;
 
int n,m,cnt = 0;
int dx[] = {1, -1, 0 ,0};
int dy[] = {0, 0, -1, 1};
bool ok[1005][1005];
int d[1005][1005];
 
void dfs(int u, int v){
    d[u][v] = 1;
    FOR(i,0,3){
        int U = u + dx[i];
        int V = v + dy[i];
        if (!d[U][V] && U > 0 && V > 0 && U <= n && V <= m && ok[U][V]){
            dfs(U,V);
        }
    }
}
 
int main()
{
  //  freopen(name".inp","r",stdin); freopen(name".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    FOR(i,1,n)
    FOR(j,1,m){
        char x;
        cin>>x;
        if (x == '.') ok[i][j] = true;
        else ok[i][j] = false;
    }
    FOR(i,1,n)
    FOR(j,1,m){
        if (d[i][j] == 0 && ok[i][j] == true){
            dfs(i,j);
            cnt++;
        }
    }
    cout<<cnt;
 
    return 0;
}
