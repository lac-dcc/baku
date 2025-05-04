#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vpi;
typedef map<int, int> mp;
typedef set<int> se;
typedef pair<int, int> pr;
#define bug(a) cout << #a << " : " << a << endl;
#define INF INT_MAX
#define pb push_back
#define ppb pop_back
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define all(x) x.begin(), x.end()
#define ceiling(a, b) ((a / b) + (a % b != 0))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a * b) / gcd(a, b))
 
int MOD = 1e9 + 7;
 
int minCoins(vi coins, int m, int V)
{
    int table[V + 1];
    table[0] = 0;
 
    for (int i = 1; i <= V; i++)
        table[i] = INF;
 
    for (int i = 1; i <= V; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (coins[j] <= i)
            {
                int sub_res = table[i - coins[j]];
                if (sub_res != INF && sub_res + 1 < table[i])
                    table[i] = sub_res + 1;
            }
        }
    }
 
    if (table[V] == INF)
        return -1;
    return table[V];
}
 
void solve(int cs)
{
    int m, V;
    vi coins;
    cin >> m >> V;
    for (int i = 0; i < m; i++)
    {
        int n;
        cin >> n;
        coins.pb(n);
    }
    cout << minCoins(coins, m, V) << endl;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int tc = 1;
    // cin >> tc;
    for (int cs = 1; cs <= tc; cs++)
    {
        solve(cs);
    }
    return 0;
}
