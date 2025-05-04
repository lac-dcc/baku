// -
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <cmath>
#include <iterator>
#include <set>
#include <map>
#include <math.h>
#include <iomanip>
#include <unordered_set>
#include <queue>
#include <climits>
using namespace std;
// clang++ -std=c++17 cses1643.cpp && ./a.out
 
using ll = long long;
 
void solve(){
    int n;
    cin >> n;
 
    ll curr_sum = 0, min_pref = 0, ans = -LLONG_MAX;
 
    for (int i = 0; i < n; i++){
        int e;
        cin >> e;
        curr_sum += e;
 
        ans = max(ans, curr_sum - min_pref);
        min_pref = min(min_pref, curr_sum);
    }
 
    cout << ans;
    cout << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    // freopen("input.txt", "r", stdin);
    solve();
 
    return 0;
}