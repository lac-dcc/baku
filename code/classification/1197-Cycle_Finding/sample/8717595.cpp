#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie()
#define ll long long
#define ull unsigned long long
#define pb push_back
#define endl "\n"
 #define int ll
#define F first     
#define S second
#define db double
#define ld long double
#define short unsigned short
#define pii pair<int,int>
using namespace std;
const   ll inf = 1e18,MOD=1e9+7,N=2e5+5,MN=1e9+7,lim=1e6;
ll binpow(int a,int p); 
vector<pair<int,int>>g[N];
vector<pair<int,pair<int,int>>>e(N);
void solve(){
  int n,m;
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    g[a].pb({b,c});
    e[i].F=a;
    e[i].S.F=b;
    e[i].S.S=c;
  }
  vector<int>d(n+1,inf);
  vector<int>p(n+1,-1);
  d[1]=0;
  int x;
  for(int i=0;i<n;i++){  
    x=-1;
    for(int j=0;j<m;j++){
      if(d[e[j].S.F]>d[e[j].F]+e[j].S.S){
        d[e[j].S.F]=d[e[j].F]+e[j].S.S;
        p[e[j].S.F]=e[j].F;
        x=e[j].S.F;
      }
    }
  }
  if(x==-1){
    cout<<"NO"<<endl;
  }
  else{
    cout<<"YES"<<endl;
    int y=x;
    for(int i=0;i<n;i++){
      y=p[y];
    }
    vector<int>path;
    for(int cur=y;;cur=p[cur]){
      path.pb(cur);
      if(cur==y&&path.size()>1){
        break;
      }
    }
    reverse(path.begin(),path.end());
    for(int i=0;i<path.size();i++){
      cout<<path[i]<<" ";
    }
  }
}   
signed main() {
    IOS;
    srand(time(NULL));
    /*freopen("numbers.in", "r", stdin);
    freopen("numbers.out", "w", stdout);*/
  // cout<<endl;
    int UwU=1;
    // cin>>UwU;
    for(int i=1;i<=UwU;i++) {
      // cout<<"Case "<<i<<": ";
        solve();
      // cout<<endl;
    }
}
ll binpow(int a,int p){if(p==0)return 1;if(p%2){return ((binpow(a,p-1)*a)%MOD);}int res=binpow(a,p/2)%MOD; return (res*res)%MOD;}; 
 
 
