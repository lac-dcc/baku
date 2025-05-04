#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
template<class T, class U> istream& operator>>(istream &is, pair<T, U>& p) { is >> p.first >> p.second; return is; }
template<class T> istream& operator>>(istream& is, vector<T>& vec) { for(auto &x : vec) cin >> x; return is; } 
template<class T, class U> ostream& operator<<(ostream &os, pair<T, U>& p) { os << "<" << p.first << "," << p.second << ">"; return os; }
template<class T> ostream& operator<<(ostream& os, vector<T>& vec) { for(auto x : vec) os << x << " "; return os; }
 
int bitcount(ll mask) {
    int ct = 0;
    while (mask > 0) {
        if (mask & 1) ct++;
        mask >>= 1;
    }
    return ct;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
 
    ll n; cin >> n;
    int k; cin >> k;
    ll res = 0;
 
    vector<ll> primes;
    for (int i = 0; i < k; i++) {
        ll x; cin >> x;
        primes.push_back(x);
    }
 
    for (int mask = 1; mask < (1 << k); mask++) {
        int bc = bitcount(mask);
        ll lc = 1;
        bool over = false;
        for (int i = 0; i < k; i++) {
            if (mask & (1 << i)) {
                ll g = gcd(primes[i], lc);
                if (lc / g > n / primes[i]) {
                    // we will overflow
                    over = true;
                    break;
                }
                lc = lc / g * primes[i];
            }
        }
        if (!over) {
            if (bc % 2) res += n / lc;
            else res -= n / lc;
        }
    }
 
    cout << res << '\n';
    
	return 0;
}