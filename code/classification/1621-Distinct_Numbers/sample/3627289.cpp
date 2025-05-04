#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
   int n;
   cin>>n;
   vector<int>A(n);
   for(int i=0;i<n;i++){
       cin>>A[i];
   }
   sort(A.begin(),A.end());
   int cnt=0;
   for(int i=0;i<n;i++){
       int j=i;
       while(j<n && A[j]==A[i]){
           j++;
       }
       cnt++;
       i=j-1;
   }
   cout<<cnt<<"\n";
   return 0;
}