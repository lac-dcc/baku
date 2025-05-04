#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define rep(i,s,e) for(int i=s;i<e;++i)
using namespace std;
 
const int N=2e5;
ll n,x,prv=0,ans=LLONG_MIN;
 
int main(void){
  fastio;
  cin>>n;
  rep(i,0,n){
    cin>>x;
    prv=max(prv+x,x);
    ans=max(ans,prv);
  }
  cout<<ans<<endl;
  return 0;
}
