/**
    Lost Arrow (Aryan V S)
    Friday 2021-01-22
**/
 
#ifdef LOST_IN_SPACE
#  if   __cplusplus > 201703LL
#    include "lost_pch1.h" // C++20
#  elif __cplusplus > 201402LL
#    include "lost_pch2.h" // C++17
#  else
#    include "lost_pch3.h" // C++14
#  endif
#else
#  include <bits/stdc++.h>
#endif
 
constexpr bool test_cases = false;
 
void solve () {
    int n, x;
    std::cin >> n >> x;
    std::vector <std::pair <int64_t, int>> a (n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a [i].first;
        a [i].second = i + 1;
    }
 
    struct pairs {
        int64_t sum = 0;
        int x = -1;
        int y = -1;
    };
 
    std::vector <pairs> v;
    for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) {
        v.push_back({a [i].first + a [j].first, a [i].second, a [j].second});
    }
 
    std::sort(v.begin(), v.end(), [&] (auto& l, auto& r) {
        return l.sum < r.sum;
    });
 
    n = v.size();
    int low = 0, high = n - 1;
    while (low < high) {
        if (v [low].sum + v [high].sum == x) {
            std::set <int> s;
            s.insert(v  [low].x);
            s.insert(v  [low].y);
            s.insert(v [high].x);
            s.insert(v [high].y);
 
            if ((int)s.size() == 4) {
                for (int i : s)
                    std::cout << i << ' ';
                return;
            }
            --high;
        }
        else if (v [low].sum + v [high].sum < x)
            ++low;
        else
            --high;
    }
 
    std::cout << "IMPOSSIBLE" << '\n';
}
 
int main () {
 
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.precision(10);
    std::cerr.precision(10);
    std::cout << std::fixed << std::boolalpha;
    std::cerr << std::fixed << std::boolalpha;
 
    int32_t cases = 1;
    if (test_cases)
        std::cin >> cases;
    while (cases--)
        solve();
 
    return 0;
}
 
// g++.exe -Wall -Weffc++ -Wextra -pedantic -std=c++20 -g -D_GLIBCXX_DEBUG -DLOST_IN_SPACE -H
 
// Replace failing with learning
// Replace overthinking with action
// Replace blame with responsibility
// Replace toxic friends with mentors
// Replace complaining with gratitude
// Replace netflix marathons with sleep
// Replace fake influencers with inspiring creators