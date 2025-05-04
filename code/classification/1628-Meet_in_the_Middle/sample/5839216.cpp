#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("bmi,bmi2,lzcnt,popcnt")
using namespace std;
using ll = long long;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<ll> a, b;
    for(int i = 0; i < n; i++) {
        ll k;
        cin >> k;
        if(i < (n/2)) {
            a.push_back(k);
        }
        else {
            b.push_back(k);
        }
    }
    vector<ll> a_subst, b_subst;
    int k1 = 0, k2 = 0;
    for(int i = 0; i < a.size(); i++) {
        k1 |= (1 << i);
    }
    for(int i = 0; i < b.size(); i++) {
        k2 |= (1 << i);
    }
    int k = 0;
    do {
        ll s = 0;
        for(int i = 0; i < a.size(); i++) {
            if(k & (1 << i)) {
                s += a[i];
            }
        }
        a_subst.push_back(s);
    }
    while(k=(k-k1)&k1);
    k = 0;
    do {
        ll s = 0;
        for(int i = 0; i < b.size(); i++) {
            if(k & (1 << i)) {
                s += b[i];
            }
        }
        b_subst.push_back(s);
    }
    while(k=(k-k2)&k2);
    k = 0;
    ll ans = 0;
    sort(a_subst.begin(), a_subst.end());
    for(auto it : b_subst) {
        auto it1 = lower_bound(a_subst.begin(), a_subst.end(), x-it);
        auto it2 = upper_bound(a_subst.begin(), a_subst.end(), x-it);
        ans += it2-it1;
    }
    cout << ans;
    return 0;
}
