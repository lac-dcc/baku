#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define int long long int
#define endl '\n'
void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
using namespace __gnu_pbds;
const int M = 1e9 + 7;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
// Author:Abhas
void solution()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int sum = 0;
    int ans = a[0];
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        ans = max(ans, sum);
        if (sum < 0)
        {
            sum = 0;
        }
    }
    cout << ans << endl;
}
signed main()
{
    fastio();
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}
