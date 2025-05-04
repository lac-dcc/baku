#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
// #define LOCAL
 
void solve() {
    // Write your solution here
 
    ll x , y , m ,n;
    cin >> x >> y;
    m = max(x,y); //nos from (m-1)^2 + 1 to m^2
    n = min(x,y);
    ll ans;
    ll ans1 = (m-1)*(m-1) + n ; 
    ll ans2 = m*m - n +1 ;
 
    if( m % 2 == 0){
        if(x== m) ans = ans2;
        else ans = ans1;
    }
 
    else{
        if(x==m) ans = ans1;
        else ans = ans2;
    }
 
    cout << ans << "\n";
 
}
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto start_timer = chrono::high_resolution_clock::now();
#endif
 
    int t = 1;
    cin >> t;  // Comment out if single test case
    while (t--) {
        solve();
    }
 
#ifdef LOCAL
    auto stop_timer = chrono::high_resolution_clock::now();
    auto duration =
        chrono::duration_cast<chrono::nanoseconds>(stop_timer - start_timer);
    cerr << "Time taken : "
         << ((long double)duration.count()) / ((long double)1e9) << "s "
         << endl;
#endif
    return 0;
}