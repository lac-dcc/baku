#include <bits/stdc++.h>
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("bmi,bmi2,lzcnt")
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define edl '\n'
#ifdef LOCAL
#include "../cp-template/Basic/debug.h"
#else
#define dbg1(args...)
#define dbg2(x)
#define stop
#endif
typedef long long LL;
typedef unsigned long long uLL;
// typedef __int128_t LLL;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef pair<LL, int> pli;
typedef pair<LL, LL> pll;
const int INF = 1e9;
const LL MOD = 998244353;
void solve(int csno)
{
    int n, m;
    cin >> n >> m;
    multiset<int> vec;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vec.insert(x);
    }
    vec.insert(-1);
 
    while(m--)
    {
        int x;
        cin >> x;
        auto itr = vec.upper_bound(x);
        cout << *--itr << "\n";
        if(itr != vec.begin())
            vec.erase(itr);
    }
    cout << edl;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    // cin >> T;
    for (int csno = 1; csno <= T; csno++)
        solve(csno);
}
