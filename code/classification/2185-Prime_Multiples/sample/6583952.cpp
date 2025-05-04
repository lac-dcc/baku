#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 
int main() {
    ll n; cin >> n;
    int k; cin >> k;
    vector<ll> v(k); for(auto &num : v) cin >> num;
    ll ans = 0;
    for(int i = 1; i<(1<<k); i++) {
        int tmp = i;
        int cur = 0, cnt = 0, bits = 0; bool can = true;
        ll total = 1;
        while(tmp) {
            if(tmp&1) {
                if(n/v[cnt] < total) {
                    can = false;
                    break;
                }
                total*=v[cnt];
                bits++;
            }
            cnt++;
            tmp = tmp/2;
        }
        if(!can) continue;
        if(bits%2==0) ans -= n/total;
        else ans += n/total;
    }
    cout << ans << endl;
    return 0;
}