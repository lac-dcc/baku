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
    int max = 2e5;
    array<int, 3> arr[max];
    int ans[max];
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][1] >> arr[i][0];
        arr[i][2] = i;
    }
    sort(arr, arr + n);
 
    set<array<int, 2>> s;
    for (int i = 0; i < n; i++)
    {
        auto itr = s.lower_bound({arr[i][1] + 1});
        if (itr != s.begin())
        {
            itr--;
            ans[arr[i][2]] = (*itr)[1];
            s.erase(itr);
        }
        else
            ans[arr[i][2]] = s.size();
        if (s.size() < k)
        {
            s.insert({arr[i][0], ans[arr[i][2]]});
            x++;
        }
    }
    cout << x << endl;
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