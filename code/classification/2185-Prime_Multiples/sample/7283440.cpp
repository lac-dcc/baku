#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <numeric>
#define int long long int
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
#define ull unsigned long long
#define lld long double
#define mp make_pair
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define vi vector<int>
#define usi unordered_set<int>
#define si set<int>
#define msi multiset<int>
#define mss multiset<string>
#define mii map<int,int>
#define umii unordered_map<int,int>
#define vpii vector<pii>
#define spii set<pii>
#define F first
#define I insert
#define S second
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
#define eb emplace_back
#define bg(x) begin(x)
#define ftl(x) bg(x), end(x)
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl
#else
#define debug(x)
#endif
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
const int md = 1000000007;
#define Shivam_Saurabh_18ss ios::sync_with_stdio(0);cin.tie(0)
int32_t main() {
   Shivam_Saurabh_18ss;
#ifndef ONLINE_JUDGE
   freopen("debug.txt", "w", stderr);
   freopen("input.txt", "r" , stdin);
   freopen("output.txt", "w", stdout);
#endif
   int ttt = 1;
   //cin>>ttt;
   for (int iii = 0; iii < ttt; iii++)
   {
      int n, k;
      cin >> n >> k;
      vi v;
      for (int i = 0; i < k; i++)
      {
         int x; cin >> x;
         v.eb(x);
      }
      int sum = 0;
      for (int i = 0; i < (1 << k); i++)
      {
         int x = n;
         int nop = 0;
         for (int j = 0; j < k; j++)
         {
            if ((i >> j) & 1 == 1)
            {
               x /= v[j];
               nop++;
            }
         }
         if (nop == 0)
         {
 
         }
         else if (nop % 2 == 0)
            sum -= x;
         else
            sum += x;
      }
      cout << sum << endl;
   }
}