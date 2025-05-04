#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <array>
#include <set>
#include <bitset>
#include <list>
#include <iterator>
#include <regex>
#define ll long long
#define ld long double
#define pb push_back
#define endl '\n'
#define ull unsigned long long
#define ui unsigned int
#define MP make_pair
#define PI 3.1415926535
#define minimum LLONG_MIN
#define maximum LLONG_MAX
#define vii vector < int >
#define vll vector < ll >
#define all(n) n.begin() , n.end()
#define bc back()
#define F first
#define S second
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mx 0x3f3f3f3f3f3f3f3f
using namespace std;
 
//Bismillah
 
const int N = 100005;
const int mod = 1e9 + 7;
const int INF = 1e18;
 
 
ll dis[505][505];
 
signed main() {
    fast;
    ll n , m , q; cin >> n >> m >> q;
    memset(dis , 63 , sizeof(dis));
    while(m--)
    {
        ll u , v , w;
        cin >> u >> v >> w;
        dis[u][v] = min(dis[u][v] , w);
        dis[v][u] = min(dis[v][u] , w);
    }
    for(ll i = 1; i <= n; i++)
    {
        dis[i][i] = 0;
    }
    for(ll k = 1; k <= n; k++)
    {
        for(ll i = 1; i <= n; i++)
        {
            for(ll j = 1; j <= n; j++)
            {
                dis[i][j] = min(dis[i][j] , dis[i][k] + dis[k][j]);
            }
        }
    }
    while(q--)
    {
        ll s , f;
        cin >> s >> f;
        if(dis[s][f] == mx) cout << -1 << endl;
        else cout << dis[s][f] << endl;
    }
}
