#include<bits/stdc++.h>
using namespace std;
 
#define infL                LLONG_MAX
#define infI                INT_MAX
#define leadzero            __builtin_clz           // count the leading zeros of the integer
#define trailzero           __builtin_ctz           // count the trailing zeros of the given integer
#define numone              __builtin_popcount
#define ll                  long long
#define yes                 cout << "YES\n"
#define no                  cout << "NO\n"
#define endl                "\n"
#define MX                  10000+10
#define sp                  " "
#define pb                  push_back
#define eb                  emplace_back
#define mp                  make_pair
#define all(v)              (v).begin(),(v).end()
#define rall(v)             (v).rbegin(),(v).rend()
#define modu                1000000007
#define ff                  first
#define ss                  second
 
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
 
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll n, m;
    cin >> n >> m;
    vector<ll> arr(n), ind(n);
    for(auto &x : arr) cin >> x;
    iota(ind.begin(), ind.end(), 0);
    sort(ind.begin(), ind.end(), [&](int x, int y) { return arr[x] < arr[y]; });
    sort(all(arr));
    for(int i = 0; i < n - 3; i++){
      for(int j = i + 1; j < n - 2; j++){
        if(arr[i] + arr[j] >= m) break;
        ll other = m - arr[i] - arr[j];
        for(int l = j + 1, r = n - 1; l < r; ){
          if(arr[l] + arr[r] > other) r--;
          else if(arr[l] + arr[r] < other) l++;
          else{
            return cout << ind[i] + 1 << ' ' << ind[j] + 1 << ' ' << ind[l] + 1 << ' ' << ind[r] + 1, 0;
          }
        }
      }
    }
    return cout << "IMPOSSIBLE", 0;
}
