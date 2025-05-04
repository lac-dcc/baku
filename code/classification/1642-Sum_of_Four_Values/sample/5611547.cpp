#include <bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
// orderded_set ->  find_by_order(x)<itr, x being 0-indexed>; order_of_key(x)<count, strictly less>
 
typedef long long       ll;
typedef long double     lld;
typedef pair<int,int>   pii;
#define loop(n)         for(int i = 0; i < (n); ++i)
#define rep(i,zz,n)     for(int i = zz; i < (n); ++i)
#define repi(i,zz,n)    for(int i = zz; i >= (n); --i)
#define all(v)          v.begin(),v.end()
#define pb              push_back
#define ff              first
#define ss              second
#define sz(x)           (int)x.size()
#define nline           cout << '\n'
 
#define     debug(x)    cout << #x << " "; _print(x); cout << '\n';
#define     _debug(a,b) cout << #a << " [ "; array_debug(a,b); cout << "]\n";
template <class T, class V> void array_debug(T *a, V n){ rep(i,0,n) cout << a[i] << ' ';}
template <class T>          void _print(T t) {cout << t;}
template <class T, class V> void _print(pair <T, V> p) {cout << "{"; _print(p.ff); cout << ","; _print(p.ss); cout << "}";}
template <class T>          void _print(vector <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T>          void _print(set <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T>          void _print(multiset <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T, class V> void _print(map <T, V> v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]";}
 
const lld eps = 1e-9;
const int mod = 1e9 + 7;
const ll inf = 1e18;
const int N1 = 2e5 + 10;
 
int code(){
 
    ll n, x;
    cin >> n >> x;
 
    vector<ll> v1(n);
    loop(n) cin >> v1[i];
 
    map<ll, vector<pii>> m1;
	rep(i, 0, n) {
		rep(j, i + 1, n) {
			ll cur = v1[i] + v1[j];
			if (cur >= x)	continue;
 
			for (auto [y1, y2] : m1[x - cur]) {
				cout << y1 + 1 << ' ' << y2 + 1 << ' ' << i + 1 << ' ' << j + 1;
				return 0;
			}
		}
 
		rep(j, 0, i) {
			if (v1[i] + v1[j] >= x)	continue;
			m1[v1[i] + v1[j]].pb({ j, i });
		}
	}
    cout << "IMPOSSIBLE";
 
    return 0;
}
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    
    int tc = 1;
    // cin >> tc;
 
    loop(tc)  code();
    // rep(i, 1, tc+1)  cout << "Case #" << i << ": ", code();
 
    return 0;
}