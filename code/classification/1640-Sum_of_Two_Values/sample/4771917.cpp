#include <bits/stdc++.h>
using namespace std;
 
pair<int, int> a[200005];
int n, s, l, r, mid;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i+1;
    }
    sort(a, a+n);
    for (int i = 0; i < n-1; ++i) {
        l = i+1; r = n-1; mid = (l+r)/2;
        while (l <= r) {
            if (a[i].first+a[mid].first == s) {
                cout << a[i].second << ' ' << a[mid].second;
                return 0;
            }
            if (a[i].first+a[mid].first > s) r = mid-1;
            else l = mid+1;
            mid = (l+r)/2;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}