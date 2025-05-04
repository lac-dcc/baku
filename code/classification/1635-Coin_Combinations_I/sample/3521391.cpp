#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
int main()
{
  
      ll n,x;
      cin>>n>>x;
      ll a[n];
      for(ll i=0;i<n;i++)
      cin>>a[i];
      sort(a,a+n);
      //ll d[x+1]={0};
      vector<ll> d(x + 1, 0); 
      d[0]=1;
      ll m=1e9+7;
      for(ll i=a[0];i<x+1;i++){
          for(ll j=0;j<n;j++)
          {
              if(a[j]>i)
              break;
              else
              d[i]=((d[i]%m)+(d[i-a[j]]%m))%m;
          }
      }
      cout<<d[x]<<"\n";
   
 
    return 0;
}
 
