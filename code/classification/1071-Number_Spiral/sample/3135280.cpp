#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
void solve() {
    ll y, x;
    cin >> y >> x;
    if (y <= x) {
        if(x&1) {
            cout << x*x-y+1;
        } else {
            cout << (x-1)*(x-1)+y;
        }
    } else {
        if(y&1) {
            cout << (y-1)*(y-1) + x;
        } else {
            cout << y*y - x +1; 
        }
    }
    cout << "\n";
}
 
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int t;
    cin >> t;
    while(t--)
        solve();
 
}