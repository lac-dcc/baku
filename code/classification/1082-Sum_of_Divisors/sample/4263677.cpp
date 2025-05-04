#include <bits/stdc++.h>
#define fastio fastioread()
#define int long long
const int mod = 1e9 + 7;
using namespace std;
 
void fastioread()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#ifndef ONLINE_JUDGE
#ifndef CPH
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
#endif
}
int mpow(int a, int n)
{
  int ans = 1;
  while (n)
  {
    if (n & 1)
      ans = (ans * a) % mod;
    a = (a * a) % mod;
    n >>= 1;
  }
  return ans % mod;
}
int inv(int x)
{
  return mpow(x, mod - 2);
}
int moddiv(int a, int b)
{
  return (a * inv(b)) % mod;
}
int solve(int st, int end)
{
  return moddiv((((end - st + 1) % mod) * ((st + end) % mod)) % mod, 2);
}
int32_t main()
{
  fastio;
  int n;
  cin >> n;
  int num = 1;
  int ans = 0;
  while (num <= n)
  {
    int q = n / num;
    int lq = n / q;
    ans = (ans + q * solve(num, lq)) % mod;
    num = lq + 1;
  }
  cout << ans << endl;
}