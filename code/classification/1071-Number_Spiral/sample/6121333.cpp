// This code is written by aryan007awm
#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using db = long double;
using str = string;
#define PI 3.1415926535897932384626433832795
 
// loops
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define rep(a) F0R(_, a)
 
//>>>>>>>--SOLVE function--<<<<<<<
 
void solve()
{
    ll x, y;
    cin >> y >> x;
    ll n = max(x, y);
    ll sq = 0;
    for (ll i = 0; i < n; i++)
    {
        sq += n;
    }
    if (n % 2 == 0)
    {
        if (y > x)
        {
            cout << sq - (n - 1) + (y - x) << "\n";
        }
        if (y < x)
        {
            cout << sq - (n - 1) - (x - y) << "\n";
        }
        if (y == x)
        {
            cout << sq - (n - 1) << "\n";
        }
    }
    if (n % 2 == 1)
    {
        if (y > x)
        {
            cout << sq - (n - 1) - (y - x) << "\n";
        }
        if (y < x)
        {
            cout << sq - (n - 1) + (x - y) << "\n";
        }
        if (y == x)
        {
            cout << sq - (n - 1) << "\n";
        }
    }
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
