#include <bits/stdc++.h>
#include <iostream>
using namespace std;
 
typedef long long ll;
const int mxN = 5001;
 
const int mod = 1e9+7;
 
ll dp[mxN][mxN];
bool done[mxN][mxN];
 
int solve(string &s, string &t, int i, int j)
{
    if(i == 0) return j;
    if(j == 0) return i;
    if(done[i][j]) return dp[i][j];
    done[i][j] = true;
    if(s[i - 1] == t[j - 1])
    {
        return dp[i][j] = solve(s, t, i - 1, j - 1);
    }
    /// promeni poslednji u poslednji, i - 1, j - 1
    /// obrisi poslednji i probaj -1,
    /// prebaci u posednji -1 i dodaj
    int ans = 1e9;
    ans = min(ans, solve(s, t, i - 1, j - 1) + 1); /// i
    ans = min(ans, solve(s, t, i - 1, j) + 1); /// o
    ans = min(ans, solve(s, t, i, j - 1) + 1); /// d
    return dp[i][j] = ans;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s, t; cin >> s >> t;
    cout << solve(s, t, s.size(), t.size());
}