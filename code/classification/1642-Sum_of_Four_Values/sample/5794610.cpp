#include <bits/stdc++.h>
using namespace std;
 
#ifndef ONLINE_JUDGE
#include "bugme/bugha.h"
#else
#define debug(...)
#endif
 
#define ll long long
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pair<ll, ll>> vpll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
#define pb push_back
#define forl(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define sortA(a) sort(a.begin(), a.end())
#define sortD(a) sort(a.rbegin(), a.rend())
#define yes() cout << "YES" << endl
#define no() cout << "NO" << endl
const ll inf = 1e9;
 
#define read(a)       \
    for (auto &x : a) \
        cin >> x;
#define out(a)            \
    for (auto &x : a)     \
        cout << x << " "; \
    cout << endl;
 
#define io                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
 
void solve()
{
    ll n;
    cin >> n;
    ll k;
    cin >> k;
    vll v(n);
    read(v);
    map<ll, pll> mp;
    forl(i, 0, n - 1)
    {
        forl(j, i + 1, n)
        {
            if (mp.find(k - v[i] - v[j]) != mp.end())
            {
                pll p = (mp[k - v[i] - v[j]]);
                if (i != p.first && j != p.second && i != p.second && j != p.first)
                {
                    cout << i + 1 << " " << j + 1 << " " << p.first + 1 << " " << p.second + 1 << endl;
                    return;
                }
            }
            if (mp.find(v[i] + v[j]) == mp.end())
                mp[v[i] + v[j]] = {i, j};
        }
    }
 
    debug(mp);
    cout << "IMPOSSIBLE" << endl;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}