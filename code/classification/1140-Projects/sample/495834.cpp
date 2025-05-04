#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
struct interval {
    ll l, r, p;
    interval(ll l, ll r, ll p)
        : l(l), r(r), p(p) {}
    bool operator<(const interval& i) const {
        return tie(r, l) < tie(i.r, i.l);
    }
};
 
 
int main(int argc, char *argv[])
{
    int N;
    cin >> N;
    vector<interval> intervals;
    for (int i = 0; i < N; i++) {
        int l, r, p;
        cin >> l >> r >> p;
        intervals.emplace_back(l, r, p);
    }
    sort(begin(intervals), end(intervals));
    vector<ll> dp(N);
    dp[0] = intervals[0].p;
    for (int i = 1; i < N; i++) {
        auto [l, r, p] = intervals[i];
        int index = lower_bound(begin(intervals), end(intervals), interval(0, l, 0)) - begin(intervals) - 1;
        ll m = dp[i - 1];
        if (index >= 0) {
            m = max(m, dp[index] + p);
        } else {
            m = max(m, p);
        }
        dp[i] = m;
    }
    cout << dp[N - 1] << '\n';
    return 0;
}
