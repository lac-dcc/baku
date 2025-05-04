#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define FOR(i,a,b) for (ll i = a; i < b; i++)
#define rep(i,n) FOR(i,0,n)
#define endl "\n"
#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7:合同式の法
 
//略記
#define all(x) x.begin(),x.end()
#define pb push_back //挿入
#define mp make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second //pairの二つ目の要素
 
template <typename T> //常にaのほうが大きくなる、更新が起こったらtrueを返す(true = a < bということ)
bool chmax(T &a, const T& b){
    if (a < b){
        a = b;
        return true;
    }
    return false;
}
 
template <typename T> //常にaのほうが小さくなる、更新が起こったらtrueを返す(true = a > bということ)
bool chmin(T &a, const T& b){
    if (a > b){
        a = b;
        return true;
    }
    return false;
}
 
ll mod(ll val, ll m){
    ll res = val % m;
    if (res < 0) res += m;
    return res;
}
// ios::sync_with_stdio(0);
// std::cin.tie(0);
 
vector<vector<int>> g;
int n, a, b, ans = 0;
 
int dfs(vector<vector<int>> &g, int node, int parent){
    int res = 0, first = -1, second = -1;
    for (auto nei : g[node]){
        if (nei == parent){continue;}
        int depth = dfs(g,nei,node);
        chmax(res,depth + 1);
        if (depth > first){
            second = first; first = depth;
        } else if(depth > second){
            second = depth;
        }
    }
    if (first != -1 && second != -1){chmax(ans,first + second + 2);}
    if (first != -1 && second == -1){chmax(ans,first + 1);}
    return res;
}
 
int main(){
    cin >> n;
    g.assign(n,vector<int>());
    rep(i,n-1){
        cin >> a >> b;
        a -= 1; b -= 1;
        g[a].pb(b); g[b].pb(a);
    }
    dfs(g,0,-1);
    cout << ans << endl;
}
