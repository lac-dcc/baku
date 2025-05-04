#include<bits/stdc++.h>
 
#define ull unsigned long long
#define ll long long
#define ar array
#define imei(...)   "[ "<< #__VA_ARGS__ <<" = "<< __VA_ARGS__ <<" ] "
 
using namespace std;
const int nax = 1e5+5;
int n, m;
vector<pair<int, int>> adj[nax];
ar<ll, 3> dp[nax];
 
int main(int argc, char *argv[])
{
    priority_queue<ar<ll, 3>, vector<ar<ll, 3>>, greater<ar<ll, 3>>> pq;
 
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a>> b>> c;
        adj[a].push_back({b, c});
    }
 
    dp[1][0] = dp[1][1] = 0;
    for (int i = 2; i < nax; i++)
        dp[i][0] = dp[i][1] = 1e18;
 
    pq.push({0, 1, 0}); // cost, dst, flag, flag = 1 ==> using coupon
    while (!pq.empty()) {
        auto [c, u, f] = pq.top();
        pq.pop();
        if (c > dp[u][f]) continue;
        dp[u][f] = c;
        for (auto [v, d]: adj[u]) {
            // not use coupon
            if (c+d < dp[v][f]) {
                dp[v][f] = c + d;
                pq.push({c+d, v, f});
            }
            // use coupon
            if (!f && c+d/2 < dp[v][1]) {
                dp[v][1] = c + d/2;
                pq.push({c+d/2, v, 1});
            }
        }
    }
 
    cout << dp[n][1]<<endl;
 
    return 0;
}
