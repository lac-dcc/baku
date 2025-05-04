#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    vector<int> b(m);
    int ans=0;
    for (int i=0; i<n; ++i) {
        cin >> a[i];
    }
    for (int i=0; i<m; ++i) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i=0;
    int j=0;
    while (i<n && j<m) {
        if (abs(a[i]-b[j])<=k) {
            ++i;
            ++j;
            ++ans;
        }
        else {
            if (a[i]>b[j]) {
                ++j;
            }
            else {
                ++i;
            }
        }
    }
    cout << ans;
}