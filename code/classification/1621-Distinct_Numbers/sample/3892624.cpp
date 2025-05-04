#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
int main()
{
   ll n;
   cin>>n;
   set<ll>st;
   vector<ll>v(n);
   for(int i=0;i<n;i++)
   {
       cin>>v[i];
       st.insert(v[i]);
   }
   cout<<st.size()<<endl;
}
