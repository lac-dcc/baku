#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    set<pair<ll, int>> s;
    for (ll i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        s.insert({x, 0});
        s.insert({y, 1});
    }
    ll presentCustomer = 0, res = 0;
    for (auto el : s)
    {
        if (el.second == 0)
        {
            presentCustomer++;
        }
        else
        {
            presentCustomer--;
        }
 
        res = max(presentCustomer, res);
    }
    cout << res << endl;
    return 0;
}
