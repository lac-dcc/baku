#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    long long n, m;
    cin >> n >> m;
    vector<vector<pair<long long,long long>>> a(n+1, vector<pair<long long,long long>>());
    for (long long i = 0; i < m; i++)
    {
        long long x,y,z;
        cin >> x >> y >> z;
        a[x].push_back({y,z});
    }
    priority_queue<array<long long,3>, vector<array<long long,3>>, greater<array<long long,3>>> pq;
    vector<vector<long long>> dp (2, vector<long long>(n+1, LLONG_MAX));
    pq.push({0,1,true});
    while (!pq.empty())
    {
        long long dist = pq.top()[0];
        long long cur = pq.top()[1];
        bool coupon = pq.top()[2];
        pq.pop();
 
        if (dp[!coupon][cur] < dist) continue;
 
        for (auto it : a[cur])
        {
            long long dest = it.first;
            long long weight = it.second;
            
            //dont use the coupon
            if (coupon && dp[0][dest] > weight + dist)
            {
                dp[0][dest] = weight + dist;
                pq.push({weight + dist, dest, 1});
            }
            //use the coupon
            if (coupon && dp[1][dest] > weight/2 + dist)
            {
                dp[1][dest] = weight/2 + dist;
                pq.push({weight/2 + dist, dest, 0});
            }
            //used the coupon already
            if (!coupon && dp[1][dest] > weight + dist)
            {
                dp[1][dest] = weight + dist;
                pq.push({weight + dist, dest, 0});
            }
        }
    }
    cout << dp[1][n] << endl;
}
