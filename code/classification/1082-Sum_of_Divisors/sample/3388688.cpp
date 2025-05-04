#include<bits/stdc++.h>
#define FOR(i,a,n) for(int i = a;i<n;i++)
#define RFOR(i,a,n) for(int i = n-1;i>=a;i--)
typedef long long ll;
#include <bitset>
using namespace std;
// DEBUG FUNCTIONS 
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
// 1554B 
// https://codeforces.com/contest/1554/problem/B
// https://codeforces.com/contest/1617/problem/C
ll inf=1e18;
ll mod=1e9+7; 
//ll mod=998244353;
// long long inf=1000*1000*((double)1000)*1000*1000*1000*1000; 
 
 
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
 
 ll binpow(ll a,ll b){
	ll z=1;
	while(b>0){
  		if(b%2==1){
  			z*=a;
  			z%=mod;
  		}
  		a*=a;
  		a%=mod;
  		b/=2;
 
  	}
  	return z;
}
 
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
 // https://codeforces.com/contest/1517/problem/D   
    // int n;
    // cin>>n;
 
    // vector<int> x(n,0);
    // FOR(i,0,n){
    //     cin>>x[i];
    // }
 
   ll n;
   cin>>n;
 
   ll k=2;
   ll ans=0;
   for( ; k*k<=n ; k++  ){
   		ll nl=n/k;
   		ll nu=n/(k-1);
 
   		nl%=mod;
   		nu%=mod;
 
   		ll sum=((nu*(nu+1))/2)%mod-((nl*(nl+1))/2)%mod;
   		if(sum<0){
   			sum+=mod;
   		}
   		ans+=sum*(k-1);
 
   		ans%=mod;
   }
 
 
   for( ll i=1; i<=n/(k-1) ; i++ ){
   		ans+=(n/i)*i;
   		ans%=mod;
   }
  
 
   cout<<ans;
 
return 0;
 
}
