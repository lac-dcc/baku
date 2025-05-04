#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
vector<ll> sa, sb, a, b;
ll n;
 
void f(ll i, ll s, vector<ll> &a, vector<ll> &v) // svi subbarays iz a se spremaju sume u v
{
    if (i >= a.size())
    {
        v.push_back(s);
        return;
    }
    f(i + 1, s, a, v);
    f(i + 1, a[i] + s, a, v);
    return;
}
 
signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);
 
    ll x;
    cin >> n >> x;
 
    for (ll i = 0; i < n; ++i)
    {
        ll _;
        cin >> _;
        if (i < n / 2)
            a.push_back(_);
        else
            b.push_back(_);
    }
 
    f(0, 0, a, sa);
    f(0, 0, b, sb);
 
    sort(sa.begin(), sa.end());
    sort(sb.begin(), sb.end());
 
    ll cnt = 0;
 
    if (sa.size() < sb.size())
    {
        for (ll i = 0; i < sa.size(); ++i)
        {
            ll trazi = x - sa[i];
            auto [lx, rx] = equal_range(sb.begin(), sb.end(), trazi);
            cnt += rx - lx;
        }
    }
    else
    {
        for (ll i = 0; i < sb.size(); ++i)
        {
            ll trazi = x - sb[i];
            auto [lx, rx] = equal_range(sa.begin(), sa.end(), trazi);
            cnt += rx - lx;
        }
    }
 
    cout << cnt;
}
