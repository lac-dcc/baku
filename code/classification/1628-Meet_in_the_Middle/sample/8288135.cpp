#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n; cin >> n;
    long long x; cin >> x;
    int k = n / 2;
    vector<long long> a(k), b(n - k);
    for (long long& c: a) cin >> c;
    for (long long& c: b) cin >> c;
 
    vector<long long> s1, s2;
    for (int i = 0; i < (1 << k); ++i) {
        long long sum = 0;
        for (int j = 0; j < k; ++j) {
            if (i & (1 << j)) {
                sum += a[j];
            }
        }
        s1.push_back(sum);
    }
 
    for (int i = 0; i < (1 << (n - k)); ++i) {
        long long sum = 0;
        for (int j = 0; j < n - k; ++j) {
            if (i & (1 << j)) {
                sum += b[j];
            }
        }
        s2.push_back(sum);
    }
 
    sort(s2.begin(), s2.end());
 
    long long ans = 0;
    for (int i = 0; i < s1.size(); ++i) {
        long long s = s1[i];
        auto fs = lower_bound(s2.begin(), s2.end(), x - s);
        auto sc = upper_bound(s2.begin(), s2.end(), x - s);
        ans += sc - fs;
    }
 
    cout << ans;
 
    return 0;
}
