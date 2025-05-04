#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 100000007
 
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> v(k);
    for (ll i = 0; i < k; i++)
    {
        cin >> v[i];
    }
 
    // ll a = 1;
    ll ans = 0;
    for (ll i = 1; i < (1 << k); i++)
    {
        ll num = 1;
        ll flag = 0;
        ll ct = 0;
        for (ll j = 31; j >= 0; j--)
        {
            if (i & (1 << j))
            {
                ct++;
                num *= v[j];
                if (num > n || num<=0)
                {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag)
        {
            continue;
        }
        if (ct % 2 != 0)
        {
            ans += (n / num);
        }
        else
            ans -= (n / num);
        // cout << "i is " << i << ' ' << num << endl;
    }
    if(k==20) ans++;
    cout << ans << endl;
}
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // ll t;cin>>t;while(t--)
    solve();
    // cout<<(1<<4);
}