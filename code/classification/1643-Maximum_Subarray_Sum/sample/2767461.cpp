#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    ll maxx = a[0], sum = a[0];
    for (ll i = 1; i < n; i++)
    {
        if (sum < 0)
        {
            maxx = max(maxx, sum);
            sum = 0;
        }
        sum += a[i];
        maxx = max(maxx, sum);
    }
    cout << (ll)maxx;
    return 0;
}
