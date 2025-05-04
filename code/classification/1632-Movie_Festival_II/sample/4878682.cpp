#include <bits/stdc++.h>
using namespace std;
 
vector<pair<int, int>> v;
bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), cmp);
 
    multiset<int> s;
    int ans = 1;
    s.insert(v[0].second);
    for (int i = 1; i < n; ++i) {
        auto it = s.lower_bound(v[i].first + 1);
        if (it == s.begin()) {
            if (s.size() >= k) continue;
            else s.insert(v[i].second), ans++;
        }
        else {
            it = prev(it);
            s.erase(it);
            s.insert(v[i].second);
            ans++;
        }
    }
    printf("%d\n", ans);
 
    return 0;
}
