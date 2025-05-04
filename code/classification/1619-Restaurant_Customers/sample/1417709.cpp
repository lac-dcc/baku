#pragma GCC optimization ("O2")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   map<int,int>arr;
   int n;
   cin>>n;
   vector<int>brr;
   for (int i =0;i<n;++i){
       int a,b;
       cin>>a>>b;
       if (arr.find(a)==arr.end()){
           arr.insert(make_pair(a,1));
           brr.push_back(a);
       }
      else arr[a]++;
       if (arr.find(b)==arr.end()){
           arr.insert(make_pair(b,-1));
           brr.push_back(b);
       }
       else arr[b]--;
   }
   sort(brr.begin(),brr.end());
   int counts=0;
   int maxxy=0;
   for (auto x:brr){
       counts+=arr[x];
       maxxy=max(maxxy,counts);
   }
   maxxy=max(counts,maxxy);
    cout<<maxxy;
    
}
