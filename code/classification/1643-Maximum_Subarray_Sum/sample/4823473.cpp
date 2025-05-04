#include <bits/stdc++.h>
using namespace std;
 
long long a[200200];
int main() {
    long long n;
    cin >> n;
    for (long long i = 0; i < n; i++){
        cin >> a[i];
    }
    long long s = 0;
    long long res = INT_MIN;
    for (int i = 0; i < n; i++){
        s = max(a[i], s + a[i]);
        res = max (res, s);
    }
    cout << res;
}
