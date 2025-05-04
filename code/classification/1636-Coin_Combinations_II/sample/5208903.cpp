#include <bits/stdc++.h>
#define err(args...) {}
#ifdef DEBUG
#include "_debug.cpp"
#endif
using namespace std;
using ll = long long;
using ld = long double;
template <typename T> using lim = numeric_limits<T>;
template <typename T> istream& operator>>(istream& is, vector<T>& a) { for(T& x : a) { is >> x; } return is; }
template <typename X, typename Y> istream& operator>>(istream& is, pair<X, Y>& p) { return is >> p.first >> p.second; }
const int M = 1'000'000'007;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    cin >> c;
    c.insert(c.begin(), 0);
    vector ways(n + 1, vector<int>(x + 1));
    for(int i = 0; i <= n; i++) {
        for(int amt = 0; amt <= x; amt++) {
            int& ans = ways[i][amt];
            if(i == 0) {
                ans = amt == 0;
            } else {
                ans = ((amt >= c[i] ? ways[i][amt - c[i]] : 0) + ways[i - 1][amt]) % M;
            }
        }
    }
    cout << ways[n][x] << endl;
    return 0;
}