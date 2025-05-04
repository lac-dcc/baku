#include <bits/stdc++.h>
#include <vector>
#include <tuple>
// #include "debugging.h"
// #include <atcoder/lazysegtree>
// #include <atcoder/modint>
// #include <atcoder/dsu>
// using namespace atcoder;
// using mint = modint998244353;
 
using namespace std;
const int LARGE = 1e9;
 
#define all(x) (x).begin(), (x).end()
 
using ll = long long;
typedef pair<ll, ll> pi;
 
ll solve()
{
        ll N;
        cin >> N;
 
        vector<ll> A(N + 1);
        ll maxSumm = INT64_MIN;
        for (int i = 0; i < N; i++)
        {
                ll x;
                cin >> x;
                A[i + 1] = A[i] + x;
                if (A[i + 1] < x)
                        A[i + 1] = x;
                maxSumm = max(maxSumm, A[i + 1]);
        }
 
        cout << maxSumm << '\n';
 
        return 0;
}
 
int main()
{
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        // freopen("div7.in", "r", stdin);
        // freopen("div7.out", "w", stdout);
 
        // ll caseCnt = 1;
 
        // ll T;
        // cin >> T;
        // while (T--)
        // {
        solve();
 
        // 	cout << "Case #"<< caseCnt << ": " << ans << '\n';
        // 	caseCnt++;
        // }
 
        return 0;
}
