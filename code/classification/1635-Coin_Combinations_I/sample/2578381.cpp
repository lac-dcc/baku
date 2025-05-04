// I don't know what im doing
// na ho paega humse
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
#define int long long
#define PB push_back
#define all(x) (x).begin(),(x).end()
#define MP make_pair
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
 
#define FOR(i,a,b) for(int i=a; i<b; i++)
 
const int modn = 1e9 + 7;
 
void solve(){
 
  int n,x; cin>>n>>x;
  vector<int> coins(n);
 
  FOR(i,0,n) cin>>coins[i];
 
  // int dp[n+1][x+1];
  //
  // FOR(i,0,n+1){
  //   FOR(j,0,x+1){
  //     dp[i][j] = 0;
  //   }
  // }
  //
  // FOR(i,0,x+1){
  //   dp[0][i] = 0;
  // }
  //
  // FOR(i,0,n+1){
  //   dp[i][0] = 1;
  // }
  //
  //
  //
  // FOR(i,1,n+1){
  //   FOR(j,1,x+1){
  //     dp[i][j] = dp[i-1][j];
  //     if(j>=coins[i-1]){
  //       dp[i][j] += dp[i][j-coins[i-1]];
  //       // dp[i][j] += dp[i-1][j-coins[i-1]];
  //     }
  //   }
  // }
 
  // FOR(i,0,n+1){
  //   FOR(j,0,x+1){
  //     // dp[i][j] = 0;
  //     cout<<dp[i][j]<<" ";
  //   }
  //   cout<<'\n';
  // }
  //
  // cout<<dp[n][x]<<'\n';
 
  vector<int> dp(x+1);
  dp[0] = 1;
 
  FOR(i,1,x+1){
    FOR(j,0,n){
      if(i>=coins[j]){
        dp[i] += dp[i-coins[j]];
        dp[i] = dp[i]%modn;
      }
    }
  }
 
  cout<<dp[x]<<'\n';
 
 
}
 
signed main(){
 
  #ifndef ONLINE_JUDGE
  freopen("inputfa.txt", "r", stdin);
  freopen("outputfa.txt", "w", stdout);
  freopen("error.txt","w",stderr);
  #endif
 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  auto start = chrono::high_resolution_clock::now();
 
  int t=1;
  // cin>>t;
  while(t--){
    solve();
  }
 
  auto end = chrono::high_resolution_clock::now();
  double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
 
  time_taken *= 1e-9;
 
  cerr <<fixed<<time_taken<<setprecision(9)<< " sec"<<endl;
  return 0;
}