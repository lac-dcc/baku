#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main() {
    ll n,x;
    cin >> n >> x;
    vector<int> a1(n/2);
    vector<int> a2(n-n/2);
    for (int i=0; i<n; ++i) {
        if (i>=n/2) {
            cin >> a2[i-n/2];
        }
        else {
            cin >> a1[i];
        }
    }
    vector<ll> m1,m2;
    for (int i=0; i<(1<<(n/2)); ++i) {
        ll sum = 0;
        for (int j=0; j<(n/2); ++j) {
            if ( ((1<<(j)) & i) ) {
                sum += a1[j];
            }
        }
        m1.push_back(sum);
    }
    for (int i=0; i<(1<<(n-(n/2))); ++i) {
        ll sum = 0;
        for (int j=0; j<(n-(n/2)); ++j) {
            if ( ((1<<(j)) & i) ) {
                sum += a2[j];
            }
        }
        m2.push_back(sum);
    }
    ll ans = 0;
    sort(m1.begin(), m1.end());
    sort(m2.begin(),m2.end());
    int p1 = 0, p2 = 0;
    for (auto& n1: m1) {
        auto least = lower_bound(m2.begin(),m2.end(),x-n1);
        auto upone = upper_bound(m2.begin(),m2.end(),x-n1);
        ans += (upone-m2.begin()) - (least - m2.begin());
    }
    cout << ans;
}
 
/*
4 5
1 2 3 2
*/
