#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <array>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <cassert>
#include <vector>
#include <numeric>
#include <cstdlib>
#include <bitset>
#include <chrono>
#include <random>
#include <fstream>
#include <iterator>
#include <complex>
#include <cstring>
 
typedef long long ll;
typedef unsigned long long int ull;
typedef long double ldb;
 
#define PB push_back
#define all(x) x.begin(), x.end() 
 
#define PYES cout<<"YES\n"
#define PNO cout<<"NO\n"
#define PYes cout<<"Yes\n"
#define PNo cout<<"No\n"
#define MOD 1000000007
 
#define all(x) x.begin(), x.end()
#define MAXN 1000000
 
using namespace std;
//--------------------------------------------functions-------------------------------------------------//
ll mod(ll x,ll M){return ((x%M + M)%M);}
ll mod_inv(ll a, ll m) {
    ll g = m, r = a, x = 0, y = 1;
    while (r != 0) {
        ll q = g / r;
        g %= r; swap(g, r);
        x -= q * y; swap(x, y);
    }
    return mod(x,m);
}
bool compare1(pair<ll, ll> a,pair<ll, ll> b){
    return a.second < b.second;
}
 
//--------------------------------------------solve----------------------------------------------//
vector<vector<int>> e;
vector<int> visited;
vector<int> par;
vector<int> ans;
int star, en;
 
void dfs(int n, int p){
    visited[n]=1;
    for(auto x : e[n]){
        dfs(x, n);
        ans[n] += 1 + ans[x];
    }
}
 
void solve(){
    int n; cin>>n;
    e.resize(n+1, vector<int>());
    visited.resize(n+1, 0);
    par.resize(n+1, -1); 
    ans.resize(n+1, 0);
    int x;
    for(int i=2;i<=n;i++){
        cin>>x;
        e[x].PB(i);
        //e[i].PB(x);
    }    
    dfs(1,-1);
    for (int i = 1; i <= n; ++i)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test_cases=1;
    //cin>>test_cases;
    while(test_cases--){
        solve();
    }
    return 0;
}
