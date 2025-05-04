//shinzo_wo_sasageyo!!
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define int long long
#define endl "\n"
#define mod 1000000007
#define setbits(x) __builtin_popcountll(x)
//use INT_MAX as LLONG_MAX
/*points to keep in mind:->
.)make sure that you have read the ques properly
.)look for even and odd pattern
.)look for a pattern involving consecutive elements of array
.)use_repeated things from here->
-------------------------------------------------------------------------
//2D ARRAY:->
for(int i=0;i<n;i++){//beaware of indices
   for(int j=0;j<m;j++){
 
   }
}
-------------------------------------------------------------------------
//FOR DP OR ELSE
vector<vector<int>>(n+1,vector<int>(m+1,-1)) dp;memset(dp,-1,sizeof(dp));
-------------------------------------------------------------------------
//FOR FLAG->(YES/NO)
if(){
   cout<<"yes"<<endl;
}
else{
   cout<<"no"<<endl;
}
--------------------------------------------------------------------------
//PRINT VECTOR
for(int i=0;i<v.size();i++){
   cout<<v[i]<<" ";
}
--------------------------------------------------------------------------
//FOR ITERATOR
for(auto it=ans.begin();it!=ans.end();it++){
 
   }
--------------------------------------------------------------------------
 
 
 
*/
const int N=1e3+1;
//vector<vector<int>> v(N);
//vector<int> vis(N,0);
void rec(int i,int j,vector<vector<int>> &vis,vector<vector<int>> &a,int n,int m){
  //cout<<"pro"<<endl;
  //cout<<i<<" "<<j<<endl;
  vis[i][j]=1;
  int rx=i;
  int ry=j+1;
  int lx=i;
  int ly=j-1;
  int tx=i-1;
  int ty=j;
  int dx=i+1;
  int dy=j;
  if(rx>=1 and rx<=n and ry>=1 and ry<=m and (a[rx][ry]==0) and vis[rx][ry]==0 ){
    rec(rx,ry,vis,a,n,m);
  }
  if(lx>=1 and lx<=n and ly>=1 and ly<=m and (a[lx][ly]==0) and vis[lx][ly]==0 ){
    rec(lx,ly,vis,a,n,m);
  }
  if(tx>=1 and tx<=n and ty>=1 and ty<=m and (a[tx][ty]==0) and vis[tx][ty]==0 ){
    rec(tx,ty,vis,a,n,m);
  }
  if(dx>=1 and dx<=n and dy>=1 and dy<=m and (a[dx][dy]==0) and vis[dx][dy]==0){
    rec(dx,dy,vis,a,n,m);
  }
  return;
 
}
signed main()
{
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;//vertex
    int m;//edges
    cin>>n>>m;
 
 
 // --------------------making graph---------------------------------
    // for (int i = 0; i < m; ++i)
    // {
    //   int x,y;
    //   cin>>x>>y;
    //   v[x].push_back(y);
    //   v[y].push_back(x);
    // }
  //---------------------printing graph-----------------------------------
    // for(int i=0;i<v.size();i++){
    //   vector<int> x=v[i];
    //   if(x.size()!=0){
    //     dfs(i);
 
    //   }
    // }
    //----------------------------------------------------------------
    //iterating in vis array
    //finding_connected_components
    vector<int> v(m+1,0);
    vector<vector<int>> a(n+1,v);
    vector<vector<int>> vis(n+1,v);
    //int a[n+1][m+1];
    //int vis[n+1][m+1];
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        char c;
        cin>>c;
        if(c=='#'){
          //wall
          a[i][j]=1;
        }
        else{
          a[i][j]=0;
        }
      }
    }
    int cnt=0;
   // rec(2,5,vis,a,n);
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        if(a[i][j]==0){
          if(vis[i][j]==0){
            //cout<<"go"<<endl;
            cnt++;
            rec(i,j,vis,a,n,m);
          }
 
        }
      }
    }
    cout<<cnt<<endl;
 
 
 
 
    return 0;
}
