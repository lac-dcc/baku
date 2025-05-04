#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("popcnt,abm,mmx,tune=native")
#include <bits/stdc++.h>
#include <ext/rope>
#include <random>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
 
#define file ""
 
#define all(x) x.begin(), x.end()
 
#define sc second
#define fr first
 
#define pb push_back
#define mp make_pair
 
#define pss pair<line*, line*>   
 
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds; 
 
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
 
template<typename T>
using ordered_set = tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ;
                                 
const ll inf = 1e18;
const int MOD = 1e9 + 7;
 
const int dx[] = {+1, -1, 0, 0, -2, +2, -1, +1};
const int dy[] = {0, 0, -1, +1, +1, +1, +2, +2};
 
int const N = 1e5 + 5;
int const M = 1e8;
 
vector<int> g[N];
int used[N];
 
void go (int x, int cur) {
	used[x] = cur;
	for (int to : g[x]) {
	 	if (used[to] == used[x]) {
	 		cout << "IMPOSSIBLE", exit(0);
	 	}
	 	if (used[to] == 0)
	 		go(to, (cur == 2 ? 1 : 2));
	}
}
 
int main() {                 
#ifdef Mask                                                         
  freopen(".in", 	"r", stdin);
  freopen(".out", "w", stdout);  
#endif
	ios_base :: sync_with_stdio(false);               
  cin.tie(nullptr);
  srand(time(nullptr));
  int n, m;
  cin >> n >> m;
  vector<int> ans;
  for (int i = 1; i <= n; i++)
  	used[i] = 0;
  for (int i = 1; i <= m; i++) {
  	int x, y;
  	cin >> x >> y;
  	g[x].pb(y);
  	g[y].pb(x);
  }
  for (int i = 1; i <= n; i++) {
   	if (used[i] == 0) {
   	 	go(i, 1);
   	}
  }
  for (int i = 1; i <= n; i++)
  	cout << used[i] << " ";
 	return 0;
}
