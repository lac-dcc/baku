#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define gcd __gcd
 
using namespace std;
const int INF = 1e18 + 5;
int n, k, a[25], x[25], ans = 0, cnt = 0;
int lcm(int a, int b){
    int x = a / gcd(a, b);
    if(k / b < x) return INF;
    return x * b;
}
void Try(int i, int val, int cnt){
    for(int v = 0; v < 2; v++){
        x[i] = v;
        if(x[i] == 1){
            val = lcm(val, a[i]), cnt++;
            if(val >= INF) return;
        }
        if(i == n){
            if(cnt == 0 || val >= INF) continue;
            if(cnt & 1) ans += k / val;
            else ans -= k / val;
        }
        else Try(i + 1, val, cnt);
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    Try(1, 1, 0);
    cout << ans;
    return 0;
}