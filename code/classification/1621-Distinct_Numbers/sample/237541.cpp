// 'g++ -std=c++17 -O2 -Wall -Wextra -Wfatal-errors -o sample sample.cpp'
#include<bits/stdc++.h>
#define int long long
#define sz(a) (int)(a).size()
 
using namespace std;
 
template<typename T> struct point { T x;  T y; };
template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }
template<typename... Args> auto Func(Args... args)    { return (args + ...); }
template<typename... Args> void in(Args&... args) { ((cin >> args), ...) ; }
template<typename... Args> void out(Args... args) { ((cout << args << " "), ...); cout << endl;  }
 
const int INF = 1e5+2;
const int MAX = 1e3+1;
const int hell = 1e9+7ll;
 
void solve() {
    int n , a ;
    in(n);
    set<int>arr;
    for( int i = 0 ; i < n ; i++ ){
        in(a);
        arr.insert(a);
    }
    out(size(arr));
}
 
int32_t main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;
    cout.precision(10);
    
    int q = 1;
    //cin >> q;
    while (q--) {
        solve();
    }
    cout << endl;
    return 0;
}