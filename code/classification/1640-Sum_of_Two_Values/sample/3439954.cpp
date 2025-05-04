#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vector<pair<int, int> > a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    int p = 0;
    int q = n - 1;
    while (q > p) {
        if (a[p].first + a[q].first > x) {
            q--;
        } else if (a[p].first + a[q].first < x) {
            p++;
        } else {
            break;
        }
    }
    if (p != q && a[p].first + a[q].first == x) {
        cout << a[p].second << " " << a[q].second;
    } else {
        cout << "IMPOSSIBLE";
    }
    return 0;
}