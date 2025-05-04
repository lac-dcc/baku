#include <iostream>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <chrono>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
 
const int mmx = 1e9 + 1;
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count() % mmx;
struct chash {
    int operator()(int x) const { return x ^ RANDOM; }
};
 
int A[40];
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x; cin >> n >> x;
    int g = x;
    for(int i = 0; i < n; ++i) {
        cin >> A[i];
        g = __gcd(g, A[i]);
    }
    
    for(int i = 0; i < n; ++i)
        A[i] /= g;
    x /= g;
 
    unordered_map <int, int, chash> box;
    ll nx = 0;
    for(int i = (1 << (n >> 1)) - 1; i >= 0; --i) {
        ll mx = 0;
        for(int j = i; j; j -= j & (-j)) {
            if(mx > mmx) break;
            mx += A[__builtin_ctz(j)]; }
 
        if(mx <= mmx) box[mx] += 1;
    }
 
    int r = n - n / 2;
    n /= 2;
    for(int i = (1 << r) - 1; i >= 0; --i) {
        int mx = 0;
        for(int j = i; j; j -= j & (-j)) {
            if(mmx < mx) break;
            mx += A[__builtin_ctz(j) + n]; }
 
        if (mx <= mmx and box.count(x - mx) > 0)
            nx += box[x - mx];
    }
    
    cout << nx;
 
    return 0;
}
