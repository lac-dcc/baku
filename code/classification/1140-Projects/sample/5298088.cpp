// Example program
#include <iostream>
#include <string>
#include<vector>
#include <utility>
#include <algorithm>
 
using Days = std::pair<uint64_t, uint64_t>;
using Val = std::pair<Days, uint64_t>;
 
bool compare(const Val& v1, const Val& v2)
{
    return v1.first.second < v2.first.second;
}
 
bool compare2(const Days& v1, const uint64_t v2)
{
    return v1.first < v2;
}
 
uint64_t max(uint64_t a, uint64_t b)
{
    return (a > b) ? a : b;
}
 
uint64_t bynary_search(std::vector<Days> v, uint64_t val)
{
    if (v.back().first < val)
    {
        return v.back().second;
    }
    uint64_t l = 0, r = v.size() - 1, mid = 0;
    while (l < r)
    {
        mid = (l + r) / 2;
        if (v[mid].first < val)
        {
            if (v[mid + 1].first >= val)
            {
                return v[mid].second;
            }
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
}
 
 
uint64_t func(std::vector<Val> days)
{
    std::vector<Days> dp;
    std::sort(days.begin(), days.end(), compare);
    dp.emplace_back(0, 0);
    uint64_t res = 0;
    for (auto cur : days)
    {
        auto ind = std::lower_bound(dp.begin(), dp.end(), cur.first.first, compare2) - 1;
        
        uint64_t cos = cur.second + ind->second;
        if (cos > res)
        {
            res = cos;
            dp.emplace_back(cur.first.second, cos);
        }
    }
    return res;
}
 
int main()
{
    uint64_t a,b, n, p;
    std::cin >> n;
    std::vector<Val> v;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a>>b>>p;
        v.emplace_back(std::make_pair(a, b), p);
    }
    std::cout << func(v);
}