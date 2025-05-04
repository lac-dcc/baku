#include<bits/stdc++.h>
using namespace std;
 
long long n, dp[200005];
 
struct elem
{
    long long start, finall, cost;
}v[200005];
 
inline bool cmp(const elem a, const elem b)
{
    if (a.finall == b.finall) {
        if (a.start == b.start)
            return a.cost > b.cost;
        return a.start < b.start;
    }
 
    return a.finall < b.finall;
}
 
int main()
{
    cin >> n;
    for (long long i = 1; i <= n; i++) {
        cin >> v[i].start >> v[i].finall >> v[i].cost;
    }
 
    sort(v + 1, v + n + 1, cmp);
    for (long long i = 1; i <= n; i++) {
        long long st = 1, dr = i - 1, poz = 0;
        while (st <= dr) {
            long long mijl = (st + dr) / 2;
            if (v[i].start > v[mijl].finall) {
                st = mijl + 1;
                poz = mijl;
            } else {
                dr = mijl - 1;
            }
        }
 
        dp[i] = max(dp[i - 1], dp[poz] + v[i].cost);
    }
 
    cout << dp[n];
    return 0;
}