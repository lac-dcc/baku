#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int MOD = 1e9 + 7;
 
int main(){
    //freopen("sum.in" , "r" , stdin);
 
    ll n , ans = 0; cin >> n;
    ll d = (int) sqrt(n);
 
    for(ll i=1; i <= d; i++){
        ll q = n / i;
        //cout << i << " " << q << endl;
        if(q > d){
            ll k , temp;
            if((q-d) % 2 == 0){
                k = ((q-d)/2) % MOD;
                temp = (q+d+1) % MOD;
                k = k * temp % MOD;
            }
            else{
                k = ((q+d+1)/2) % MOD;
                temp = (q-d) % MOD;
                k = k * temp % MOD;
            }
            ans = (ans + k) % MOD;
        }
        ll extra = q*i % MOD;
        ans = (ans + extra) % MOD; 
        //cout << ans << endl;
 
        //if(i*i == n) ans -= n;
    }
    while(ans < 0) ans += MOD;
 
    cout << ans << endl;
    return 0;
 
}