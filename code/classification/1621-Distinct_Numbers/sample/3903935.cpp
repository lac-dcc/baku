#include <bits/stdc++.h>
#define nline "\n"
using namespace std;
typedef long long ll;
#define vi vector<int>
#define vs vector<string>
#define vll vector<ll>
#define vi vector<int>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
 
///////////////////////////////////////////////////
 
void solve()
{
    int n;
    cin >> n;
    vi arr;
    int cnt;
    for (int i = 0; i < n; i++)
    {
        cin >> cnt;
        arr.push_back(cnt);
    }
    sort(arr.begin(), arr.end());
    cnt = 1;
    int prev = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != prev)
        {
            cnt++;
            prev = arr[i];
        }
    }
    cout << cnt << nline;
}
 
int main()
{
    fast;
    solve();
    return 0;
}