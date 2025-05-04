#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    long long n;
    cin >> n;
    long long arr[n];
    for(long long i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long long ans = arr[0];
    for(long long i = 1; i < n; i++) {
        arr[i] = max(arr[i], arr[i] + arr[i - 1]);
        ans = max(arr[i], ans);
    }
    cout << ans << endl;
    return 0;
}