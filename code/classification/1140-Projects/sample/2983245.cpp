#include <bits/stdc++.h>
 
using namespace std;
 
using pii = pair<int, int>;
using i64 = long long;
const i64 MOD = 1e9 + 7;
 
int main() {
    int n;
    cin >> n;
 
    vector<int> start(n), end(n), reward(n);
    map<int, int> lookup;
    for (int i = 0; i < n; ++i) {
        int x, y, r;
        cin >> x >> y >> r;
        start[i] = x;
        end[i] = y;
        reward[i] = r;
 
        // add start[i], end[i] to a lookup map
        lookup[start[i]];
        lookup[end[i]];
    }
 
    int cmax = 0;
    for (auto &e : lookup) {
        e.second = ++cmax;
    }
 
    // create new list based on the compressed values
    vector<vector<pii>> intervals (cmax+1);
    for (int i = 0; i < n; ++i) {
        intervals[lookup[end[i]]].push_back({lookup[start[i]], reward[i]});
    }
 
    // check all intervals ending at j
    // let's say one such interval is (i, j)
    // dp[j] = max(dp[j-1], dp[i-1] + reward[i,j]);
    vector<i64> best(cmax+1, 0);
    for (int j=1; j<=cmax; ++j) {
        best[j] = best[j-1];
        for (auto interval: intervals[j]) {
            int i = interval.first;
            int r = interval.second;
 
            best[j] = max(best[j], best[i-1] + r);
        }
    }
 
    cout << best[cmax] << '\n';
}