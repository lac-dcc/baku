#include <bits/stdc++.h>
#define ll long long int
const ll N=1e9+7;
using namespace std;
 
 
 
void solve(){
ll n,m;
cin>>n>>m;
multiset<ll>ms;
for(int i=0;i<n;i++){
ll k;
cin>>k;
ms.insert(k);
}
for(int i=0;i<m;i++){
    ll x;
    cin>>x;
    auto it=ms.upper_bound(x);
    if(it==ms.begin()){
      cout<<-1<<endl;
    }
    else{
      cout<<*(--it)<<endl;
      ms.erase(it);
    }
}
  return;
}
 
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t = 1;
  //cin >> t;
  while (t--)
    solve();
}
