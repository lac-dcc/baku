#include<bits/stdc++.h>
using namespace std;
int main(){
   long long n,x; cin>>n>>x;
   pair<long long,long long> a[n+4];
   for(long long i=1;i<=n;i++) {
       cin>>a[i].first;
       a[i].second=i;
   }
   sort(a+1,a+n+1);
 
   long long cnt=0;
   for(long long i=1;i<=n-3;i++){
       for(long long j=i+1;j<=n-2;j++){
           long long l=j+1,r=n;
           while(l<r){
 
               if(a[i].first+a[j].first+a[l].first+a[r].first<x){
                   l++;
               }
               else if(a[i].first+a[j].first+a[l].first+a[r].first>x){
                   r--;
               }
               else {
                   cnt++;
                   cout<<a[i].second<<' '<<a[j].second<<' '<<a[l].second<<' '<<a[r].second<<endl;
                   break;
               }
           }
           if(cnt!=0) break;
       }
       if(cnt!=0) break;
   }
   if(cnt==0) cout<<"IMPOSSIBLE"<<endl;
}
