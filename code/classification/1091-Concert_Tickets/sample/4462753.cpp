#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define endl "\n"
#define nahi            \
    cout << -1 << endl; \
    return;
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    multiset<ll> s;
    forn(i, n)
    {
        cin >> a[i];
        s.insert(a[i]);
    }
    forn(i, m)
    {
        cin >> b[i];
        auto itr = s.lower_bound(b[i]);
        if (*itr != b[i] && itr == s.begin())
        {
            cout << -1 << endl;
        }
        else if (*itr != b[i] && itr != s.begin())
        {
            cout << *(--itr) << endl;
            s.erase(itr);
        }
        else
        {
            cout << *itr << endl;
            s.erase(itr);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t = 1;
    while (t--)
        solve();
}
