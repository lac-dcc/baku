#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define print(x) cout << x << endl
#define debug(x) cerr << #x << " : " << x << endl
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
    while (t--) {
        int64_t y, x; cin >> y >> x;
        int64_t mx = max(x, y), mn = min(x, y), ans = 0;
        if ((mx ^ 1) & 1 && y <= x || !((mx ^ 1) & 1) && y >= x) {
            ans = (mx-1)*(mx-1)+mn;
        } else {
            ans = (mx-1)*(mx-1)+mx+(mx-mn);
        }
 
        print(ans);
    }
 
	return 0;
}