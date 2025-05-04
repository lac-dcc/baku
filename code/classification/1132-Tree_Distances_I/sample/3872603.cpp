#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define ld long  double
#define pi pair<int ,int>
#define pl pair<ll ,ll>
#define vi vector<int>
#define vl vector<ll>
#define vp vector<pi >
#define vd vector<double>
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define pb push_back
#define fl(i,l,n) for(int i =l ; i < n ; i ++)
 
void read(vector<int> &v,int n) {for(int i=0;i<n;i++) cin>>v[i];}
void readl(vector<ll> &v,ll n) {for(ll i=0;i<n;i++) cin>>v[i];}
 
bool is_sorted(vector<ll>& arr){
    int n = arr.size() ;
    for(int i=0; i<n-1; i++){
        if(arr[i]>arr[i+1])
          return false ;
    }
    return true ;
}
 
/*
 
void solve(int src , int par , vector<vector<int>>& adj){
  dp[src][0] = 0;
  dp[src][1] = 0;
  bool leaf = true;
  for(auto i : adj[src]){
    if(i==par)
      continue ;
    leaf = false;
    solve(i,src , adj);
  }
  if(leaf){
    return ;
  }
  vector<int> pre;
  vector<int> suff;
  for(int ch : adj[src]){
    if(ch==par)continue;
      int temp = max(dp[ch][0] , dp[ch][1]) ;
      pre.push_back(temp);
      suff.push_back(temp);
  }
 
  for(int i=1 ; i<pre.size();i++){
    pre[i] += pre[i-1] ;
  }
 
  for(int i=suff.size()-2; i>=0;i--){
    suff[i] += suff[i+1];
  }
 
 
  dp[src][0] = suff[0] ;
  int cnt = 0;
  for(int i=0 ; i<adj[src].size();i++){
    int ch = adj[src][i] ;
    if(ch==par)
      continue;
    if(suff.size()==1){
      dp[src][1] = 1 + dp[ch][0] ; 
    }
    else if(cnt==0){
      dp[src][1] = max(dp[src][1] , 1 + dp[ch][0] + suff[1]);
    }
    else if(cnt==pre.size()-1){
      dp[src][1] = max(dp[src][1] , 1 + pre[cnt-1] + dp[ch][0] );
    }
    else
      dp[src][1] = max(dp[src][1] , 1 + pre[cnt-1] + suff[cnt+1] + dp[ch][0]) ;
    cnt++ ;
  }
}
*/
/*
int dia[200001] ;
int down[200001] ;
 
void help(int src , int par , vector<vector<int>>& adj){
  bool leaf = true ;
  dia[src] = 0 ;
  down[src] = 0 ;
 
  for(auto i : adj[src]){
    if(i==par) continue;
    leaf = false;
    help(i , src , adj) ;
  }
 
  if(leaf) return ;
 
  vector<int> downchild ;
  for(auto i : adj[src]){
    if(i==par) continue ;
    downchild.push_back(down[i]) ;
  }
  sort(downchild.begin() , downchild.end());
  int nchild = downchild.size() ;
  down[src] = 1 + downchild[nchild-1] ;
 
  int ans = 0;
 
  for(auto i  : adj[src]){
    if(i==par) continue ;
    ans = max(ans , dia[i]) ;
  }
 
  int ans2  = 0;
 
  if(nchild==1){
    ans2 = 1 + downchild[0] ;
 
  }
  else{
    ans2 = 2 + downchild[nchild-1] + downchild[nchild-2] ;
  }
 
  dia[src] = max(ans,ans2) ;
}
*/
int n ;
void bfs(int i , vector<int>& ans , vector<vector<int>>& adj){
  vector<int> dx(n+1);
  vector<int> dy(n+1);
   queue<int> q ;
   vector<bool> vis(n+1 , false);
  int x ,y ;
  q.push(1);
  x = 1;
  while(!q.empty()){
    int len = q.size() ;
    for(int i=0;i<len ; i++){
       int t = q.front();
       q.pop() ;
       vis[t] = true ;
       for(int child : adj[t]){
          if(vis[child]) continue;
            x = child;
            q.push(x) ;
        }
    }
  }
    //cout<<x<<" "<<y<<endl ;
 
  for(int i=1;i<=n;i++) vis[i] = false;
  while(!q.empty() ) q.pop();
 
  q.push(x);
  while(!q.empty()){
    int len = q.size() ;
    for(int i=0;i<len ; i++){
       int t = q.front();
       q.pop() ;
       vis[t] = true ;
       for(int child : adj[t]){
          if(vis[child]) continue;
            y = child;
            q.push(child) ;
        }
    }
  }
 
  for(int i=1;i<=n;i++) vis[i] = false;
  while(!q.empty() ) q.pop();
 
  //cout<<x<<" "<<y<<endl ;
 
 
 
  int cnt = 0 ;
  q.push(x) ;
 
   while(!q.empty()){
    int len = q.size() ;
 
    for(int i=0;i<len ; i++){
       int t = q.front();
       dx[t] = cnt ;
       q.pop() ;
       vis[t] = true ;
       for(int child : adj[t]){
          if(vis[child]) continue;
            q.push(child) ;
        }
    }
 
    cnt++ ;
  }
 
  for(int i=1;i<=n;i++) vis[i] = false;
  while(!q.empty() ) q.pop();
 
 
 
 cnt = 0 ;
  q.push(y) ;
   while(!q.empty()){
    int len = q.size() ;
 
    for(int i=0;i<len ; i++){
       int t = q.front();
       dy[t] = cnt ;
       q.pop() ;
       vis[t] = true ;
       for(int child : adj[t]){
          if(vis[child]) continue;
            q.push(child) ;
        }
    }
    cnt++ ;
  }
  for(int i=1 ; i<=n ; i++) ans[i] = max(dx[i] , dy[i]) ;
 
}
 
void solve(){
  cin>>n;
  if(n==1){
    cout<<0<<endl ;
    return ;
  }
  vector<vector<int>> adj(n+1) ;
  int a,b;
  for(int i=1;i<n;i++){
    cin>>a>>b; 
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vector<int> ans(n+1) ;
 // vector<int> dx(n+1) ;
  // vector<int> dy(n+1) ;
  bfs(1 , ans , adj) ;
  for(int i=1;i<=n;i++){
    cout<<ans[i]<<" ";
  }
  cout<<endl ;
  return ;
}
 
 
int main(){
int n=1;//cin>>n;
while(n--)
  solve() ;
return 0 ;
}
