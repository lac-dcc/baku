// Jayanth PSY
 
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
 
#include <bits/stdc++.h>
 
using namespace std;
 
 
using uns = unsigned;
using ll = long long;
using vb = vector<bool>;
using vc = vector<char>;
using vi = vector<int>;
using ii = pair<int, int>;
using vu = vector<uns>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vs = vector<string>;
using sll = set<ll>;
using pll = pair<ll, ll>;
 
using msll = multiset<ll>;
using mll = map<ll, ll>;
 
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define what_is(x) cerr << #x << " is " << (x) << endl;
#define rep(i, start, end) for(ll i = (start); i < (end); ++i)
 
template<typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) {
    is >> p.first >> p.second;
    return is;
}
 
template<typename T>
istream &operator>>(istream &is, vector<T> &p) {
    for (T &x: p) is >> x;
    return is;
}
 
template<typename T>
ostream &operator<<(ostream &os, vector<T> &p) {
    for (auto i = 0; i < p.size() - 1; ++i) {
        os << p[i] << ' ';
    }
    if (not p.empty())
        os << p.back();
    return os;
}
 
template<typename T>
void print(T a) {
    cout << a << '\n';
}
 
template<typename T, typename... Args>
void print(T a, Args... args) {
    cout << a << ' ';
    print(args...);
}
 
 
const ll INF = 1e18;
 
//const ll M = 1000000007;
 
 
 
 
string s1, s2;
ll dest = 0;
 
const ll factor = 1e10;
 
vvll dp;
vector<vb> done;
 
 
ll prob(ll start, ll ind) {
    if (ind == s2.size()) {
        return start == dest ? factor : 0;
    }
 
    if (done[start + s1.size() + 2][ind]) {
        return dp[start + s1.size() + 2][ind];
    }
 
    done[start + s1.size() + 2][ind] = true;
    ll ans;
    switch (s2[ind]) {
        case '+': {
            ans = prob(start + 1, ind + 1);
            break;
        }
        case '-': {
            ans = prob(start - 1, ind + 1);
            break;
        }
        case '?': {
            ans = prob(start + 1, ind + 1) + prob(start - 1, ind + 1);
            ans /= 2;
            break;
        }
    }
    return dp[start + s1.size() + 2][ind] = ans;
 
}
 
 
void solve(ll t) {
    ll n; cin >> n;
    sll v;
    rep (i, 0, n) {
        ll x; cin >> x;
        v.insert(x);
    }
    print(v.size());
 
}
 
signed main() {
 
    IOS
    ll T = 1;
//    cin >> T;
    for (int i = 0; i < T; ++i) {
        solve(i + 1);
    }
//    while (T--)
//        solve();
    return 0;
 
}