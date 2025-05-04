#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
#define rep(i,n) for(i=0; i<n; i++)
#define repa(i,a,n) for(i=a; i<n;i++)
#define repit(x, k) for(auto x:k)
#define vi vector<int>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vvi vector<vector<int>>
#define fi first
#define se second
#define pb(t) push_back(t)
#define lb(t) lower_bound(t)
#define ub(t) upper_bound(t)
#define mp(a,b) make_pair(a, b)
#define mset(a, val) memset(a, val, sizeof(a))
#define all(v) v.begin(), v.end()
 
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
 
#define M 1000000007 // 9 zeros + 5
#define epsilon 1e-9
#define PI  3.14159265
#define INF 1e9+5
#define INFF  1000000000000000005ll //18 zeros + 5
 
int main(){
  SPEED;
  ll i,j,k;
  
  int n,m;
  cin>>n>>m;
  multiset<ll> mm;
  ll t1;
  rep(i,n){
    cin>>t1;
    mm.insert(t1);
  }
  vll price(m);
  rep(i,m){
    cin>>price[i];
  }
  // auto it;
  rep(i,m){
    ll tf = price[i];
 
    if(mm.empty()){
      cout<<-1<<endl;
      continue;
    }
 
    auto it = mm.lower_bound(tf);
    if(*it == tf){
      cout<<tf<<endl;
      mm.erase(it);
    }
    else if(it!=mm.begin()){
      it--;
      cout<<*it<<endl;
      mm.erase(it);
    }
    else{
      cout<<-1<<endl;
    }
 
  }
 
 
  return 0;
}
