/*author: maxifier**/
#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <stack>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <queue>
#include <vector>
using namespace std;
 
#define int long long int
#define deb(x) cout<<#x<<" "<<x<<" "
 
const int mod = 1e9 + 7;
 
void FCF() {
   int n, m;
   cin >> n >> m;
 
   multiset<int> st;
   for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      st.insert(x);
   }
 
   vector<int> v(m);
   for (int i = 0; i < m; i++) cin >> v[i];
 
   for (int i = 0; i < m; i++) {
      auto it = st.upper_bound(v[i]);
      if (it != st.begin()) {
         it--;
         cout << *it << "\n";
         st.erase(it);
      }
      else {
         cout << "-1\n";
      }
   }
}
 
int32_t main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   int tc, t = 0;
   tc = 1;
   //cin >> tc;
   while (tc--) {
      //++t;
      //cout << "Case " << "#" << t << ":" << " ";
      FCF();
   }
   return 0;
}
