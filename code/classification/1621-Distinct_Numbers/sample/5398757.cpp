#include <iostream>
#include <algorithm>
 
#define long long long
 
using namespace std;
 
long n, a[200000], t = 1;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (long i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for (long i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) t++;
    }
    cout << t;
}
