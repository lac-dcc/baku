#include <bits/stdc++.h>
#define ll long long
#define ii pair <int, int>
#define ill pair <int, ll>
#define llll pair <ll, ll>
#define ld long double
#define el "\n"
#define sp " "
#define modulo (ll)(1e9 + 7)
#define fi first
#define se second
using namespace std;
//const ld y1
 
ll n, m, x, y, to_node[2 * 100005], max_length[2 * 100005], ans;
bool v[2 * 100005];
vector <ll> a[2 * 100005];
 
void DFS(ll node)
{
    ll temp = 0;
    v[node] = true;
    for (ll i : a[node])
    {
        if (!v[i])
        {
            DFS(i);
            if (to_node[i] + 1 > to_node[node])
            {
                if (to_node[node] > temp) temp = to_node[node];
                to_node[node] = to_node[i] + 1;
            }
            else if (to_node[i] + 1 > temp) temp = to_node[i] + 1;
        }
    }
    ans = max(ans, temp + to_node[node]);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("Tree Diameter.inp", "r", stdin);
    //freopen("Tree Diameter.out", "w", stdout);
    cin >> n;
    ans = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!v[i]) DFS(i);
    }
    cout << ans;
    return 0;
}
 
//author: icyalmond
