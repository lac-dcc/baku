#include <bits/stdc++.h>
#include<iostream>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set> 
#include <algorithm>
 
 
#include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
 
using namespace __gnu_pbds;
using namespace std;
 
/*=============================================================================================================================*/
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define set_bits(x) __builtin_popcountll(x)
#define sz(x) ((int)(x).size())
/*=============================================================================================================================*/
typedef long long ll;
typedef pair<int, int> pii;
static int mod = 1e9 + 7;
static int mod1 = 998244353;  
// typedef tree<pair<int, int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
 
template<typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/*=============================================================================================================================*/
 
void onlineJudge() {
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout); 
  #endif
} 
 
bool isVowel(char ch) {
  return (ch=='a' || ch=='e' ||ch=='i' || ch=='o'|| ch=='u');
}
 
static bool compare(pii &a, pii &b) {
  return  a.second<b.second;
}
 
 
 
vector<int> query(int l, int r) {
  cout<<"? "<<l<<" "<<r<<endl;
  vector<int> ans;
  for(int i=l; i<=r; i++) {
    int x;
    cin>>x;
    ans.pb(x);
  }
  return ans;
} 
 
ll binexp(ll a, ll b) {
  ll res  = 1;
 
  while(b>0) {
    if(b&1) res  = (res*a)%mod;
    a = (a*a)%mod;
    b =  b >> 1;
  }
  return res;
}
 
 
bool sorted(vector<ll> &arr) {
  for(int i=1; i<sz(arr); i++) {
    if(arr[i-1]>=arr[i]) return false;
  }
  return true;
}
 
 
ll sumOfDigits(ll x) {
  ll sx = 0;
  while (x > 0) {
    sx += x % 10;
    x /= 10;
  }
  return sx;
}
 
 
bool isFeasible(vector<ll> &arr, ll mid, ll n, ll k) {
  ll subarr_count  = 0;
  ll sum = 0;
 
  for(int i=0; i<n; i++) {
    ll x = arr[i];
    if(x>mid) return false;
    if(sum+x>mid) {
      subarr_count++;
      sum = 0;
    }
    sum+=arr[i];
  }
  if(sum>0) subarr_count++;
  return subarr_count <=k;
}
 
 
 
void solve() {
  ll n, m, k, x;  
  cin>>n>>x;
  
  vector<long long int> coins(n);
  for(int i=0;i<n;i++) {
    cin>>coins[i];
  }
  
  vector<long long int> dp(x+1,0);
  for(long long int i=1;i<=x;i++) {
    dp[i]=INT_MAX;
    for(long long int j=0;j<n;j++) {
      if(i-coins[j] >= 0)
      dp[i] = min(dp[i],dp[i-coins[j]]+1);
    }
  }
  cout << (dp[x] >= INT_MAX ? -1 : dp[x]);
 
  cout << endl;
}
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  onlineJudge();
 
  int t = 1;
  // cin >> t;
  while (t--){ 
    solve();
  }
 
  return 0;
}
