#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
ll MOD = 1e9 + 7;
double eps = 1e-12;
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define SPEED                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define cjam(i) cout << "Case #" << it + 1 << ": "
#define min_heap priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
#define max_heap priority_queue<pair<int, int>, vector<pair<int, int>>>
#define sz(x) ((ll)(x).size())
 
void solve()
{
    int n, sum;
    cin >> n >> sum;
    unordered_map<int, int> m;
    vector<pi> v;
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        v.push_back({a, i + 1});
    }
    sort(all(v));
    for (int i = 0; i < n - 3; ++i)
    {
        for (int it = i + 1; it < n - 2; ++it)
        {
 
            int s = sum - v[i].first - v[it].first;
            int k = n - 1;
            for (int j = it + 1; j < k;)
            {
                if (v[j].first + v[k].first == s)
                {
                    cout << v[i].second << " " << v[it].second << " " << v[j].second << " " << v[k].second;
                    return;
                }
                else if (v[j].first + v[k].first < s)
                    ++j;
                else
                    --k;
            }
        }
    }
 
    cout << "IMPOSSIBLE";
}
int main()
{
    SPEED;
    ll t = 1;
    //cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}
