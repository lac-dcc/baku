#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <functional>
#include <utility>
#include <tuple>
#include <numeric>
#include <queue>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <regex>
#include <stack>
#include <limits>
#include <climits>
 
using namespace std;
 
void solve() {
    long long n;
    cin >> n;
    const int M = 1e9+7;
    long long res = 0;
    for (int i = 1; i <= min(n, 1000000ll); ++i) {
        res = (res + n / i * i) % M;
    }
    long long cur = n;
    for (int i = 1; cur > 1000000ll; i++) {
        long long next = max(n / (i+1), 1000000ll);
        long long len = cur - next;
        long long sum = cur + next + 1;
        if (len % 2 == 0) len /= 2; else sum /= 2;
        len %= M; sum %= M;
        res = (res + ((i * len) % M) * sum) % M;
        cur = next;
    }
    cout << res << endl;
}
 
int main() {
#ifdef LOCAL
    int start_time = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    solve();
 
#ifdef LOCAL
    cerr << "time: " << (clock() - start_time) / (double) CLOCKS_PER_SEC << " sec" << endl;
#endif
    return 0;
}
