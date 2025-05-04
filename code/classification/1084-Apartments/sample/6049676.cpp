#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
   ll n,m,k;
   cin>>n>>m>>k;
   vector<ll> desired(n),available(m);
   for(int i=0;i<n;i++){cin>>desired[i];}
   for(int i=0;i<m;i++){cin>>available[i];}
   sort(desired.begin(),desired.end());
   sort(available.begin(),available.end());
   ll i=0,j=0,ans=0;
   while(i<n && j<m){
        if(abs(desired[i]-available[j])<=k){
         ans++;i++;j++;
        }
        else{
         if(available[j]<desired[i]-k){j++;}
         else if(available[j]>desired[i]+k){i++;};
        }
   }
   cout<<ans<<endl;
}
