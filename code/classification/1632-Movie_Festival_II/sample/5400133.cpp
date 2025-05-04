#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define modulo 1000000007
#define ln '\n'
 
bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
    return p1.second < p2.second;
}
 
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int k, n, ans = 0; cin >> n >> k;
    vector<pair<int, int>> arr(n);
    for (auto &e: arr) cin >> e.first >> e.second;
    sort(arr.begin(), arr.end(), cmp);
    multiset<int, greater<int>> set;
    for (auto &e: arr) {
        auto it = set.lower_bound(e.first);
        if (it != set.end()) {
            set.erase(it);
            set.insert(e.second);
            ans++;
        }
        else if (set.size() < k) {
            set.insert(e.second);
            ans++;
        }
    }
    cout << ans;
    return 0;
}