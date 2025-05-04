#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <bitset>
#include <deque>
#include <stack>
#include <array>
#include <cassert>
#define ll long long
#define ld long double
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define ALL(x) x.begin(), x.end()
#define vi vector<int>
#define vl vector<ll>
#define SZ(x) (int)x.size()
#define CASE int t;cin>>t;for(int ca=1;ca<=t;ca++)
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int MAX = 1 << 20, MOD = 1e9 + 7;
 
void ADD(ll &a, ll b){
    a += b;
    if(a >= MOD)
        a -= MOD;
    if(a < 0)
        a += MOD;
}
 
void solve(){
    ll n;
    cin >> n;
    ll ans = 0;
    for(ll i = 1;i * i <= n;i++){
        ADD(ans, (n / i - i + 1) % MOD * i % MOD);
        ll tmp1 = n / i + i + 1, tmp2 = n / i - (i + 1) + 1;
        if(tmp1 & 1)
            tmp2 /= 2;
        else
            tmp1 /= 2;
        tmp1 %= MOD;
        tmp2 %= MOD;
        ADD(ans, tmp1 * tmp2 % MOD);
    }
    cout << ans << '\n';
}
 
int main(){
    IOS
    // CASE
        solve();
    return 0;
}