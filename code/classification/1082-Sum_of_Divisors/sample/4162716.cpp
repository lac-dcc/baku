#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
void test_case() 
{ 
 
  long long n ;
  cin >> n;
  long long ans=0;
  for(long long i = 1,j;i <= n;i=j){
    long long q = n/i;
    j = n/q + 1;
    long long x = j-i;
    long long y = i + j - 1;
    if(x & 1){
      y/=2;
    }
    else x/=2;
    x%=mod;y%=mod;
    ans = (ans%mod + (q%mod * x%mod * y%mod)%mod)%mod;
 
 
  }
  cout << ans << endl;
 
 
 
  
  
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif
    // int t ;
    // cin >> t;
    // while(t--){
    //   test_case();
    // }
    test_case();
   // cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}
