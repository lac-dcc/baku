#include<bits/stdc++.h>
typedef long long int ll;
#define do_it_fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define vll vector<long long int>
#define pll pair<long long int, long long int>
using namespace std;
 
void solve(){
    ll x,y;
    cin>>x>>y;
    if(x<y){
        ll ans;
        if(y%2!=0)
        ans=(y*y)-x+1;
        else
        ans=((y-1)*(y-1))+x;
        cout<<ans;
    }else{
        ll ans; 
        if(x%2==0)
            ans = (x* x) - y + 1;
        else
            ans = ((x - 1) * (x - 1))+y;
        cout << ans;
    }
    cout<<"\n";
}
 
int main(){
    do_it_fast;
    ll t=1; cin>>t;
    while(t--){
        solve();     
    }
    return 0;
}