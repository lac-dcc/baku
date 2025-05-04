#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll x, n, i, t, l, r;
vector<pair<ll, ll>> a;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> x;
    for (i = 0; i < n; i++) {
        cin >> t;
        a.push_back({t, i + 1});
    }
    sort(a.begin(), a.end());
    //for (i = 0; i < n; i++)
    //    cout << a[i].first << endl;
    l = 0; r = n-1;
    while (l < r) {
        if (a[l].first + a[r].first > x)
            r--;
        else if (a[l].first + a[r].first < x)
            l++;
        else {
            cout << a[r].second << " " << a[l].second;
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
}