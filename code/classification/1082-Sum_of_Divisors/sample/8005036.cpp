#include <iostream>
#include <vector>
using namespace std;
 
const int mod = 1e9 + 7;
 
long long total_sum(long long start, long long end) {
    return ((((end - start + 1) % mod) * ((end + start) % mod) % mod) * 500000004 % mod);
}
 
int main() {
    long long n;
    long long ans = 0, now = 1;
    cin >> n;
    while(now <= n) {
        long long add = n / now; // divisor to process
        // The largest num that still has the same value of q
        long long last_same = n / add;
        ans = (ans + add * total_sum(now, last_same)) % mod;
        now = last_same + 1;
    }
    cout << ans << '\n';
    return 0;
}
