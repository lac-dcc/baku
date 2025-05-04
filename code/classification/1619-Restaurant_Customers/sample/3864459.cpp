#include <algorithm>
#include <ios>
#include <iostream>
#include <utility>
#include <vector>
 
using std::cin;
using std::cout;
using std::ios_base;
using std::make_pair;
using std::max;
using std::pair;
using std::sort;
using std::vector;
 
auto solve() {
 
    auto n = 0;
 
    cin >> n;
 
    auto times = vector<pair<int, bool>>(n * 2);
 
    for (auto i = 0; i < n; i++) {
        auto a = 0;
        auto b = 0;
        cin >> a >> b;
        times[i * 2] = make_pair(a, true);
        times[i * 2 + 1] = make_pair(b, false);
    }
 
    sort(
        times.begin(), times.end(),
        [](pair<int, bool>& a, pair<int, bool>& b) {return a.first < b.first;}
    );
 
    auto current = 0;
    auto result = 0;
 
    for (const auto& time : times) {
        if (time.second) {
            current++;
        } else {
            current--;
        }
        result = max(current, result);
    }
 
    cout << result << '\n';
 
}
 
int main() {
 
    cin.tie(nullptr);
 
    ios_base::sync_with_stdio(false);
 
    solve();
 
    return 0;
 
}
