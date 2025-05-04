/*
\~~~~~~~~~~~~~~~~~\
 \    TOUFIK       \
  \        ISLAM    \
   \~~~~~~~~~~~~~~~~~\
*/
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define nl '\n'
#define Faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
 
const int md = 1000000007;
const int N = 1e6 + 5;
vector<int> comb(N, 0);
vector<int> coins;
 
void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0, x; i < n; i++)
    {
        cin >> x;
        coins.push_back(x);
    }
    comb[0] = 1;
 
    sort(coins.begin(), coins.end());
 
    for (int j = 0; j < coins.size(); j++)
    {
        for (int i = 1; i <= k; i++)
        {
            if (i - coins[j] >= 0)
                comb[i] += comb[i - coins[j]];
            comb[i] = comb[i] % md;
        }
    }
 
    // for (int i = 0; i <= k; i++)
    //     cout << comb[i] << ' ';
 
    cout << comb[k];
}
 
int main()
{
    Faster;
 
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
 
    return 0;
}