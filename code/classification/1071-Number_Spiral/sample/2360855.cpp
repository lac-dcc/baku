#include<iostream>
using namespace std;
#define ll long long
int main()
{
 
 ll t;
 cin>>t;
 while(t--)
 {
     ll y,x,ans=0;
     cin>>y>>x;
     ll z=max(y,x);
      ll z2=z*z;
      if(z%2)
      {
          if(y==z)
            ans=(z-1)*(z-1)+x;
          else
            ans=z2-y+1;
      }
      else
      {
          if(y==z)
            ans=z2-x+1;
          else
            ans=(z-1)*(z-1)+y;
      }
      cout<<ans<<endl;
 }
}
