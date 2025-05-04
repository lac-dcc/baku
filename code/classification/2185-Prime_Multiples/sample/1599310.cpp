// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
const ll inf = 1e18;
ll a[30];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n, k;
    cin >> n >> k;
    for(ll i =0;i<k;i++) cin >> a[i];
    ll r=0;
    for(ll mask=1;mask<(1<<k);mask++){
        __int128 e=1;
        for(ll i = 0;i<k;i++) if((mask>>i)&1){
            e*=a[i];
            if(e>inf) e=0;
        }
        if(!e) continue;
        if(__builtin_popcount(mask)&1) r+=n/e;
        else r-=n/e;
    }
    cout<<r;
}