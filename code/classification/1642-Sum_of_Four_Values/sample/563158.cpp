#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll modularExponentiation(ll x, ll n, ll M)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 0)
        return modularExponentiation((x * x) % M, n / 2, M);
    return (x * modularExponentiation((x * x) % M, (n - 1) / 2, M)) % M;
}
ll binaryExponentiation(ll x, ll n)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 0)
        return binaryExponentiation(x * x, n / 2);
    else
        return x * binaryExponentiation(x * x, (n - 1) / 2);
}
ll GCD(ll A, ll B)
{
    if (B == 0)
        return A;
    else
        return GCD(B, A % B);
}
ll extended_GCD(ll a, ll b, ll &x, ll &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll gcd = extended_GCD(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}
ll modinv(ll a, ll mod)
{
    ll x, y;
    extended_GCD(a, mod, x, y);
    if (x < 0)
        x += mod;
    return x;
}
ll modPrimeInverse(ll A, ll M)
{
    return modularExponentiation(A, M - 2, M);
}
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "rt", stdin);
    //     freopen("output.txt", "wt", stdout);
    // #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    ll n, x;
    cin >> n >> x;
    vector<pair<ll, ll>> a;
    for (ll i = 0; i < n; i++)
    {
        ll b;
        cin >> b;
        a.push_back(make_pair(b, i + 1));
    }
    // cout << x << "\n";
    sort(a.begin(), a.end());
    ll flag = 0, i;
    for (ll t = 0; t < n - 3; t++)
    {
        for (i = t + 1; i < n - 2; i++)
        {
            ll j = i + 1, k = n - 1;
            while (j < k)
            {
                // cout << a[i].first << " " << a[j] << " " << a[k] << "\n";
                ll sum = a[i].first + a[j].first + a[k].first + a[t].first;
                // cout << sum << " ";
                if (sum == x)
                {
                    flag = 1;
                    cout << a[t].second << " " << a[i].second << " " << a[j].second << " " << a[k].second << "\n";
                    // j++;
                    // k--;
                    break;
                }
                if (sum > x)
                    k--;
                if (sum < x)
                    j++;
            }
            // cout << "\n";
            if (flag)
                break;
        }
        if (flag)
            break;
    }
    if (!flag)
        cout << "IMPOSSIBLE";
 
    // #ifndef ONLINE_JUDGE
    //     cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
    // #endif
    return 0;
}
