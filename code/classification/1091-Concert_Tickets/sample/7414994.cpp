#include <bits/stdc++.h>
using namespace std;
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define ll long long
#define ull unsigned long long
void solve()
{
    int n, m;
    cin >> n >> m;
    multiset<ll> mp;
    ll arr2[m];
 
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        mp.insert(x);
    }
 
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
        auto it = mp.upper_bound(arr2[i]);
        if (it == mp.begin())
        {
            cout << -1 << endl;
        }
        else
        {
            --it; 
            cout << *it << endl;
            mp.erase(it);
        }
    }
}
 
int main()
{
    int t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
}
