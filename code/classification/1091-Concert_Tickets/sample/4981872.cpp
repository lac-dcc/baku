#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
  ll n, m;
  cin >> n >> m;
  multiset<ll> v;
  vector<ll> arr(m);
  for (ll i = 0; i < n; i++)
  {
    ll x;
    cin >> x;
    v.insert(x);
  }
  for (ll i = 0; i < m; i++)
  {
    cin >> arr[i];
  }
 
  for (ll i = 0; i < m; i++)
  {
    if (v.size() == 0)
    {
      cout << "-1" << endl;
      continue;
    }
 
    auto itr = v.rbegin();
    if ((*itr) < arr[i])
    {
      cout << (*itr) << endl;
      ll kg=(*itr);
      auto itp=v.find(kg);
      v.erase(itp);
      continue;
    }
    auto it = v.lower_bound(arr[i]);
    if ((*it) > arr[i] && it == v.begin())
    {
      cout << "-1" << endl;
    }
    else if ((*it) > arr[i])
    {
      it--;
      cout << (*it) << endl;
      v.erase(it);
    }
    else
    {
      cout << (*it) << endl;
      v.erase(it);
    }
  }
  return 0;
}
