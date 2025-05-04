#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define MOD 64735492
#define pb push_back
#define f first
#define s second
#define ffor(i, a, b) for (int i = a; i < b; i++)
#define fmfor(i, a, b) for (int i = a; i <= b; i++)
#define clr(arr, val) memset(arr, val, sizeof(arr))
 
ll expo(ll x, ll y)
{
    ll res = 1;
    while (y)
    {
        if (y & 1)
            res = res * x;
        res %= MOD;
        y = y >> 1;
        x = x * x;
        x %= MOD;
    }
    return res;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll INF = 1e16;
    ll n,m,q;
    cin>>n>>m>>q;
    vector<pair<ll,ll>>v[n+5];
    vector<vector<ll>>d(n+5,vector<ll>(n+5,INF));
    for(int i=0;i<m;i++) {
        ll x,y,c;
        cin>>x>>y>>c;
        v[x].pb({c,y});
        d[x][y] = min(d[x][y],c);
        d[y][x] = min(d[y][x],c);
    }
    for(int i=1;i<=n;i++) {
        d[i][i] = 0;
    }
    for(int k=1;k<=n;k++) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(d[i][k]<INF && d[k][j]<INF) {
                    d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
                }
            }
        }
    }
    while(q--) {
        ll a,b;
        cin>>a>>b;
        if(d[a][b]==INF) cout<<-1<<endl;
        else cout<<d[a][b]<<endl;
    }
}
