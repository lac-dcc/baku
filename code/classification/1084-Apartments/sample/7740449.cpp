#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
ll mod=1e9+7;
 
ll power(ll base,ll expo){
    ll result=1;
    base=base%mod;
    while(expo){
        if(expo%2==1){
            result=(result*base)%mod;
        }
        base=(base*base)%mod;
        expo/=2;
    }
    return result;
}
 
 
int main()
{
   IOS;
   int t=1;
   //cin>>t;
   while(t--){
      ll n,m,k;
      cin>>n>>m>>k;
      vector<ll> v;
      for(int i=0;i<n;i++){
          int x;
          cin>>x;
          v.push_back(x);
      }
      vector<ll> v1;
      for(int i=0;i<m;++i){
          int y;
          cin>>y;
          v1.push_back(y);
      }
      sort(v.begin(),v.end());
      sort(v1.begin(),v1.end());
      ll a=0,b=0;
      ll ans=0;
      while(a<n && b<m){
          if(abs(v[a]-v1[b])<=k){
              ans++;
              a++;
              b++;
          }
          else{
              if(v[a]<v1[b]) ++a;
              else ++b;
          }
      }
      cout<<ans<<endl;
     }
   return 0;
}
