#include <bits/stdc++.h>
#define ll long long
#define _ ' '
using namespace std;
 
const int maxn = 1001;
ll t[maxn][maxn] , check[maxn][maxn];
ll n , m;
 
void dfs(ll x , ll y)
{
    check[x][y] = 1;
//    cout << x << _ << y << "\n";
    ll a = x; ll b = y;
    if ((a - 1 > 0) && (check[a - 1][b] == 0) && (t[a - 1][b] == 1)) dfs(a - 1 , b);
    if ((a + 1 <= n) && (check[a + 1][b] == 0) && (t[a + 1][b] == 1)) dfs(a + 1 , b);
    if ((b - 1 > 0) && (check[a][b - 1] == 0) && (t[a][b - 1] == 1)) dfs(a , b - 1);
    if ((b + 1 <= m) && (check[a][b + 1] == 0) && (t[a][b + 1] == 1)) dfs(a , b + 1);
}
 
int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    ll c = 0;
    for (ll i = 1 ; i <= n ; i++)
    {
        for (ll j = 1 ; j <= m ; j++)
        {
            char s; cin >> s;
            if (s == '#') t[i][j] = 0;
            else t[i][j] = 1;
        }
    }
    for (ll i = 1 ; i <= n ; i++)
    {
        for (ll j = 1 ; j <= m ; j++)
        {
            if ((t[i][j] == 1) && (check[i][j] == 0))
            {
                c++;
                dfs(i , j);
            }
        }
    }
//    for (ll i = 1 ; i <= n ; i++)
//    {
//        for (ll j = 1 ; j <= m ; j++)
//        {
//            cout << check[i][j] << _;
//        }
//        cout << "\n";
//    }
    cout << c;
    return 0;
}
