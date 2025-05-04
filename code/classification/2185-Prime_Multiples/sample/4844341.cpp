#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define FAST_IO  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define show(x)  cout << ">> " << #x << " = " << x << '\n'
#define endl     '\n'
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const double EPS = 1e-10;  // epsilon
const double PI = acos(-1);
const int MOD = 998244353;
const int BASE = 31;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5 + 5, M = 1e6 + 5;
 
void myMain()
{
    ll n, ans = 0;
    int k;
    cin >> n >> k;
    vector<ll> a(k);
    for (auto& item : a)
        cin >> item;
    int len = 1 << k;
    for (int mask = 1; mask < len; mask++)
    {
        ll pro = 1;
        int cnt = 0;
        bool flag = false;
        for (int i = 0; i < k; i++)
            if ((1 << i) & mask)
            {
                if (pro > n / a[i])
                {
                    flag = true;
                    break;
                }
                pro *= a[i];
                cnt++;
            }
        if (flag)
            continue;
        if (cnt & 1)
            ans += n / pro;
        else
            ans -= n / pro;
    }
    cout << ans << endl;
}
 
int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    FAST_IO
    int t = 1;
//    cin >> t;
    while (t--)
        myMain();
    return 0;
}