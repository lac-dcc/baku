#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
    ll n;
    cin >> n;
 
    vector<ll> arr(n);
    for (auto &a : arr) cin >> a;
 
    ll sum = 0, max_so_far = -10000000000;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        max_so_far = max(max_so_far, sum);
        if (sum < 0) {
            sum = 0;
        }
    }
 
    cout << max_so_far << endl;
}
