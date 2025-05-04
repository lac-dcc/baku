#include <bits/stdc++.h>
using namespace std;
#define li long long int
#define le long double
#define mod 1000000007
#define maxe 100006
vector<bool> pu(maxe + 1, false);
vector<li> pr;
vector<li> prevprime(maxe + 1, 1);
class dop
{
public:
  li n, m, p, q, r, k;
  void get();
};
void seive()
{
  for (li i = 2; (i) <= maxe; i++)
  {
    if (!pu[i])
    {
      prevprime[i] = i;
      for (li j = (2 * i); j <= maxe; j += i)
      {
        if (!pu[j])
        {
          prevprime[j] = i;
        }
        pu[j] = true;
      }
      pr.push_back(i);
    }
  }
}
li power(li x, li n)
{
  li res = 1;
  while (n > 0)
  {
    if (n & 1)
    {
      res = ((res % mod) * (x % mod)) % mod;
    }
    n = n >> 1;
    x = ((x % mod) * (x % mod)) % mod;
  }
  return res;
}
li inv(li x)
{
  return power(x, mod - 2);
}
void factor(li x)
{
  while (x != 1)
  {
    li div = prevprime[x];
 
    while (prevprime[x] == div)
    {
      x /= div;
    }
  }
}
li gcd(li a, li b)
{
  if (a == 0)
  {
    return b;
  }
  return gcd(b % a, a);
}
void dop::get()
{
  string s, v;
  cin >> s >> v;
  n = s.length();
  m = v.length();
  vector<vector<li>> dp(n + 1, vector<li>(m + 1, 1e6));
  for (li i = 0; i <= n; i++)
  {
    dp[i][0] = i;
  }
  for (li j = 0; j <= m; j++)
  {
    dp[0][j] = j;
  }
  for (li i = 1; i <= n; i++)
  {
    for (li j = 1; j <= m; j++)
    {
      if (s[i - 1] == v[j - 1])
      {
        dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
      }
      dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
      dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
      dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
    }
  }
  cout << dp[n][m] << endl;
}
 
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
#ifndef ONLINE_JUDGE
  // for getting input from input.txt
  freopen("input.txt", "r", stdin);
  // for writing output to output.txt
  freopen("output.txt", "w", stdout);
#endif
 
  li t = 1;
  //cin >> t;
  dop obj[t];
  // seive();
  for (li i = 0; i < t; i++)
  {
    obj[i].get();
  }
  return 0;
}