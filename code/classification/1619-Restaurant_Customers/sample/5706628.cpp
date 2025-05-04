#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
#define AQUA                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
 
const ll N = 10000000 + 5;
const ll mod = 998244353;
// int spf[N] = {0};
 
int main()
{
  AQUA
 
      ll tt = 1;
  // cin >> tt;
 
  while (tt--)
  {
    ll n;
    cin>>n;
    map<ll,ll> m;
    while(n--){
      ll a,b;
      cin>>a>>b;
      m[a]++,m[b+1]--;
    }
    ll ans=0;
    ll sum=0;
    for(auto val : m){
      sum+=val.second;
      ans=max(ans,sum);
    }
    cout<<ans<<endl;
 
 
  
  }
}
