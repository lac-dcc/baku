#include <bits/stdc++.h>
using namespace std ; 
#define int long long 
using namespace std;
#define int long long
#define pb push_back
#define mset(m,v) memset(m,v,sizeof(m))
#define dbg(var) cout<<#var<<"="<<var<<"\n";
#define nl cout<<"\n";
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
 
#define f(x,a,b) for(int x=a;x<b;x++)
#define all(a) (a).begin(), (a).end()
#define yes cout<<"Yes\n"
#define no cout<<"No\n"
#define ff first
#define ss second
#define debarr(a,n) cout<<#a<<" : ";for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debmat(mat,row,col) cout<<#mat<<" :\n";for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const unordered_set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const unordered_map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const multiset<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}
//lli binpow(lli b,lli p,lli mod){lli ans=1;b%=mod;for(;p;p>>=1){if(p&1)ans=ans*b%mod;b=b*b%mod;}return ans;}
 
int n, m ;
vector<vector<int>> g;
vector<int> vis;
vector<int> parent;
 vi path;
// bool valid(int nx, int ny) {
//     return (nx >= 0 && ny >= 0 && nx < n && ny < m && g[nx][ny] != '#');
// }
 bool is_cycle  =0 ;
void dfs( int node  , int par  ){
  vis[node] = 2 ;
  parent[node] = par  ; 
  for (auto v :g[node]){
      if(v==par) continue ;
      if(vis[v]==1){
          dfs(v  , node ) ;
      }
      else if (vis[v] ==2){
          if(is_cycle == 0){
              int temp = node ;
              //vi path ;
              while (temp!=v){
                  path.pb(temp) ; 
                  temp = parent[temp] ; 
                  
              }
              path.pb(temp) ; 
              reverse(all(path)) ;
              is_cycle = 1 ;
          }
      }
  }
  vis[node] = 3 ; 
  //return  ;
}
// void bfs(int node ) {
//     queue<int> q;
//     q.push(node);
//     dis[node]= 0;
 
//     while (!q.empty()) {
//         int curr = q.front();
//         q.pop();
 
//         for(auto v : g[curr]){
//             if(v== curr) continue;
//             if(dis[v] > dis[curr]+1){
//               dis[v] = dis[curr]+1 ;
//               parent[v] = curr;
//               q.push(v);
//             }
//         }
//     }
// }
 
void solve() {
    cin >> n >> m;
    g.assign(n+1, vector<int>());
    vis.assign(n+1,1);
    parent.assign(n+1, -1);
    //pair<int, int> st, en;
    map<pair<int, int> ,int>EdgeList ;
    int a, b ;
    f(i , 0 , m){
     cin>>a >> b ;
     if(a>b)swap(a, b);
     else if (a==b)continue ;
     EdgeList[make_pair(a,b)]++;
     if(EdgeList[make_pair(a,b)]>1)continue ;
     else{
     g[a].pb(b);
     g[b].pb(a);
     }
    
    }
    
    f(i , 1, n+1 ){
        if (vis[i]==1){
            dfs(i , -1) ; 
        }
    }
    if(is_cycle){
        
    
    cout << path.size()+1;
    nl;
    for(auto v : path){
        cout << v << " " ; 
    }
    cout << path[0] ;
  nl;
    }
    else {
        cout <<"IMPOSSIBLE" ;
        
    }
 
// if (path.size() >= 3) {
//         cout << path.size()+1 << "\n";
//         for (int i = 0; i < path.size(); i++) {
//             cout << path[i] << " ";
//         }
//       cout << path[0];
//         cout << "\n";
//     } else {
//         cout << "IMPOSSIBLE\n";
//     }
 
    
     // Check if Uolevi's computer is not connected to any other computer
    // if (g[1].empty()) {
    //     cout << "IMPOSSIBLE" << endl;
    //     return;
    // }
 
//  bfs(1);
 
//  if(dis[n+1]!=1e9){
//      cout << dis[n]+1;
//      nl;
//      int temp = n ;
//      vi path ;
//      while (temp !=1){
//          path.pb(temp);
//          temp = parent[temp] ;
         
//      }
//     path.pb(1);
//     reverse(all(path));
//     for(int i = 0 ; i< path.size() ; i++){
//         cout << path[i] <<" " ;
//     }
//     }
//  else if(dis[n]== 1e9){
//      cout << "IMPOSSIBLE";
//  }
//  nl;
 
 
}
 
signed main (){
    int t=1 ; 
    //cin >> t  ;
    while (t--){
        solve () ; 
        
    }
}
 
 
