#include<bits/stdc++.h>
#include<queue>
using namespace std;
 
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
#define mod 1000000007
#define endl '\n'
const int N = 1e5 + 1;
int cnt=0;
const int inf = 1e17;
const int ninf = -1e17;
 
 
void solve() {
    
 
  struct A
  {
   int u;
   int v;
   int c;   
  };
 int n,m;cin>>n>>m;
 vector<A>adj;
 for(int i=0;i<m;i++){
    int u,v,c;cin>>u>>v>>c;
    adj.push_back({u,v,c});
 }
 vector<int>dis(n+1,inf);
 vector<int>par(n+1,0);
 dis[1]=0;
 int st=-1;
 for(int i=1;i<=n;i++){
      st=-1;
      for(auto ii:adj){
        int u=ii.u;
        int v=ii.v;
        int c=ii.c;
        if(dis[v]>dis[u]+c){
            dis[v]=dis[u]+c;
            par[v]=u;
            st=v;
        }
      }
 }
 
 if(st==-1)cout<<"NO"<<endl;
 else {
    // this one giving wrong answer
    // int cnt=0;
    // cout<<"YES"<<endl;
    // vector<int>res;
    // res.push_back(st);
    // int x=par[st];
    // while(x!=st){
    //     cnt++;
    //     if(cnt>10)break;
    //     res.push_back(x);
    //     x=par[x];
    // }
 
    //so to confirm that we are on the node from where cycle started we have to traceback n times
 
   
    for(int i=1;i<=n;i++)st=par[st];
 
    cout<<"YES"<<endl;
    vector<int>res;
    for(int i=st;;i=par[i]){
         res.push_back(i);
         if(res.size()>1&&i==st)break;
    }
    reverse(res.begin(),res.end());
    for(auto v:res)cout<<v<<" ";cout<<endl;
 
 
 }
 
}
 
 
 
 
int32_t main() {
    
  fast;
#ifndef ONLINE_JUDGE
  freopen("Input.txt", "r", stdin);
  freopen("Output.txt", "w", stdout);
#endif
 
   int t = 1;
 
   // cin >> t;
   while (t--)solve();
   return 0;
}
