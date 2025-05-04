#include <bits/stdc++.h>
 
#define sz(a) (int)a.size()
 
typedef long long ll;
 
using namespace std;
 
void solve() {
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
 
    sort(a.begin(), a.end());
 
    int i = 0, j = n - 1;
    while (i < j) {
        if (a[i].first + a[j].first == x) {
            cout << a[i].second << ' ' << a[j].second << '\n';
            return;
        }
        if (a[i].first + a[j].first > x) {
            j--;
        } else {
            i++;
        }
    }
 
    cout << "IMPOSSIBLE\n";
}
 
int main() {
#ifdef LOCAL
    freopen("../in.txt", "r", stdin);
    freopen("../out.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
 
    solve();
 
    return 0;
}
