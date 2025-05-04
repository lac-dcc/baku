//1008
#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
   
#define int long long
using namespace std;
using namespace __gnu_cxx;
int M=1e9+7;
 
void dfs(int i,vector<vector<int>> &v,vector<int> &visited,stack<int> &st){
   visited[i]=1;
   for(int x:v[i]){
      if(!visited[x])dfs(x,v,visited,st);
   }
   st.push(i);
   return ;
}
 
void dfs1(int i,int k,vector<vector<int>> &v,vector<int> &visited){
   visited[i]=k;
   for(int x:v[i]){
      if(!visited[x])dfs1(x,k,v,visited);
   }
   
   return ;
}
 
void solve(int itiii,int test){
int n,m;cin>>n>>m;
 
vector<vector<int>> v(m,vector<int>(3));
for(int i=0;i<m;i++){
   int x,y,z;cin>>x>>y>>z;
   v[i]={--x,--y,z};
}
vector<int> dist(n,1e18),par(n,-1);
int a=-1;
 
dist[0]=0;
for(int i=0;i<=n;i++){
   for(auto x:v){
      
      if(dist[x[1]]>dist[x[0]]+x[2]){
      par[x[1]]=x[0];
      dist[x[1]]=dist[x[0]]+x[2];
      if(i==n){
a=x[0];
 
      }
      }
   }
}
if(a==-1){
   cout<<"NO";return ;
}
for(int i=0;i<n;i++){
   a=par[a];}
vector<int> ans;
int p=a;
ans.push_back(a);
a=par[a];
while(a!=p){
   ans.push_back(a);
   a=par[a];
}
ans.push_back(p);
cout<<"YES\n";
reverse(ans.begin(),ans.end());
for(int x:ans)cout<<x+1<<" ";
}
 
 
int32_t main(){
 ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //     freopen("inputh.txt","r",stdin);
    // freopen("output.txt","w",stdout);
int test;
 test=1;
// cin>>test;
 
 
 
 for(int i=0;i<test;i++){
//   cout<<"Case #"<<i+1<<":"<<" ";
 solve(i,test);
cout<<"\n";
}
   return 0;
}
