#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
typedef long long ll;
 
ll n, k;
vector <ll> a;
 
int main() {
    ios_base::sync_with_stdio(false);
 
    cin >> n >> k;
    
    for (int i = 0; i < k; ++i) {
        ll x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    k = a.size();
    
    ll sol = 0;
    for (int i = 1; i < (1 << k) ; ++i) {
        ll now = 1;
        bool dobar = 1;
        for (int j = 0; j < k; ++j) {
            if (!(i & (1 << j))) continue;
            
            if (a[j] > n / now){
                dobar = 0;
                break;
            }
            now *= a[j];
        }
 
        if (dobar) {
            if (__builtin_popcount(i) & 1) {
                sol += n / now;
            }
            else {
                sol -= n / now;
            }
        }
    }
    cout << sol << "\n";
 
    return 0;
}