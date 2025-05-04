#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define deb(x) cout<<#x<<'='<<x<<'\n';
#define deb2(x,y) cout<<#x<<'='<<x<<", "<<#y<<'='<<y<<'\n';
#define int long long
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define pb push_back
#define f first
#define s second
#define sz(x) (int)(x).size()
const long double PI = acos(-1);
const int mod = 1e9 + 7, inf = 1e18;
const int D = 2e5 + 10;
 
signed main() {
    fastio
 
    // freopen("../input1.txt", "r", stdin);
    // freopen("../output1.txt", "w", stdout);
 
    int n, k; cin >> n >> k;
    pii a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i].s >> a[i].f;
 
    sort(a, a + n);
 
    int ans = 0;
    multiset<int> ms;
    for (int i = 0; i < k; i++)
        ms.insert(0);
    for (int i = 0; i < n; i++) {
        auto it = ms.upper_bound(a[i].s);
        if (it != ms.begin()) {
            it--;
            ms.erase(it);
            ms.insert(a[i].f);
            ans++;
        }
    }
    cout << ans << '\n';
 
    return 0;
}
