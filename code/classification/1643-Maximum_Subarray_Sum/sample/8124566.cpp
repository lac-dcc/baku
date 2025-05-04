#include <bits/stdc++.h>
using namespace std;
 
const int M=1e9+7;
 
#define rep(i,a,b) for(int i = a; i < b; i++)
#define fr(a,b) for(int i = a; i < b; i++)
#define all(x) (x).begin(),(x).end()
#define ll long long int
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int n;cin>>n;
  ll a[n],ans=LLONG_MIN,cur=0;
  fr(0,n){
    cin>>a[i];
    if(a[i]<0) ans=max(ans,a[i]);
  }
  for(int i=0;i<n;i++){
    cur+=a[i];
    ans=max(ans,max(a[i],cur));
    if(cur<0) cur=0;
  }
  cout<<ans;
 
  return 0;
}