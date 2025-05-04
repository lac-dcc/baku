#include<bits/stdc++.h>
#define ll long long int
#define fr(i,x,y) for(int i=x;i<y;i++)
using namespace std;
vector<int> v;
void solve()
{
  ll n,m;
  cin>>n>>m;
  multiset<ll> ticketprice;
  ll x;
 
  for(ll i=0;i<n;i++){
   cin>>x;
   ticketprice.insert(x);
  }
 
  for(ll i=0;i<m;i++){
    cin>>x;
    auto it=ticketprice.upper_bound(x);
    if(it==ticketprice.begin()){
      cout<<-1<<endl;
    }else{
      cout<<*(--it)<<endl;
      ticketprice.erase(it);
    }
  }
 
}
int main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
// ll t;cin>>t;while(t--)
{solve();}
return 0;
}
