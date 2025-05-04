#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <assert.h>
#include <iomanip>
#include <cmath>
#include <unordered_set>
#include <time.h>
#include <random>
#include <stack>
 
using namespace std;
using ll = long long;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll n, m, x;
    set<pair<ll, ll>> h;
    cin >> n >> m;
    vector<ll> t(m);
    for (ll i = 0; i < n; ++i) {
        cin >> x;
        h.insert({ x, i });
    }
    for (ll i = 0; i < m; ++i) cin >> t[i];
    for (ll i = 0; i < m; ++i) {
        auto it = h.lower_bound({ t[i] + 1, 0 });
        if (it == h.begin()) cout << -1 << '\n';
        else {
            it--;
            cout << (*it).first << '\n';
            h.erase(it);
        }
    }
    return 0;
}
