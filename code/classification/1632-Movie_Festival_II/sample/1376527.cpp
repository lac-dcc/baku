#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
 
typedef long long ll;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> intervals;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        intervals.push_back({a, b});
    }
    sort(intervals.begin(), intervals.end(), [](auto& i1, auto& i2) {
        return i1.second < i2.second;
    });
    multiset<int> ends;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (ends.size() < k) {
            auto it = ends.upper_bound(intervals[i].first);
            if (it == ends.begin()) {
                ends.insert(intervals[i].second);
            }
            else {
                --it;
                ends.erase(it);
                ends.insert(intervals[i].second);
            }
            ans++;
        }
        else {
            auto it = ends.upper_bound(intervals[i].first);
            if (it != ends.begin()) {
                --it;
                ends.erase(it);
                ends.insert(intervals[i].second);
                ans++;
            }
        }
    }
    cout << ans << "\n";
}