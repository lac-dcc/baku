#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define ll long long
 
using namespace std;
 
 
void solve() {
    long long n;
    int k;
    cin >> n >> k;
    vector<ll> v;
    for (int i = 0; i < k; i++) {
        ll a;
        cin >> a;
        v.push_back(a);
    }
 
    map<int, vector<ll>> mp;
 
 
    for (int i = 0; i < k; i++) {
        map<int, vector<ll>> mpp;
        for (auto &cur: mp) {
            for (ll x: cur.second) {
                if (n * 1.0 / v[i] + 1.0 >= x * 1.0) {
//                    cout << (n * 1.0 / v[i] + 1.0) << " " << x * 1.0 << " " << v[i] << " " << x << " " << v[i] * x
//                         << endl;
                    mpp[cur.first + 1].push_back(v[i] * x);
                }
            }
        }
        mpp[1] = {v[i]};
 
        for (auto &cur: mpp) {
            mp[cur.first].insert(mp[cur.first].end(), mpp[cur.first].begin(), mpp[cur.first].end());
        }
    }
    ll ans = 0;
    for (auto x: mp) {
        if (x.first % 2)
            for (auto i: x.second)
                ans += n / i;
        else
            for (auto i: x.second)
                ans -= n / i;
//       cout<<x.first<<": ";
//       for(auto i:x.second)
//           cout<<i<<" ";
//       cout<<endl;
    }
    cout << ans;
}
 
int main() {
    int t = 1;
    //  cin >> t;
    for (; t--;)
        solve();
    return 0;
}