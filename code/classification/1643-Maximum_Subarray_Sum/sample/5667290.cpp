#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define f(n) for(long long i=0;i<n;i++)
#define NahlaHesham  ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
using namespace std;
 
int main() {
   NahlaHesham
   int n;cin>>n;
   ll arr[n];
   f(n)
   {
       cin>>arr[i];
   }
   ll i=0,j=0,sum=0;
   ll maxx=INT_MIN;
 
   while(i<n &&j<n)
   {
      if(arr[j]+sum>=arr[j])
      {
          sum+=arr[j];
          maxx=max(maxx,sum);
          j++;
      }
      else if(arr[j]+sum<arr[j])
      {
          sum=arr[j];
          maxx=max(maxx,sum);
          i++;j++;
      }
   }
   cout<<maxx<<endl;
}