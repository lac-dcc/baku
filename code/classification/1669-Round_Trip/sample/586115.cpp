#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define ll long long
#define PI 3.141592653589
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define EPS 1e-7
#define ff first
#define ss second
#define print(val) "[ " << #val ": " << (val) << " ]\n"
#define vpp pair<int,pair<int,int>>
#define m_p(x,y) make_pair(x, y)
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
const int MOD = 1e9+7 ;
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int random_int(int l,int r){return uniform_int_distribution<int>(l,r)(rng);}
struct Debug;
template<typename T, typename C = std::ostream&>
struct hasPrint : false_type{};
template<typename T>
struct hasPrint<T, decltype(cout << declval<T>())>: true_type{};
struct Debug{
    template<typename T>
    typename enable_if<hasPrint<T>::value, Debug&>::type operator << (const T& t){
        cerr << t;
        return *this;
    }
    template<typename T>
    typename enable_if<!hasPrint<T>::value, Debug&>::type operator << (const T& t){
        auto ed = t.end();
        *this << "[";
        for(auto it = t.begin(); it != ed; it++){
            if(next(it) == ed){
                *this << *it; continue;
            }
            *this << *it << ", ";
        }
        *this << "]";
        return *this;
    }
    template<typename T, typename C>
    Debug& operator << (const pair<T,C>& t){
        *this << "[ " << t.first << ", " << t.second << " ]";
        return *this;
    }
};
constexpr ll fast_power(ll x, ll p){
    ll res = 1;
    while(p > 0){
        if(p & 1){
            res = (res * x)%MOD;
        }
        p = p >> 1;
        x = (x*x)%MOD;
    }
    return res;
}
vector<vector<int>> adj;
int main(){
    IO;
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool flag = false;
    vector<int> visited(n, -1);
    vector<int> ans;
    function<void(int, int)> dfs = [&](auto node, auto par){
        if(visited[node] != -1){
            flag = true;
            int cur = par;
            ans.push_back(node+1);
            while(cur != node){
                ans.push_back(cur+1);
                cur = visited[cur];
            }
            ans.push_back(node+1);
            return;
        }
        visited[node] = par;
        for(int x: adj[node]){
            if(x == par){
                continue;
            }
            dfs(x, node);
            if(flag){
                return;
            }
        }
 
    };
    for(int i = 0; i < n && !flag; i++){
        if(visited[i] == -1){
            dfs(i, i);
        }
    }
    if(!flag){
        cout << "IMPOSSIBLE";
        return 0;
    }
    cout << ans.size() << "\n";
    for(int x: ans){
        cout << x << " ";
    }
 
}
