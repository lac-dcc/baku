#include "bits/stdc++.h"
//#include <quadmath.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define fo(i, n) for (int i = 0; i < n; i++)
#define deb(x) cout << #x << " " << x << "\n";
#define pb push_back
#define mp make_pair
#define minusone  \
  cout << "-1\n"; \
  return;
#define el "\n"
#define pel cout << "\n";
#define accuracy setprecision(30)
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<ll, ll>>
#define mii map<int, int>
#define all(x) x.begin(), x.end()
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
typedef long long int ll;
typedef long double ld;
const ll mod = 1000000007;
const ll mod1 = 998244353;
const long double Pi = acos(-1);
const long double euler = 2.7182818284590452353602;
 
ll ipow(ll a, ll n)
{
  ll result = 1;
  for (;;)
  {
    if (n & 1)
      result *= a;
    n >>= 1;
    if (!n)
      break;
    a *= a;
  }
  return result;
}
 
ll backtrack(ll i, ll sum, ll target, ll n, vll v)
{
  if (sum > target)
    return 0;
  if (i == n)
    return sum;
 
  return max(backtrack(i + 1, sum + v[i], target, n, v), backtrack(i + 1, sum, target, n, v));
}
 
ll Nc2(ll n)
{
  return n * (n - 1) / 2;
}
 
void show(vector<int> arr)
{
  for (auto i : arr)
    cout << i << ' ';
  pel;
}
 
bool isPrime(int n)
{
  if (n <= 1)
    return false;
 
  if (n <= 3)
    return true;
 
  if (n % 2 == 0 || n % 3 == 0)
    return false;
 
  for (int i = 5; i * i <= n; i = i + 6)
  {
    if (n % i == 0 || n % (i + 2) == 0)
      return false;
  }
 
  return true;
}
 
void dfs(int node, vi graph[], vi &visited)
{
  visited[node] = 1;
 
  for (auto i : graph[node])
  {
    if (!visited[i])
      dfs(i, graph, visited);
  }
}
// vi A;
// int arr[] = {10, 9, 8, 7, 6, 4, 5, 2, 1, 3};
// int n = sizeof(arr)/sizeof(arr[0]);
// fo(i, n) { A.pb(arr[i]); }
void psi()
{
  int n, m, x, y;
  cin >> n >> m;
 
  vi graph[n + 1];
  vi visited(n + 1);
 
  fo(i, m)
  {
    cin >> x >> y;
    graph[x].pb(y);
    graph[y].pb(x);
  }
 
  int ans = 0;
  vpii v;
  for (int i = 1; i <= n; i++)
  {
    if (!visited[i])
    {
      if (ans)
        v.pb({i - 1, i});
      ans++;
      dfs(i, graph, visited);
    }
  }
  cout << ans - 1 << el;
  for (auto i : v)
  {
    cout << i.first << ' ' << i.second << el;
  }
}
 
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T = 1;
  // cin >> T;
 
  for (int i = 1; i <= T; i++)
  {
    psi();
  }
  return 0;
}
