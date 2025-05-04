#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
 
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> d(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> d[i].second >> d[i].first;
    }
    sort(begin(d), end(d));
    multiset<int> f;
    for (int i = 0 ; i < m ; i++) f.insert(0);
    int ans = 0;
    for (int i = 0 ; i < n ; i++) {
        auto it = f.upper_bound(d[i].second);
        if (it == f.begin()) continue;
        f.erase(--it);
        f.insert(d[i].first);
        ans++;
    }
    cout << ans;
    return 0;
}