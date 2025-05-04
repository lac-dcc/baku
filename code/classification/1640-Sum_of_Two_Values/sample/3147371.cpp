#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B> ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream &operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << " " << H; dbg_out(T...); }
#ifdef SMIE
#define debug(args...) cerr << "(" << #args << "):", dbg_out(args)
#else
#define debug(args...)
#endif
void solve()
{
    int n, x; cin >> n >> x;
    map<int, int> mp;
    vector<int> vec;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        mp[a] = i + 1;
        vec.push_back(a);
    }
    bool hand = false;
    for (int i = 0; i < n; i++) {
        int need = x - vec[i], ans = -1;
        if (i + 1 != mp[need])
            ans = mp[need];
        if (ans > 0) {
            cout << i + 1 << ' ' << ans << '\n';
            hand = true;
            break;
        }
    }
    if (!hand) cout << "IMPOSSIBLE" << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false); //Don't mix c eith c++ IO
    cin.tie(nullptr);  //Don't Use for interactive problem
    int test = 1;
    //cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}
