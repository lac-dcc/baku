#include <bits/stdc++.h>
 
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds; // pb_ds
//#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
 
 
using namespace std;
typedef long long ll;
typedef long double ld;
#define EPS (1e-9)
 
//             N  E  S  W  NW  NE SE SW
//int dr[] = {-1, 0, 1, 0, -1, -1, 1, 1};
//int dc[] = {0, 1, 0, -1, -1, 1, 1, -1};
 
class Project {
public:
    int s, e;
    ll w;
 
    Project(int a = 0, int b = 0, ll c = 0) : s(a), e(b), w(c) {
 
    }
 
    Project(const Project &other) : s(other.s),
                                    e(other.e),
                                    w(other.w) {
 
    }
 
    Project &operator=(const Project &other) {
        s = other.s;
        e = other.e;
        w = other.w;
        return *this;
    }
 
    bool operator<(const Project &other) const {
        if (s != other.s) return s < other.s;
        return e < other.e;
    }
 
    bool operator==(const Project &other) const {
        return s == other.s && e == other.e;
    }
};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
//    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
 
    int n;
    cin >> n;
    vector<Project> a(n);
    for (int i = 0; i < n; ++i) {
        int s, e, w;
        cin >> s >> e >> w;
        a[i] = Project(s, e, w);
    }
 
    sort(a.begin(), a.end());
    
    vector<ll> dp(n);
    for (int i = n - 1; i >= 0; --i) {
        ll p1 = i + 1 < n ? dp[i + 1] : 0LL;
 
        ll p2 = a[i].w;
        const Project key(a[i].e + 1, 0, 0);
        int j = lower_bound(a.begin(), a.end(), key) - a.begin();
        if (j < n) p2 += dp[j];
        dp[i] = max(p1, p2);
    }
 
    cout << dp[0] << '\n';
 
    return 0;
}