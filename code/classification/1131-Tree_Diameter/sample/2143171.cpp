#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
 
using namespace std;
#define ll long long
#define pi pair<int,int>
#define pll pair<ll,ll>
#define ld  long double
 
const int INF = 1e9 + 7;
const long long MOD = 1e9 + 7;
 
const int N = 2e5 + 7;
int n, ans = 0;
vector<int> g[N];
 
int d[N];
 
void dfs(int x = 1, int p = -1){
    for(auto y : g[x]){
        if(y == p) continue;
        dfs(y , x);
        ans = max(ans, d[x] + d[y] + 1);
        d[x] = max(d[x], d[y] + 1);
    }
}
 
void solve(){
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int x , y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs();
    cout << ans << endl;
}
 
int main(){
    ios :: sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr);
 
    int tt = 1;
    // cin >> tt;
 
    #ifdef SIEVE
    construct();
    #endif
 
    #ifdef NCR
    compute_combinations_table(MOD);
    #endif
 
    #ifdef FACTORIALS
    compute_factorials(MOD);
    #endif
 
    for(int tc = 1; tc <= tt; tc++){
        // cout << "Case #" << tc << ": ";
        solve();
    }
}
