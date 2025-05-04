#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int main()
{
    ll n, m, temp;
    cin >> n >> m;
    multiset<ll, greater<ll>> m_set;
    for (ll i = 0; i < n; i++)
    {
        cin >> temp;
        m_set.insert(temp);
    }
    for (ll i = 0; i < m; i++)
    {
        cin >> temp;
        auto itr = m_set.lower_bound(temp);
        if (itr == m_set.end())
        {
            cout << "-1\n";
        }
        else
        {
            cout << *itr << "\n";
            m_set.erase(itr);
        }
    }
}
