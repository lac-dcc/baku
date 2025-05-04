#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL const p = 1e9 + 7;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    LL n;
    cin >> n;
    LL ans = 0;
 
    for(LL i = 1; i * i <= n; i++){
        LL x = n / i % p;
        ans += x * (x + 1) / 2 % p;
        ans -= (i - 1) * i / 2 % p;
        x -= i;
        ans += x * i % p;
        ans = (ans % p + p) % p;
    }
    cout << ans << '\n';
}
