#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, x, y;
    cin >> n;
    pair<int, int> a[2 * n];
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        a[i * 2] = make_pair(x, 1);
        a[i * 2 + 1] = make_pair(y, -1); 
    }
    
    sort(a, a + 2 * n);
    // a[0].first;
    // a[0].second;
    int ans = 0, sum = 0;
    for(int i = 0; i < 2 * n; i++) {
        sum += a[i].second;
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}
