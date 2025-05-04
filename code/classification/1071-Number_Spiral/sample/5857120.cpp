#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    while (t--) {
        unsigned long long int y, x;
        cin >> y >> x;
        unsigned long long int max_yx_squared, min_yx = min(y, x);
        int add_1 = 0, signal = 1;
        if (y > x) {
            if (y % 2 != 0) {
                y--;
                add_1 = 1;
                signal = -1;
            }
            max_yx_squared = y * y + add_1;
        }
        else {
            if (x % 2 == 0) {
                x--;
                add_1 = 1;
                signal = -1;
            }
            max_yx_squared = x * x + add_1;
        }
        cout << max_yx_squared - signal * (min_yx - 1) << '\n';
    }
    return 0;
}