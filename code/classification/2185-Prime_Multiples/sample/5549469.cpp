#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long long ll;
#define PB push_back
#define MP make_pair
#define FOR(i, x, y) for (int i = x; i < y ; i ++)
const int MAXK = 20;
const ll MAXN = 2e18;
int sign(int i){
    int cnt = __builtin_popcount(i);
    if (cnt & 1){
        return 1;
    }
    else{
        return -1;
    }
}
int main(){
    ll n; int k; cin >> n >> k;
    vector<ll> p(k);
    FOR(i, 0, k){
        cin >> p[i];
    }
    ll ans = 0;
    int flag = 0;
    FOR(i, 1, (1 << k)){
        ll prod = 1;
        flag = 0;
        FOR(j, 0, k){
            if (p[j] > n) continue;
            if (i & (1 << j)){
                if (MAXN/ p[j] < prod){
                    flag = 1;
                    break;
                }
                prod *= p[j];
            }
        }
        // cout << i << ": " << prod << ' ';
        if (flag) continue;
        ans += sign(i) * (n / prod);
    }
    cout << ans << '\n';
}