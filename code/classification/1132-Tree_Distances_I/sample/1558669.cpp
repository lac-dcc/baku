    #include<bits/stdc++.h>
 #include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 using namespace std;
 using namespace __gnu_pbds;
 #define li long long long 
 #define ll long long 
 #define ld long double 
 #define pll pair<ll,ll>
 #define pii pair<long long ,long long >
 #define  pb push_back
 #define vlp vector<pair<ll,ll>>
 # define vll vector<ll>
 #define rep(i,a,b) for(long long  i=a; i<=b; i++)
 #define all(x) x.begin(),x.end()
 typedef tree<long long , null_type, less_equal<long long >, rb_tree_tag, tree_order_statistics_node_update> indexed_build;
 
const long long  mod =1e9+7;
#define N 200001
 
 ll n;
 ll dis[N];
 ll ans[N];
 vector<ll>adj[N];
void dfs( ll cur, ll pre){
  for(int i:adj[cur]){
    if(i!=pre){
      dis[i]=dis[cur]+1;
        dfs(i,cur);
    }
  }
}
 
void dfs(int cur) {
    memset(dis, 0 , sizeof(dis));
    dfs(cur,-1);
}
 
void tree_dia(){
  dfs(1);
 
  int best=0; rep(i ,1, n)if(dis[i]>dis[best])best=i;
  dfs(best);rep(i, 1, n)ans[i]=dis[i];
  rep(i , 1, n)if(dis[i]>dis[best])best=i;
  dfs(best); 
  rep(i, 1, n)ans[i]=max(ans[i],dis[i]);
  
   rep(i ,1, n)cout<<ans[i]<<" ";
   
}
  
  
int  main()
{ 
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   
   cin>>n;
   rep(i ,1, n-1){
     ll a,b;
     cin>>a>>b;
     adj[a].pb(b);
     adj[b].pb(a);
   }
 
 
  tree_dia();
 
   return 0;
}
        
