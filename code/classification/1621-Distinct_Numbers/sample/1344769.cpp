#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main()
{
  ll n,a;
  cin>>n;
  set<ll> s;
  for(int i=1;i<=n;i++)
  {
    cin>>a;
    s.insert(a);
  }
  cout<<s.size()<<endl;
  
  return 0;
}
