/*/ Author: Deep_20 /*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;
#define _   "\n"
#define F   first
#define S   second
#define pb  push_back
#define pf  push_front
#define int long long int
#define mod 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define all(v)  v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define ordered_set tree<int, null_type,less<int >, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_multiset tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
 
 
void mkc()
{
      int n , x;
      cin >> n >> x;
      vector<int> a(n);
      for (int i = 0; i < n; ++i)
      {
            cin >> a[i];
      }
      vector<int> p , q;
      int l1 = n / 2 - 1 - 0 + 1 , l2 = n - 1 - n / 2 + 1;
      for (int i = 0 ; i < (1 << l1) ; i++)
      {
            int sum = 0;
            for (int j = 0; j < l1; j++)
            {
                  if (i & (1 << j))
                  {
                        sum += a[j];
                  }
            }
            p.pb(sum);
      }
      int ans = 0;
      for (int i = 0 ; i < (1 << l2) ; i++)
      {
            int sum = 0;
            for (int j = 0; j < l2; j++)
            {
                  if (i & (1 << j))
                  {
                        sum += a[n / 2 + j];
                  }
            }
            q.pb(sum);
      }
      sort(all(p));
      sort(all(q));
      for (auto e : p)
      {
            ans += upper_bound(all(q) , x - e) - lower_bound(all(q) , x - e);
      }
      cout << ans << _;
}
 
signed main()
{
      ios_base::sync_with_stdio(false);
      cout.tie(0); cin.tie(0);
#ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
#endif
      mkc();
      return 0;
}
