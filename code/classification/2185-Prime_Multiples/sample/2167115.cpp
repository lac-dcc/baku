#include<bits/stdc++.h>
using namespace std;
 
#define IO  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pp  make_pair
#define pb  push_back
#define ll  long long int
#define pi  pair<int, int>
#define pll pair<long long int, long long int>
#define F   first
#define S   second
#define vi  vector
#define all(a) (a).begin(),(a).end()
#define endl '\n'
 
#define rep(i,a,b) for (int i = (a); i < (b); ++i)
 
const int M = 1e9+7; // 998244353;
const int INF = 1e9;
// const int N = 1e5 + 1;
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    IO;
    ll n,k;
    cin>>n>>k;
    ll a[k];
    rep(i,0,k) cin>>a[i];
    ll ans=0;
    rep(i,0,(1LL<<k)){
        ll p=1;
        rep(j,0,k){
            if((1<<j)&i){
                if(p>n/a[j]){
                    p=n+1;
                    break;
                }
                p*=1LL*a[j];
            }
        }
        int cnt=__builtin_popcount(i);
        // if(p==1) continue;
        if(cnt%2) ans+=n/p;
        else ans-=n/p;
    }
    ans+=n;
    cout<<ans<<endl;
    
    
    return 0;
}