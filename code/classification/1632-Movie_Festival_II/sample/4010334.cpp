#include<bits/stdc++.h>
 
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
 
#define fo(i, n) for(int i=0;i<n;i++)
#define Fo(i, k, n) for(int i=k; i<n;i++)
#define ll long long int
#define ALL(c) (c).begin(),(c).end() //handy for function like "sort()"
#define mod 1000000007
#define ff first 
#define ss second 
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
 
typedef vector<int> vi;
typedef vector<ll> vli;
typedef vector<vli> vvl;
typedef pair<int, int> pii ;
typedef pair<ll, ll> pl ;
typedef vector<pair<ll, ll>> vpl ;
typedef vector<pii> vpi ;
typedef vector<vli> exv;
typedef map<ll,ll> mll;
typedef queue<ll> pq;
typedef queue<pii> qp;
 
const long long MOD = 1e9+7;
const long long MAX =LONG_LONG_MAX;
 
bool cmp_y(pl x, pl y){
  return x.second<y.second;
}
 
void print_vec(vector<ll> &tmp){
  for(auto& x:tmp){
      cout << x << " ";
  }
  cout<<endl;
  return;
}
 
void print_vecovec(vector<vector<ll>> lst){
    for(auto& x:lst){
      for(auto& y:x){
        cout<<y<<" ";
      }
      cout <<endl;
    }
}
 
// methods - char[x][y],string[n]
 
// vi dx{0,0,1,-1};
// vi dy{1,-1,0,0};
 
// vli d[200005];        
// vli par(200005);
// vli vis(200005);
// vli contains(200005);
 
 
// void dfs(int node,int parv){
//     for(auto&each:d[node]){
//         if(each!=parv){
//             par[each]=node;
//             dfs(each,node);
//         }
//     }
// }
// ll find(ll a){
//   if (par[a]==a)
//     return par[a];
//   return par[a]=find(par[a]);
// }
 
 
// int uni(ll a,ll b){
//   ll pa=find(a);
//   ll pb=find(b);
//   if (pa==pb)
//     return 1;
//   if (rnk[pa]<rnk[pb])
//   {
//     par[pa]=pb;
//     rnk[pb]+=rnk[pa];
//   }
//   else
//   {
//     par[pb]=pa;
//     rnk[pa]+=rnk[pb];
//   }
//   return 0;
// }
 
 
 
ll n,m,k;
// vector<vector<ll>> pref(1005,vector<ll>(1005,0));
 
void solve(){
  cin >> n >> k;
  vector<pair<ll,ll>> mv;
  fo(i,n){
    ll a,b;
    cin >> a>>b;
    mv.push_back(make_pair(a,b));
  }
  sort(ALL(mv),cmp_y);
  ll cnt=1;
  multiset<ll> en;
  en.insert(mv[0].ss);
  Fo(i,1,n){
    ll ts=mv[i].ff,te=mv[i].ss;
    auto mn=en.begin();
    // for(auto& x:en){cout << x << " ";}
    // cout <<endl;
    if(ts<*mn){
      if(en.size()<k){en.insert(te);cnt++;}
      continue;
    }
    auto itr=en.lower_bound(ts);
    if(itr==en.end()){
      en.erase(en.find(*(en.rbegin())));
    }
    else{ 
      if(*itr > ts){itr=prev(itr,1);} 
      en.erase(en.find(*itr));
    }
    en.insert(te);
    cnt++;
  }
  cout << cnt;
}
 
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
 
int main() {
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      ll t ;
      t=1;
      // cin>>t;
      // string problem="";
      // setIO(problem);
      while(t--){
        solve();
        cout << endl;
      }
      return 0;
}