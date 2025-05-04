#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define tt int t;cin>>t;while(t--)
#define all(x) x.begin(),x.end()
#define f first
#define s second
#define pb push_back
#define pi pair<int,int>
#define pll pair<ll,ll>
#define vt vector<ll>
#define vpll vector<pair<ll,ll>> 
#define vvll vector<vector<ll> >
#define vvpll vector<vector<pair<ll,ll> > >
#define inf 1000000000
#define maxn 400003
/*ll gcdeuclid(ll a,ll b){ 
    return (b==0 ? a : gcdeuclid(b,a%b));
}*/
int main(){
   ll n,i=0,j=0,cnt=1,mx=1;
   cin >> n;
   vt arr(n),dep(n);
   for(i=0;i<n;i++){
       cin >> arr[i] >> dep[i];
   }
   sort(all(arr));
   sort(all(dep));
   i=1;
   while(i<n and j<n){
       if(arr[i]<dep[j]) cnt++,i++;
       else cnt--,j++;
       mx = max(cnt,mx);
   }
   cout <<mx<<"\n";
    
    
    
    
    return 0;
}
