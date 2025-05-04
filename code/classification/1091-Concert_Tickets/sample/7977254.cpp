#include<bits/stdc++.h>
using namespace std;
 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
void primeFactors(int n , vector<int> &primes) {
    // Print the number of 2s that divide n
    while (n % 2 == 0)
    {
        primes.pb(2) ;
        n = n / 2;
    }
 
    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            primes.pb(i) ;
            n = n / i;
        }
    }
 
    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        primes.pb(n) ;
}
 
ll power(ll a , ll b) {
    if (b == 0) {
        return 1 ;
    }
 
    ll ans = power(a, b / 2) ;
    if (b & 1) {
        return ans * ans * a ;
    }
    else {
        return ans * ans ;
    }
}
 
ll lcm(int a , int b) {
    ll hcf = __gcd(a, b) ;
    return a * b / hcf ;
}
 
void solve() {
    int n , m ;
    cin >> n >> m ;
    multiset<int> st ;
    while (n--) {
        int x ;
        cin >> x;
        st.insert(x) ;
    }
 
    while (m--) {
        int x;
        cin >> x ;
        if (st.empty()) {
            cout << -1 << nline ;
            continue;
        }
 
        auto it = st.upper_bound(x) ;
        if (it == st.begin()) {
            cout << -1 << nline ;
            continue ;
        }
 
        it-- ;
        cout << *it << nline ;
        st.erase(it) ;
    }
}
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
 
    fastio();
    int t = 1 ;
    // cin >> t ;
    for (int i = 0 ; i < t ; i++) {
        // cout << "Case #" << i + 1 << ": " ;
        solve() ;
        // cout << nline ;
    }
 
}
