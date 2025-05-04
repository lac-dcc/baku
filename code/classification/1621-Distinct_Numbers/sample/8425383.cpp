//Saifur Rahman
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
#define pb push_back
#define TT int t;cin>>t; for(int tt=1;tt<=t;tt++)
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
void balchal(){
  int n;
  cin>>n;
  int a[n];
  set<int>s;
  for(int i=0;i<n;i++){
      cin>>a[i];
      s.insert(a[i]);
  }
  cout<<s.size()<<"\n";
  
    
}
int main(){
     balchal();
        
}
