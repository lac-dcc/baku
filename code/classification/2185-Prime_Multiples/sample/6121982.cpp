#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n, ans = 0;
    cin >> n;
    int k, two_k;
    cin >> k;
    two_k = (1 << k);
    vector<ll> a(k);
    for (auto &ele : a)
        cin >> ele;
 
    for (int i = 1; i < two_k; i++)
    {
        ll prod = 1;
        int tmp = i, cnt = 0, idx = 0;
        while (tmp > 0 && prod > 0)
        {
            if (tmp & 1)
            {
                if ((n / a[idx]) >= prod)
                    prod *= a[idx];
                else
                    prod = 0;
                cnt++;
            }
            tmp >>= 1;
            idx++;
        }
        if (prod == 0)
            continue;
        if (cnt & 1)
            ans += (n / prod);
        else
            ans -= (n / prod);
    }
    cout << ans;
    return 0;
}