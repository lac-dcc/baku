// compile: make data
// run: ./data < data.in
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("bmi,bmi2,lzcnt,popcnt")
#ifdef LOCAL
#include <debug/codeforces.h>
#define debug(x...) _debug_print(#x, x);
#define Debug(x...) _debug_print_format(#x, x);
std::ifstream terminal("/dev/tty");
#define PP cerr<<"\033[1;30mpause...\e[0m",terminal.ignore();
#else
#define debug(x...)
#define Debug(x...)
#define PP
#endif
template<typename...Args> void print_(Args...args){((cout<<args<<" "),...)<<endl;}
#define rep(i,a,b) for(int i=(a);i<(int)(b);++i)
#define sz(v) ((int)(v).size())
#define print(...) print_(__VA_ARGS__);
#define FIND(a, x) ((find(a.begin(),a.end(),(x))!=a.end())?1:0)
#define cmin(x,...) x=min({(x),__VA_ARGS__})
#define cmax(x,...) x=max({(x),__VA_ARGS__})
#define INTMAX (int)(9223372036854775807)
#define INF (int)(1152921504606846976)
#define NaN (int)(0x8b88e1d0595d51d1)
#define double long double
#define int long long
#define uint unsigned long long
#define MAXN 200010
 
template <typename T> int corcomp(vector<T> &a, int index = 0, function<int(T)> get = [](int x) {return x; }, function<void(T&, int)> set = [](T &x, int y) {x = y; }) {
    int maxv = 0;
    vector<pair<T, int>> l(sz(a));
    vector<pair<int, int>> r(sz(a));
    rep(i, 0, sz(a)) l[i] = {a[i], i};
    sort(l.begin(), l.end(), [&get](pair<T, int> x, pair<T, int> y) {
        return get(x.first) < get(y.first);
    });
    r[0] = {l[0].second, 0};
    rep(i, 1, sz(a)) {
        r[i].first = l[i].second;
        r[i].second = r[i-1].second + (get(l[i].first) != get(l[i-1].first));
    }
    maxv = r.back().second;
    sort(r.begin(), r.end());
    rep(i, 0, sz(a)) set(a[i], r[i].second + index);
    return maxv + index;
}
 
int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
 
    function<int(pair<int, int>)> get = [](pair<int, int> x) -> int {return x.first; };
    function<void(pair<int, int>&, int)> set = [](pair<int, int> &x, int y) -> void {x.first = y; };
    int n; cin >> n;
    vector<pair<int, int>> a;
    rep(i, 0, n) {
        int l, r; cin >> l >> r;
        a.push_back({l-1, -1});
        a.push_back({r, 1});
    }
    int N = corcomp(a, 0, get, set);
    vector<int> sum(N+1, 0);
    for (auto [x, y]: a) sum[x] += y;
    for (int i = N-1; i >= 0; --i) sum[i] += sum[i+1];
    cout << *max_element(sum.begin(), sum.end()) << endl;
 
    return 0;
}
