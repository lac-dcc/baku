#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i,e) for(ll i = 0; i < e; i++)
#define all(x) x.begin(),x.end()
typedef vector<ll> vi;
typedef unordered_set<ll> si;
 
ll sol(){
 ll n,m,k;cin>>n>>m>>k;
 
 vi kdr(n);
 rep(i,n)cin>>kdr[i];
 
 sort(all(kdr));
 
 vi apr(m);
 rep(i,m)cin>>apr[i];
 sort(all(apr));
 
 ll i=0;ll j=0;ll ans=0;
 
 while(i<n && j<m){
  while(kdr[i]<apr[j]-k && i<n)i++;
 
 
if(i<n){
  if(kdr[i]>=apr[j]-k && kdr[i]<=apr[j]+k){
     ans++;i++;
  }
}
  
  j++;
 }
 
return ans;
 
 
 
}
 
int main(){
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 cout.tie(NULL);
cout<<sol();  
return 0;
}
