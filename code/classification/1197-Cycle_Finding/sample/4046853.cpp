#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#ifdef _LOCAL_
   #include "debug.h"
#else
   #define clog if (0) cerr
   #define DB(...)
   #define db(...) 0
#endif
using namespace std;
#define int long long
#define ll long long
 
const int N=2505;
vector<pair<int,int>> adj[N];
int dp[N],par[N];
int start=-1;
 
void solve(){
   int n,m;cin>>n>>m;
   vector<tuple<int,int,int>> edges;
   for(int i=1;i<=m;i++){
      int x,y,w;cin>>x>>y>>w;
      edges.push_back({x,y,w});
   }
   memset(dp,64,sizeof dp);
   dp[1]=0;
   const int free_fire=n+1;
   for(int ff=1;ff<=free_fire;ff++){
      start=-1;
      for(auto _:edges){
         int x,y,w;tie(x,y,w)=_;
         if(dp[x]+w<dp[y]){
            dp[y]=dp[x]+w;
            par[y]=x;
            start=y;
         }
      }
   }
   if(start==-1)cout<<"NO";
   else{
      cout<<"YES\n";
      for(int i=1;i<=n;i++)
         start=par[start];
      vector<int> ans={start};
      int cur=par[start];
      while(true){
//         clog<<cur<<'\n';
         ans.push_back(cur);
         if(cur==start)break;
         cur=par[cur];
      }
      reverse(ans.begin(),ans.end());
      for(int x:ans)cout<<x<<' ';
   }
}
 
int32_t main(){
   cin.tie(0)->ios::sync_with_stdio(0);
 
   #ifdef _LOCAL_
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
      freopen(".log","w",stderr);
   #endif
 
   int tt=1;
   //cin>>tt;
   while(tt--){
      solve();
   }
 
   return 0;
}
