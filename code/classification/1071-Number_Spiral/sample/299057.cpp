#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
   
    int t;
    cin >> t;
 
    for (int i = 1; i <= t; i++) {
        long long y, x;
        cin >> y >> x;
        if (y > x) {
            if (y % 2 != 0) {
                cout << y * y - 2 * y + x + 1<<endl;
            } else {
                cout << y * y - x + 1<<endl;
            }
        }
        if (x > y) {
            if (x % 2 != 0) {
                cout << x * x - y + 1<<endl;
            } else {
                cout << x * x - 2 * x + y + 1<<endl;
            }
        }
        if (x == y) {
            cout << x * x - x + 1<<endl;
        }
       
    }
}