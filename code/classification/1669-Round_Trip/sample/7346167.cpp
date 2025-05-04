// Author : abdelrhman
#include <bits/stdc++.h>
#define ll  long long
#define body(x) vector<x>
#define maxH(x) priority_queue<x>
#define minH(x) priority_queue<x, vector<x>, greater<x>>
#define forLoop(size) for (ll i = 0; i < (size); i++)
#define fr(n) for(ll i = 0 ; i < n ;i++)
#define forE(v) for (auto ii : v)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fj(size) for (ll j = 0; j < (size); j++)
#define for1(size) for (int i = 1; i <= (size);i++)
#define popCo(msk) __builtin_popcountll(msk)
#define log(x)     __lg(x)
#define reV(x)  return(void(cout << x << endl));
#define fastInputOutput                   \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);
const ll mod = 1e9 + 7, inf = 1e9, N = 2e5 + 5, M = 5e1 + 5;
using namespace std;
template<typename T>
ostream &operator<<(ostream &os, deque<T> v) {
    forE(v) {
        cout << ii << " ";
    }
    return os;
}
template<typename P>
ostream &operator<<(ostream &os, vector<P> v) {
    forE(v) {
        cout << ii << " ";
    }
    return os;
}
 
void FILES () {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}
char dC[] = {'D', 'L', 'R', 'U'};
int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
vector<ll>adj[N];
bool vis[N];
deque<ll>ans;
ll n, m;
void dfs(ll node, ll parent){
    vis[node] = true;
    ans.push_back(node);
    forE(adj[node]){
        if((vis[ii]) && ii != parent){
            ans.push_back(ii);
            while(ans.front() != ans.back())ans.pop_front();
            if(ans.size() > 2){
                cout << ans.size() << endl;
                cout << ans << endl;
                exit(0);
            }
        }
        if(!vis[ii])dfs(ii, node);
    }
    ans.pop_back();
}
void boda()
{
    cin >> n >> m;
    forLoop(m){
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i){
 
        if(!vis[i])dfs(i, 0);
    }
    cout << "IMPOSSIBLE\n";
}
int main() {
    fastInputOutput
    FILES();
    ll t = 1;
//    cin >> t;
    while (t--){
        boda();
    }
}
