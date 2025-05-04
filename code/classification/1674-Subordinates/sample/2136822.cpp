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
const int N = 2e5 + 9;
 
int n;
vector<int> g[N];
int subtree[N];
 
void dfs(int x , int par = -1){
    for(auto child : g[x]){
        if(child == par) continue;
        dfs(child, x);
        subtree[x] += (1 + subtree[child]);
    }
}
void solve(){
    cin >> n;
 
 
    for(int i = 2; i <= n; i++){
        int par;
        cin >> par;
 
        g[par].push_back(i);
        g[i].push_back(par);
    }
 
    dfs(1);
    for(int i = 1; i <= n; i++){
        if(i > 1) cout << " ";
        cout << subtree[i];
    }
    cout << endl;
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
