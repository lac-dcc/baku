#include <bits/stdc++.h>
using namespace std;
 
#define LL long long
#define LINF (1LL << 60)
 
void runcase() {
    int N;
    cin >> N;
    vector<LL> vt_arr(N);
    for (auto &u : vt_arr) cin >> u;
    LL cur_sum = 0, cur_min = 0, ans = -2e9;
    for (int i=0; i<N; i++) {
        cur_sum += vt_arr[i];
        ans = max(ans, cur_sum - cur_min);
        cur_min = min(cur_min, cur_sum);
    }
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t;
    // cin >> t;
    // while (t-- > 0)
        runcase();
    return 0;
}
