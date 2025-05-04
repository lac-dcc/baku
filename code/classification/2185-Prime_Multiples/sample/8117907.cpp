#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
#define debug(i,n) cout<<"case# "<<i<<" : "<<n<<" "
const int mod=1e9+7;
 
void solve() {
   int N,m;
   cin>>N>>m;
   vector<int>v(m);
   for(int i=0;i<m;i++){
     cin>>v[i];
   }
   
   vector<int>ans(m+1);
   for(int i=1;i<(1<<m);i++){
    int temp=N;
    int count=0;
    
    for(int j=0;j<m;j++){
      if((1<<j)&i){
        count++;
        temp/=(v[j]);
      }
    }
    ans[count]+=temp;
   }
   int res=0;
   for(int i=1;i<=m;i++){
    if(i&1){
        res+=ans[i];
    }
    else{
        res-=ans[i];
    }
   }
   cout<<res;
}
 
int32_t main() {
   
    solve();
    cout<<endl;
    return 0;
}