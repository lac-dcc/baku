// ios_base::sync_with_stdio(false);
// cin.tie(nullptr);
// cout.tie(nullptr);
#include <valarray>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <cmath>
#include <map>
#include <stdio.h>
#include <string.h>
#define MAXN 1000000
using namespace std;
 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    set <pair<int, int>> s;
    for (int q = 0; q < n; ++q) {
        int x;
        cin >> x;
        s.insert({x, q});
    }
    for (int w = 0; w < m; ++w) {
        int x;
        cin >> x;
        auto k = s.upper_bound({x, n});
        if (k == s.begin()) {
            cout << -1 << endl;
        }
        else {
            --k;
            cout << (*k).first << endl;
            s.erase(k);
        }
    }
}
