#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef   long long int ll;
typedef unsigned long long int sll;
typedef  long double ld;
typedef tree <int,null_type,less <int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
#define rep(g, i, n) for (ll g = i; g < n; g++)
#define rev(g, n, i) for (ll g = n - 1; g >= i; g--)
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) v.begin(), v.end()
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
 
#define um unordered_multiset
#define us unordered_set
#define mxe(v) *max_element(v.begin(),v.end())
#define mne(v) *min_element(v.begin(),v.end())
#define bs binary_search
#define lb lower_bound
#define ub upper_bound
#define ve vector
#define br break
#define rem 500009
#define PI 3.1415926535
#define INF 1000000000000 
struct dataa{
                       ll sum,ans,pre,suf;
};
ll n,m=1e17,k=0,r=0,z;
queue<ll> q;
bool b=false;
ll A=1000000007  ;
ve<pair<ll,ll> > adj[200005];
ve<ll> seg(800005);
ve<ve<ll>> dis(505,ve<ll>(505,1e17));
 
long long power(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
 
/* 
void djk()
{
   set<pair<ll,ll>>s;
   s.insert({0,1});
   dis[1]=0;
   
   
   while(!s.empty())
   {
       pair<ll,ll> p=*s.begin();
        s.erase(s.begin());
       ll x=p.first;
       ll y=p.second;
       for(auto i:adj[y])
       {
         if(dis[i.first]>dis[y]+i.second)
         {  s.erase({dis[i.first],i.first});
           dis[i.first]=dis[y]+i.second;
           s.insert({dis[i.first],i.first});
           
         }
       }
       
   }
                       
}
*/
 
  
 
void solve()
{ll q;
cin>>n>>m>>q;
       rep(i,0,m)
       {ll a,b,c;cin>>a>>b>>c;
            dis[a][b]=min(dis[a][b],c);
            dis[b][a]=min(dis[b][a],c);
       }
       rep(i,1,n+1)dis[i][i]=0;
       rep(k,1,n+1)
       {
           rep(i,1,n+1)
           {
             rep(j,1,n+1)
             {
               dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);                     
             }
           }
       }
       rep(i,0,q)
       {
                              ll x,y;cin>>x>>y;
                              if(dis[x][y]==1e17)
                              {cout<<-1<<endl;}
                              else
                              {
                                cout<<dis[x][y]<<endl;                     
                              }
       }
      
}
 
 
                       
 
 
int main()
{ FAST;
 
    ll t=1;
  ////cin>>t;
    rep(l,0,t)
    {
        solve();                   
    }
}
