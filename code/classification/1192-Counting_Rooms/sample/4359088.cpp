#include <iostream>
#include <vector>
#include <string.h>
#include <map>
#include <unordered_map>
#include <set>
#include <math.h>
#include <algorithm>
#include <queue>
 
#define ll long long
#define pll  pair< long, long > 
#define ull unsigned long long
#define vll vector< ll > 
#define vpll vector< pair< ll, ll > >
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
 
using namespace std;
const ll inf = 1e6 + 1;
const int MOD = 1e9 + 7;
// ll DP[inf][inf];
 
// void generate_seive(ll n) {
//     for(ll i = 2; i <= n; i++) {
//         if(sieve[i]) continue;
//         for(ll u = 2*i; u <= n; u+=i){
//             sieve[u] = i;
//         }
//     }
// }
 
ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}
 
ll lcm(ll a, ll b){
    return a*b/gcd(a, b);
}
 
ll DP[inf];
 
bool vis[1000][1000];
string s[1000];
ll n, m;
 
void DFS(ll x, ll y){
    if(vis[x][y]) return;
    vis[x][y] = 1;
    if(x + 1 >= 0 && x + 1 < n && s[x + 1][y] == '.') {
        DFS(x + 1, y);
    }
    if(x - 1 >= 0 && x - 1 < n && s[x - 1][y] == '.') {
        DFS(x - 1, y);
    }
    if(y + 1 >= 0 && y + 1 < m && s[x][y + 1] == '.') {
        DFS(x, y + 1);
    }
    if(y - 1 >= 0 && y - 1 < m && s[x][y - 1] == '.') {
        DFS(x, y - 1);
    }
}
 
void solve(int T) {
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> s[i];
    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) {
            if(s[i][j] == '.') {
                if(!vis[i][j]){
                    ans++;
                    DFS(i, j);
                }
            }
        }
    }
    cout << ans << endl;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // ll n; cin >> n;
    // while(n--){
    //     solve(0);
    // }
    solve(0);
    return 0;
}
