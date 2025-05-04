    #include<bits/stdc++.h>
 #include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 using namespace std;
 using namespace __gnu_pbds;
 #define li long long long 
 #define ll long long 
 #define ld long double 
 #define pll pair<ll,ll>
 #define mp make_pair
 #define pii pair<long long ,long long >
 #define  pb push_back
 #define vlp vector<pair<ll,ll>>
 # define vll vector<ll>
 #define rep(i,a,b) for(long long  i=a; i<=b; i++)
 #define all(x) x.begin(),x.end()
 #define f first
 #define s second
 
 typedef tree<long long , null_type, less_equal<long long >, rb_tree_tag, tree_order_statistics_node_update> indexed_build;
 
const long long  mod =1e9+7;
#define N 200002
 
ll n,m,var;
ll dis[N];
vector<ll>v1,v2,fav,notfav,boss;
vector<char>c;
 
vector<ll>adj[N];
bool vis[N];
bool tag[N];
bool tagg,check;
vector<ll>path;
ll point;
 
void dfs(ll a , ll par ){
    
     
    vis[a]=true; 
    path.pb(a);
  
   for(int x:adj[a]){
     if(par==x)continue;
      if(vis[x]){  
        {
       path.pb(x);
       int pos=(find(all(path),x)-path.begin());
           cout<<path.size()-pos<<" \n";
           while(pos<path.size()){
             cout<<path[pos++]<<" ";
            
           }
            exit(0);
            
        }}
        else dfs(x,a);
       
     }
     path.pop_back();
   }
 
 
int  main()
{ 
 
 
   ios_base::sync_with_stdio(false);
   cin.tie(0);
 
   cin>>n>>m;
    ll a,b;
   rep(i , 1 , m){
     cin>>a>>b;
     adj[a].pb(b);
     adj[b].pb(a);
   }
    
  
 
    for(ll i=1; i<=n; i++){
       
         if(vis[i]==false)dfs(i, 0);}
        
    cout<<"IMPOSSIBLE\n";
 
 return 0;
 
  }
 
 
 
     
 
 
   
 
 
 
 
 
    
