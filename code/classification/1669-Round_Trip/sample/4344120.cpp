// #include <bits/stdc++.h>
 
// using namespace std;
 
// using ll = long long;
// using vi = vector<int>;
// using vvi = vector<vector<int>>;
// using vl = vector<ll>;
// using vvl = vector<vector<ll>>;
// using pi = pair<int, int>;
// using pl = pair<ll, ll>;
 
 
// #define all(x) begin(x), end(x)
// #define rall(x) rbegin(x), rend(x)
// #define pb push_back
// #define mp make_pair
// #define F first
// #define S second
// #define endl '\n'
// #define forn(i, n) for(ll i = 0; i < n; i++)
// #define fora(i, a, n) for(ll i = a; i < n; i++)
// #define inp(e) int e; cin >> e
// #define inpl(e) ll e; cin >> e
// #define inps(e) string e; cin >> e
// #define T int tt; cin >> tt; while(tt--)
 
 
// template<typename U>
// void print(U arr) {
//     for(auto element: arr) {
//         cout << element << " ";
//     }
//     cout << endl;
// }
 
// // read and write into files, rather than standard i/o
// void setup(string s) {
//     freopen((s+".in").c_str(), "r", stdin);
//     freopen((s+".out").c_str(), "w", stdout);
// }
 
// const int M = 1e9+7;
 
// int find(int x,vi &par){
//     if(par[x]==-1){
//         return x;
//     }
//     return par[x]=find(par[x],par);
// }
 
// bool unite(int a, int b,vi &par){
//     int x=find(a,par);
//     int y=find(b,par);
//     if(x==y){
//         return false;
//     }
//     if(par[x]<par[y]){
//         swap(x,y);
//     }
//     par[y]+=par[x];
//     par[x]=y;
//     return true;
// }
 
// void solve(){
//     long long int i,n,x,y,a,b,c,sam=0;
//     cin>>n>>x;
//     vi par(n,-1);
//     forn(i,x){
//         cin>>a>>b;
 
//     }
// }
 
// int main(void) {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     // ll tt;
//     // cin>>tt;
//     // while(tt--){
//     //     solve();
//     // }
 
//     solve();
    
 
//     return 0;
// }
 
 
#include <bits/stdc++.h>
 
using namespace std;
const int maxN = 1e5+1;
 
int N, M, a, b, p[maxN], ds[maxN];
vector<int> ans, G[maxN];
 
void dfs(int u){
    for(int v : G[u]){
        if(v != p[u]){
            p[v] = u;
            dfs(v);
        }
    }
}
 
int find(int u){
    if(ds[u] < 0)   return u;
    ds[u] = find(ds[u]);
    return ds[u];
}
 
bool merge(int u, int v){
    u = find(u); v = find(v);
    if(u == v)  return false;
    if(ds[u] < ds[v])   swap(u, v);
    ds[v] += ds[u];
    ds[u] = v;
    return true;
}
 
int main(){
    scanf("%d %d", &N, &M);
    fill(ds+1, ds+N+1, -1);
    for(int i = 0; i < M; i++){
        scanf("%d %d", &a, &b);
        if(!merge(a, b)){
            dfs(a);
 
            int u = b;
            while(u != 0){
                ans.push_back(u);
                u = p[u];
            }
 
            int K = ans.size();
            printf("%d\n", K+1);
            for(int j = 0; j < K; j++)
                printf("%d ", ans[j]);
            printf("%d\n", b);
 
            return 0;
        } else {
            G[a].push_back(b);
            G[b].push_back(a);
        }
    }
    printf("IMPOSSIBLE\n");
}
