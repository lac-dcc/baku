#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
ll recur(ll i, ll j, string &n, string &m, vector<vector<ll>> &dp)
{
    if (i >= n.size() || j >= m.size())
    {
        return max(n.size() - i, m.size() - j);
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    ll x = 0;
    if (n[i] == m[j])
    {
        x = recur(i + 1, j + 1, n, m, dp);
    }
    else
    {
        x = 1 + min(recur(i + 1, j, n, m, dp), min(recur(i, j + 1, n, m, dp), recur(i + 1, j + 1, n, m, dp)));
    }
    return dp[i][j] = x;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string n, m;
    cin >> n >> m;
    vector<vector<ll>> dp(n.size() + 1, vector<ll>(m.size() + 1, -1));
    cout << recur(0, 0, n, m, dp);
}