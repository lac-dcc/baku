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
    map<int, int> flag;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (flag[temp] == 0)
        {
            flag[temp]++;
            cnt++;
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