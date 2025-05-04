#include <bits/stdc++.h>
using namespace std;
long long m = 1e9 + 7;
long long sum (long long l, long long r)
{
    if ((l + r) & 1)
        return ((l + r) % m * (((r - l + 1) / 2) % m)) % m;
    else
        return (((l + r) / 2) % m * ((r - l + 1) % m)) % m;
}
int main()
{
    long long n, ans;
    cin >> n;
    ans = n % m;
    if (n / 1 != 1)
        ans += sum(n / 2 + 1, n / 1) * 1;
    ans %= m;
 
    for (long long i = 2; i * i <= n; i++)
    {
        //daiut kol-vo
        ans += (i * (n / i)) % m;
        ans %= m;
        if (n / i != i)
            ans += (sum(n / (i + 1) + 1, n / i) * i) % m;
        ans %= m;
    }
 
    cout << ans;
    return 0;
}
