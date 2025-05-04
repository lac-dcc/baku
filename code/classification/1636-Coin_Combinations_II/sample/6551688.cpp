#include <bits/stdc++.h>
// #include "helper.hpp"
 
using namespace std;
#define ll long long
 
#ifndef CONSTANTS
#define CONSTANTS
const double PI = acos(-1.0);
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
#endif
void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> combinations(x + 1, 0);
    combinations[0] = 1;
    for (int i{}; i < n; ++i) {
        int c;
        cin >> c;
        for (int j{c}; j <= x; ++j) {
            combinations[j] = (combinations[j] + combinations[j - c]) % MOD;
        }
        // print(combinations);
    }
    cout << combinations[x] % MOD << endl;
}
 
int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);
    solve();
    return 0;
}
