#include <iostream>
#include <bits/stdc++.h>
#include <vector>
 
#define ll long long
 
using namespace std;
 
int main() {
    ll t, y, x;
 
    cin >> t;
 
    for (int i = 0; i < t; ++i) {
        cin >> y >> x;
        --y, --x;
        ll max_val = max(x, y);
        ll ans = max_val * max_val;
        if (x == max_val) {
            if (x % 2 == 0){
                ans += x + 1 + max_val - y;
            } else {
                ans += y + 1;
            }
        } else if (y == max_val){
            if (y % 2 == 0) {
                ans += x + 1;
            }else {
                ans += y + 1 + max_val - x;
            }
        } else {
            ans += x + 1;
        }
 
        cout << ans << '\n';
 
    }
 
 
}