#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ull unsigned long long
#define MOD 998244353 // 1000000007
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
#define printall(a)       \
    for (auto &(i) : (a)) \
        cout << i << ' '; \
    cout << endl;
#define print(a) cout << a << endl;
#define rsort(a) sort((a).rbegin(), (a).rend())
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define pqmx priority_queue<int>
#define pqmn priority_queue<int, vector<int>, greater<int>>
#define mx_all(c) *max_element((c).begin(), (c).end())
#define mn_all(c) *min_element((c).begin(), (c).end())
#define lwr_b(c, a) lower_bound((c).begin(), (c).end(), (a)) - ((c).begin())
#define upr_b(c, a) upper_bound((c).begin(), (c).end(), (a)) - ((c).begin())
#define FIO                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
 
void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    ll local = 0, global = LONG_MIN;
    for (int i = 0; i < n; i++)
    {
        local += v[i];
        global = max(global, local);
        if (local < 0)
            local = 0;
    }
    cout << global;
}
 
int32_t main()
{
    FIO;
    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
        cout << endl;
    }
    return 0;
}
