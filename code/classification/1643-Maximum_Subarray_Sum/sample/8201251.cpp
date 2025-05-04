#include <bits/stdc++.h>
using namespace std;
#define int long long int 
#define rep(i,k,n) for(int i=k;i<n;i++)
#define drep(i,k,n) for(int i=k;i>=n;i--)
#define in(v)  for(int i=0;i<v.size();i++)cin>>v[i];
#define op(v) for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
#define pb push_back
#define vi vector <int>
#define pi pair< vector<int,int> >
#define ub upper_bound
#define lb lower_bound
#define int long long int
#define ff first
#define ss second
#define s(A) sort(A.begin(),A.end());
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
//.................................. SOLUTION STARTS HERE ..............................
 
// bool p(int x){
//   for(int i=2;i*i<=x;i++){
//     if(x%i==0){
//       return false;
//     }
//   }  
//   return true;
// }
 
// int gcd(int a, int b) { 
//     if (b == 0) { 
//         return a; 
//     } 
//     return gcd(b, a % b); 
// }
// int lcm(int a,int b){
//   return a*b/gcd(a,b);
// }
 
 
 
 
 	
 
 
 
 
 
void solve(){
  int n; cin>>n;
  int sum=0;
  int mx=0;
  vi v(n);in(v);
  rep(i,0,n){
   sum+=v[i];
   if(sum<0)sum=0;
   else{
   	mx=max(mx,sum);
   }
  }
  if(mx==0){
  	if(find(v.begin(),v.end(),0) !=v.end()){
  		cout<<0<<endl;
  	}
  	else{
  		cout<<*max_element(v.begin(),v.end())<<endl;
  	}
 
  }
  else cout<<mx<<endl;
}
 
 
 
 
   
 
 
   
 
int32_t main() {
  fast
  // int t; cin>>t;
  // while(t--)solve();
  solve();
  return 0;
}