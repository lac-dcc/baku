/// TỪNG TƯNG TỨNG TỪNG TƯNG CĂNG CĂNG CẮNG CẲNG , NGÀY HÔM ẤY EM BUÔNG TAY ANH VÌ LÍ DO GÌ , RỒI NHỨNG NGÀY QUA ANH PHẢI SỐNG TRONG NỖI CÔ ĐƠN.......
 
#include<bits/stdc++.h>
#define ll long long
#define se second
#define fi first
#define VCL "main"
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 
const ll N = 505, MOD = 1e9 + 7, INF = 1e18 + 1;
 
ll m , n , q, f[N][N];
 
void floyd()
{
    for(int i = 1;i <= n; ++i)
        f[i][i] = 0;
 
    for(int i = 1;i <= n; i++)
        for(int j = 1;j <= n; j++)
            for(int k = 1;k <= n ; k++)
                f[j][k] = min(f[j][k] , f[j][i] + f[i][k]);
}
 
void process()
{
    cin >> n >> m >> q;
 
    for(int i= 1;i <= n; i++)
        for(int j = 1;j <= n; j++)
            f[i][j] = INF;
 
    for(int i=1 ;i <= m; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        f[x][y] = min(f[y][x], z);
        f[y][x] = min(f[x][y] , z);
    }
 
    floyd();
 
    for(int i = 1;i <= q; i++)
    {
        int x , y;
        cin >> x >> y;
        if(f[x][y] == INF)
            cout << -1 << endl;
        else cout << f[x][y] << endl;
    }
}
 
int32_t main()
{
    //fastIO;
  //  freopen(VCL".inp" , "r" ,stdin);
   // freopen(VCL ".out" , "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--)
        process();
}
