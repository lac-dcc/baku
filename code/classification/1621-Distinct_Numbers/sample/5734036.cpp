#include<bits/stdc++.h>
using namespace std;
#define nl '\n'
#define ll long long 
// #define pb push_back
// const ll MOD=1e9+7;
// vector<ll>dp;
vector<bool>vis;
// vector<vector<ll>>dp;
void help(ll n, vector<ll>&a)
{    
   map<ll,ll>mp;
   
   for(auto it : a)mp[it]++;
   
   cout<<mp.size();
}
int main()
{ 
  ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
 ll  t = 1;
  // cin >> t;
  while(t--)
  {
    ll n ;
    cin >> n;
    
    ll a[n];
    for(auto &it: a)cin >> it;
    
    
    
    cout << set<int>(a , a+n).size();
    
    
  }
}