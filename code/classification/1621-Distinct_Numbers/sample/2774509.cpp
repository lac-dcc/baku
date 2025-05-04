#include<bits/stdc++.h>
using namespace std;
#define ll                       long long
 
 
int main()
{
    // text     //change the name of the file
  ll n,c=0;cin>>n;
  vector<ll>arr(n);
  for(ll i=0;i<n;i++)cin>>arr[i];
  sort(arr.begin(),arr.end());
  for(ll i=0;i<n;i++)
  {
      if(arr[i]!=arr[i+1])c++;
 
  }
  cout<<c<<endl;
}