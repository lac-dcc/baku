#include <bits/stdc++.h>
// #include "./stdc++.h"
using namespace std;
typedef long long int ll;
 
const int N = 2e5 + 10;
ll n, k, arr[N];
set<pair<ll, ll>, greater<pair<ll, ll>>> per;
set<pair<pair<ll, ll>, ll>> eve;
 
int main(int argc, char const *argv[])
{
    // freopen("input.txt", "r", stdin);
    scanf("%lld%lld", &n, &k);
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        scanf("%lld%lld", &a, &b);
        eve.insert({{b, a}, i});
    }
    for (int i = 0; i < k; i++)
    {
        per.insert({0, i});
    }
    ll ans = 0;
    for (auto i : eve)
    {
        ll a = i.first.second, b = i.first.first;
        auto it = per.lower_bound({a, 1 << 30});
        if (it != per.end())
        {
            per.insert({b, it->second});
            per.erase(it);
            ans++;
        }
    }
    printf("%lld\n", ans);
    return 0;
}