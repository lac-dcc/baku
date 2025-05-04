//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("fma")
 
 
#include"bits/stdc++.h"
//using namespace __gnu_pbds;
using namespace std;
#define infinity 1<<30 //2^30
#define ll long long int
#define pii pair<ll,ll>
#define pb push_back
#define FastIO ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0)
#define pi  3.14159265358979323846
#define INF 99999999
#define ff first
#define ss second
#define MAX_N 20
 
#define MAXN  10000007
#define mod  1000000007
 
#define nnn 10000007
#define endl '\n'
 
#define clearbit(x, k) (x & ~((long long)1 << k))
#define checkbit(x, k) (x & ((long long)1 << k))
#define setbit(x, k) (x | ((long long)1ll << k))
 
 
 
 
int main()
{
 
 
 
    FastIO;
 
 
    ll t; t=1;
    //cin>>t;
 
    //sieve(10000007);
 
 
 
    while(t--){
 
      ll n,x;cin>>n>>x;
 
      vector<ll>v(n+1);
 
      for(ll i=1;i<=n;i++){
        cin>>v[i];
      }
 
      map<ll,pii>mp;
 
      mp[v[1]+v[2]]={1,2};
 
 
      for(ll k=3;k<=n;k++){
        for(ll l =k+1;l<=n;l++){
            ll rem = x-v[k]-v[l];
 
            if(mp.count(rem)){
                cout<<mp[rem].ff<<" "<<mp[rem].ss<<" "<<k<<" "<<l<<endl;
                return 0;
            }
 
        }
 
        for(ll i=1;i<k;i++){
            mp[v[i]+v[k]]={i,k};
        }
      }
 
      cout<<"IMPOSSIBLE"<<endl;
 
 
    }
 
 
 
 
	return 0;
}
