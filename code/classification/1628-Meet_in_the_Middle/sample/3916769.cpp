#include <bits/stdc++.h>
 
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define endl '\n'
 
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, a, b, c) for (int i = a; i < b; i += c)
#define Each(i, v) for (auto& i : v)
 
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
// template<typename T1, typename T2>
// ostream& operator<<(ostream& os, const pair<T1, T2> &a) {
//     return os << "(" << a.first << ", " << a.second << ")";
// }
 
/* ------------------------------------------- */
 
const int maxn = (1<<20) + 1;
const int INF = 2e9;
const ll LLINF = 1e18;
const ll MOD = 1e9 + 7;
 
const int MX = 1e9 + 1;
 
 
inline int lb(int& x) {
    return x & (-x);
}
 
 
int inn, n, na, nb; int x;
int v[40], a[20], b[20];
int sa[maxn], sb[maxn], buf[maxn], maptr = 0, mbptr = 0;
short lg[maxn];
 
 
void init() {
    REP(i, 20) lg[1<<i] = i;
    
    cin >> n >> x;
    REP(i, n) cin >> v[i];
    sort(v, v+n);
    REP(i, n/2) a[na++] = v[i];
    FOR(i, n/2, n, 1) b[nb++] = v[i];
}
 
 
void solve() {
    ll ans = 0;
    
    maptr++;
    REP(i, na) {
        int original = maptr;
        REP(j, original) {
            if (sa[j] + a[i] == x) ans++;
            else if (sa[j] + a[i] < x) sa[maptr++] = sa[j] + a[i];
        }
        merge(sa, sa+original, sa+original, sa+maptr, buf);
        copy(buf, buf+maptr, sa);
    }
 
    mbptr++;
    REP(i, nb) {
        int original = mbptr;
        REP(j, original) {
            if (sb[j] + b[i] == x) ans++;
            else if (sb[j] + b[i] < x) sb[mbptr++] = sb[j] + b[i];
        }
        merge(sb, sb+original, sb+original, sb+mbptr, buf);
        copy(buf, buf+mbptr, sb);
    }
    
    for (int i = maptr-1, up = 0, low = 0; i >= 0; i--) {
        while (low < mbptr && sa[i] + sb[low] < x) low++;
        up = max(low, up);
        while (up < mbptr && sa[i] + sb[up] <= x) up++;
        ans += up-low;
    }
    
    cout << ans << endl;
}
 
 
int main() {
    fastio
    
    init();
    solve();
 
    return 0;
}
/*
 
 
4 5
1 2 3 2
 
 
 
 
 
 
 
 
 
 
 */
