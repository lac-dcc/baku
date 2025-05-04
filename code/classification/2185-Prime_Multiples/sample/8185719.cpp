#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mk make_pair
#define gcd __gcd
#define fl(i,x,y) for(ll i=x;i<y;i++)
#define bl(i,x,y) for(ll i=x;i>=y;i--)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
 
#define speed ios_base::sync_with_stdio(0),cin.tie(0), cout.tie(0);
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class TI>
using ordered_set = tree<TI, null_type, less<TI>, rb_tree_tag, tree_order_statistics_node_update>;
 
int main(){
speed;
    ll n,k;cin>>n>>k;
    ll a[k],ans=0;
    fl(i,0,k){
      cin>>a[i];
    }
    ll r=(1<<k);
    sort(a,a+k);
    fl(i,1,r){
      ll c=0,N=n;
      fl(j,0,21){
        if(i&(1<<j)){
          N/=a[j];
          c++;
        }
      }
      if(c%2==1){
        ans+=N;
      }else{
        ans-=N;
      }
    }
    cout<<ans<<endl;
    return 0;
}