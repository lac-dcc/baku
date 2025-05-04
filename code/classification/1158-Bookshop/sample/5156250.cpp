// When life gives you lemon you make lemonade
#include <bits/stdc++.h>
#define nl '\n'
#define ll int
#define fi(n, a)               \
    for (ll i = 0; i < n; ++i) \
        cin >> a[i];
#define ps(a)        \
    for (auto e : a) \
        cout << e << ' ';
using namespace std;
 
ll n, p;
 
int32_t main()
{
    iostream::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> p;
    vector<ll> price(n), pages(n);
    fi(n, price);
    fi(n, pages);
 
    // try out all the combinations
    // greedy may or may not give a good solution
    // memo causes TLE
    // try using bottom up
    vector<vector<ll>> dp(n + 1, vector<ll>(p + 1, 0));
    for (ll i = 1; i <= n; ++i)
    {
        for (ll w = 0; w <= p; ++w)
        {
            // idea is to fill the table rowwise
            // considering the capacity to be w rn
            // then we evaluate new solution after sometime
            ll curr_best = dp[i - 1][w];
            if (price[i - 1] <= w)
                curr_best = max(curr_best, pages[i - 1] + dp[i - 1][w - price[i - 1]]);
            dp[i][w] = curr_best;
        }
    }
    cout << dp[n][p] << nl;
}
