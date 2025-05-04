#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    const __int128 MOD = 1e9 + 7;
    __int128 n;
    int64_t temp;
    cin >> temp;
    n = temp;
    __int128 sq = 3000000;
    __int128 res = 0;
    for(int64_t i=1;i<=sq;i++){
        res += (i*(n/i))%MOD;
        res %= MOD;
    }
    // cout << sq << " " << res << "\n";
    for(int64_t i=1;i<=sq+1;i++){
        __int128 lw = max(sq,n/(i+1))+1;
        __int128 rg = n/i;
        // cout << lw << " " << rg << " " << i << "\n";
        if(rg-lw+1 < 0) continue;
        res += (((lw+rg)*(rg-lw+1)/2)%MOD*i)%MOD;
        res %= MOD;
    }
    cout << (int64_t)res << "\n";
}