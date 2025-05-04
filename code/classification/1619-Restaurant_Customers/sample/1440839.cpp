/*
*    @Date    : 2020-12-28 08:54:06
*    @Author  : aerma7309 
*/
 
#include <bits/stdc++.h>
using namespace std;
int FastIO = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
const int inf = 1e9 + 5;
signed main()
{
    int n, cnt = 0, ans = -1e9 + 5;
    cin >> n;
    vector<int> a(n), d(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> d[i];
    a.push_back(inf), d.push_back(inf);
    sort(a.begin(), a.end());
    sort(d.begin(), d.end());
    for (int i = 0, j = 0; i < n or j < n;)
    {
        while (j < n and d[j] <= a[i])
            cnt--, j++;
        while (i < n and a[i] < d[j])
            cnt++, i++, ans = max(ans, cnt);
    }
    cout << ans;
    return 0;
}
