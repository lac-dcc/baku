#include <bits/stdc++.h>
#define fast_input_output() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef long long ll;
using namespace std;
using namespace __gnu_pbds; 
#define int long long
int const max_n = 3000005;
int const m = 1000000007;
vector<int> a, b;
int n;
int inp[300005];
void solve( int i, ll sum ){
    if(i==n/2) { a.push_back(sum); return; }
    solve(i+1,sum+inp[i]);
    solve(i+1,sum);
}
void solve2( int i, ll sum ){
    if(i==n) { b.push_back(sum); return; }
    solve2(i+1,sum+inp[i]);
    solve2(i+1,sum);
}
signed main() {
 
      fast_input_output();
      int x, cnt = 0; cin>>n>>x;
      for(int i=0; i<n; i++) cin>>inp[i];
      solve(0,0);
      solve2(n/2,0);
      sort(a.begin(),a.end());
      sort(b.begin(),b.end());
      for(auto it:a) {
        int want = x - it;
        int ind = lower_bound(b.begin(),b.end(), want) - b.begin(); 
        int ind2 = upper_bound(b.begin(),b.end(), want) - b.begin(); 
        cnt+=ind2-ind;
      }
      cout<<cnt<<'\n';
      return 0;
}
