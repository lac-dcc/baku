#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(v) (v).begin(), (v).end()
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class A, class B> ostream& operator<<(ostream& os, const pair<A,B>& p) {
	return os << '(' << p.first << ", " << p.second << ')';
}
template<class T> auto operator<<(ostream& os, T&& x) -> decltype(x.begin(), os) {
	os << '{';
	for(auto it = x.begin(); it != x.end(); ++it) os << *it << (it == prev(x.end()) ? "" : ", ");
	return os << '}';
}
void dump() {}
template<class T,class... Args> void dump(T&& x,Args... args) { cerr<<x<<";  "; dump(args...); }
#ifdef DEBUG
    struct Lf{ ~Lf() { cerr << '\n'; } };
    #define debug(x...) cerr << (strcmp(#x, "") ? #x ":  " : ""), dump(x), Lf(), cerr << ""
#else
    #define debug(...) 0&&cerr
#endif
 
ll n;
int k;
vector<ll> p;
 
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    p.resize(k);
    for (int i=0; i<k; ++i) {
        cin >> p[i];
    }
    ll ans = 0;
    for (int i=1; i<(1<<k); ++i) {
        int cnt = 0;
        ll prod = 1;
        bool over = false;
        for (int j=0; j<k; ++j) {
            if (i & (1<<j)) {
                ++cnt;
                if (n/p[j]>=prod) {
                    prod *= p[j];
                }
                else {
                    over = true;
                    break;
                }
            }
        }
        if (!over) {
            if (cnt & 1) ans += n/prod;
            else ans -= n/prod;
        }
    }
    cout << ans << endl;
 
    return 0;
}