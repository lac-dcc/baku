#include <bits/stdc++.h>
#define ll long long
using namespace std;
int mod = 1e9 + 7;
 
ll arr[501][501];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, m, q;
    cin >> n >> m >> q;
 
    memset(arr, 0x3f, sizeof(arr));
 
    for (ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        arr[a][b] = min(arr[a][b], c);
        arr[b][a] = min(arr[a][b], c);
    }
 
    for (ll i = 0; i < n; i++)
    {
        arr[i][i] = 0;
    }
 
    for (ll k = 0; k < n; k++)
    {
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++)
            {
 
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }
 
    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        cout << (arr[a][b] >= 1e18 ? -1 : arr[a][b]) << endl;
    }
}
