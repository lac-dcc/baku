 
 
#include <bits/stdc++.h>
 
using namespace std;            //greater<int>() to sort in desc
typedef long long ll;
 
#define num 1000000007LL
#define num1 998244353LL
#define N 100005
#define f(i,a,b) for(int i=a;i<b;i++)
#define lb lower_bound
#define pb push_back
#ifndef ONLINE_JUDGE
#define  debug(x) cerr<<#x<<' ';cerr<<x<<' ';
#else
#define  debug(x)
#endif
vector<int>adj[N];
stack<int>path;
set<int>s;
bool vis[N];
int ans=-1;
void dfs1(int u){
    if(!vis[u]){return;}
    vis[u]=false;
    for(auto i:adj[u])dfs1(i);
}
void dfs(int u,int v=-1){
   
    if(ans>=0){return;}
    path.push(u);
    if(s.find(u)!=s.end()){ans=u;return;}
    s.insert(u);
    for(auto i:adj[u]){
        if(i==v){continue;}
        dfs(i,u);
        if(ans>=0)return;
    }
    path.pop();
}
 
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("cses.cc","w",stderr);
#endif
    
    //code here
    int n,m,val1,val2;
    vector<int>p;
    cin>>n>>m;
    f(i,0,m){
        cin>>val1>>val2;
        val1--;val2--;
        adj[val1].pb(val2);
        adj[val2].pb(val1);
    }
    f(i,0,n){
        vis[i]=true;
    }
    f(i,0,n){
        if(!vis[i])continue;
        dfs(i); dfs1(i);
        if(ans>=0){
          
            path.pop();
         
            while(path.top()!=ans){p.pb(path.top());path.pop();}
            cout<<p.size()+2<<endl;
            cout<<ans+1<<' ';
            for(auto j:p){cout<<j+1<<' ';}
            cout<<ans+1<<endl;
            return 0;
           }
        while(!path.empty()){path.pop();}s.clear();
    }
  
    cout<<"IMPOSSIBLE\n";
   //code here
 
   
   
   return 0;
}
