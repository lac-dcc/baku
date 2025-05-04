#include <bits/stdc++.h>
using namespace std;
 
void setIO(string file = "")
{
  // speed up
  cin.tie(0)->sync_with_stdio(0);
  if ((int)(file.size()))
  {
    freopen((file + ".in").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
  }
}
 
long long n;
const int MOD = 1e9 + 7;
long long twoMODINV;
long long modpow(int base, int power)
{
  if (power == 0)
    return 1;
  long long result = modpow(base, power / 2);
  if (power % 2 == 0)
  {
    return (result % MOD * result % MOD) % MOD;
  }
  else
  {
    return ((result % MOD) * (result % MOD) * base) % MOD;
  }
}
long long sumrange(long long start, long long end)
{
  return ((((end - start + 1) % MOD) * ((end + start) % MOD))%MOD * twoMODINV)%MOD;
}
 
int main()
{
  setIO();
  cin >> n;
  long long sum = 0;
  twoMODINV = modpow(2, MOD - 2);
  long long curr = 1;
  while(curr <= n)
  {
    long long repeats = n/curr;
    long long ends = n/repeats;
    sum = (sum + (repeats%MOD * sumrange(curr, ends)%MOD)%MOD)%MOD;
    curr = ends + 1;
  }
  cout<<sum<<endl;
}
