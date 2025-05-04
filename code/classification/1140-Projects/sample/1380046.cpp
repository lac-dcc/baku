#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <string>
#include <algorithm>
#include <tuple>
#include <array>
#include <climits>
#include <cmath>
#include <iomanip>
 
using namespace std;
 
typedef long long ll;
 
const int MAXN = 2e5;
int n;
array<int, 3> a[MAXN];
 
int main() 
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i][1] >> a[i][0] >> a[i][2];
    }
 
    sort(a, a+n);
    set<array<ll, 2> > dp;
    dp.insert({0, 0});
 
    ll prev = 0;
    for (int i = 0; i < n; ++i) {
        auto it = dp.lower_bound({a[i][1]});
        --it;
        prev = max(prev, (*it)[1] + a[i][2]);
        dp.insert({a[i][0], prev});
    }
 
    cout << prev;
    return 0;
}
