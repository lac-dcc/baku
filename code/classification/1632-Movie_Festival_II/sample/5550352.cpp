#include <bits/stdc++.h>
 
using namespace std;
 
const int N= 2e5 + 5;
int n,k;
pair<int, int> a[N];
 
static bool cmp(pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second;
}
 
signed main() {
    cin.tie(0)->sync_with_stdio(0);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
    cin >> n >> k;
    multiset<int> t;
    for(int i = 0; i < n; i++) cin >> a[i].second >> a[i].first;
    sort(a, a + n);
    //for (int i = 0; i < n; i++) cout << a[i].first << " " << a[i].second << '\n';
    for (int i = 0; i < k; i++) t.insert(0);
    // auto it = t.upper_bound(1);
    // cout<< *it << '\n';
    int cnt =0;
    for (int i = 0; i <n; i++) {
        auto it = t.upper_bound(a[i].second);
        //cout << "at " << a[i].second << " found " << *it << '\n';
        if (it == begin(t)) {// equal beginning of SET 
            //cout <<"this" << '\n';
            continue;
        }
        cnt++;
        t.erase(--it);
        t.insert(a[i].first);
    }
    cout << cnt << '\n';
}
