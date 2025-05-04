#include<bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
using namespace std;
using namespace chrono;
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
 
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define t() int test=1; cin >> test; while (test--)
#define mod 1000000007
#define mod2 998244353
#define inf 1e18
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define endl "\n"
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<vector<int>> vvi;
typedef vector<pi> vii;
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) { cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}"; }
template <class T> void _print(vector <T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(set <T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(multiset <T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(map <T, V> v) { cerr << "[ "; for (auto i : v) { _print(i); cerr << " "; } cerr << "]"; }
 
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}
 
template<typename T1, typename T2> // cout << pair<T1, T2>
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }
 
 
bool cmp(pi& a, pi& b) {
    return a.ss < b.ss;
}
void solve() {
    int n, k; cin >> n >> k;
    multiset<int> st;
    // for (int i = 0; i < k; i++) st.insert(0);
    // st.insert(0);
    int cnt = 0;
    vii arr;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        arr.push_back({a, b});
    }
    sort(all(arr), cmp);
    debug(arr);
    for (int i = 0; i < n; i++) {
        if (sz(st) and * st.begin() <= arr[i].ff) {
            ++cnt;
            auto it = st.upper_bound(arr[i].ff);
            it--;
            st.erase(it);
            st.insert(arr[i].ss);
        }
        else if (sz(st) < k) {
            ++cnt;
            st.insert(arr[i].ss);
        }
        debug(st);
    }
    cout << cnt << endl;
}
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    fast;
    auto start1 = high_resolution_clock::now();
    solve();
 
 
 
#ifndef ONLINE_JUDGE
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    cerr << "Time: " << duration . count() / 1000 << endl;
#endif
}
