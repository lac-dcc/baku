#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define si(x) scanf("%d", &x);
#define sl(x) scanf("%lld", &x);
#define pi(x) printf("%d\n", x);
#define pl(x) printf("%lld\n", x);
#define clr(x) memset((x), 0, sizeof((x)))
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fo(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define rfo(i, a, b) for (int i = (int)(a); i >= (int)(b); i--)
 
using namespace std;
using namespace __gnu_pbds;
 
#define deb(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) { cout << '\n';}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cout << '[' << *it << " = " << a << "]  ";
    err(++it, args...);
}
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef double ld;
typedef tree<int,null_type,less<int>,rb_tree_tag,
        tree_order_statistics_node_update> indexed_set;
 
/******************************************************************************/
/******************************************************************************/
/******************************************************************************/
const int N = 200100;
/*
aimr sanaatai bodlgo !!!!!
https://grocid.net/2016/06/30/computing-sum-of-divisors/?fbclid=IwAR1aAjEAqqTuEAUvNc6E4mYg2BMQVYe6eX4bHmjRD3nd8R4cwWuQzu5tWhE
*/
const ll mod = 1e9 + 7;
ll mult(ll a, ll b) {
    if (b < 10000000) return (a * b) % mod;
    if (b & 1) return ((2 * mult(a, b / 2)) + a) % mod;
    else return (2 * mult(a, b / 2)) % mod;
}
 
void solve() {
    ll n; cin >> n;
    ll q = sqrt(n);
    ll res = 0, i = 1;
    while (i <= q) {
        res += (i * (n / i));
        res %= mod;
        i++;
    }
    i = 1;
    while (i <= n / (q + 1)) {
        ll m = n / i, k = n / (i + 1);
 
        if (m % 2) res += (i * (mult(m, (m + 1) / 2))) % mod;
        else res += (i * (mult(m / 2, m + 1))) % mod;
 
        if (k % 2) res -= (i * (mult(k, (k + 1) / 2))) % mod;
        else res -= (i * (mult(k / 2, k + 1))) % mod;
 
        res %= mod;
        i++;
    }
    if (res < 0) res += mod;
    cout << res << '\n';
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
/******************************************************************************/
/******************************************************************************/
/******************************************************************************/
int main(){
  ios::sync_with_stdio(false); cin.tie(0);
  cout.precision(10); cout << fixed;
 
#ifdef LOCAL_DEFINE
  FILE *f_file;
  f_file = freopen("input.txt", "r", stdin);
  if (f_file == NULL) {
    cerr << "Error opening input file" << '\n';
    return 1;
  }
  f_file = freopen("output.txt", "w", stdout);
  if (f_file == NULL) {
    cerr << "Error opening output file" << '\n';
    return 1;
  }
#endif
 
  int test_case = 1;
  //cin >> test_case;
  while(test_case--){
    solve();
  }
 
#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}
