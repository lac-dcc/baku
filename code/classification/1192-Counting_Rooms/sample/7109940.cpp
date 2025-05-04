//
//  main.cpp
//  DFS & DFS notes
//
//  Created by Ahmed Bahy on 23/06/2023.
//
 
 
//Cycle detection in directed graph    "connected graph"
//#include <iostream>
//#include <vector>
//#include <cmath>
//#include <algorithm>
//#include <utility>
//#include <map>
//#include <set>
//#include <queue>
//#include <stack>
//#include <bitset>
//#include <iomanip>
//#include <cstring>
//#pragma GCC optimize("-Ofast")
//#pragma GCC optimize("-ffast-math")
//#pragma GCC optimize("-funroll-loops")
//#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,tune=native")
//#define ll long long
//#define ull unsigned long long
//#define Ahmed_Bahy ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//#define Num_of_Digits(n) ((int)log10(n) + 1)
//#define PI 3.1415926535897932384626433832795
//#define MOD 1000000007
//#define read(type) readInt<type>()
//using namespace std;
//const int N=1e5+5,INF=1e9;
//const ll OO=1e118;
//ll t=1;
//int n,m;
//vector<vector<int>>adj_list;
//bitset<N>vis(0),inStack(0);
//bool ok=false;
//void hasCycle(int cur)
//{
//   vis[cur]=1;
//   inStack[cur]=1;
//   for(auto i:adj_list[cur])
//   {
//       if(!vis[i])
//           hasCycle(i);
//       else if(inStack[i])
//           ok=true;
//   }
//   inStack[cur]=0;
//}
//void solve()
//{
//   int u,v;
//   cin>>n>>m;
//   adj_list.resize(n+1);
//   for(int i=0;i<m;i++)
//   {
//       cin>>u>>v;
//       adj_list[u].push_back(v);
//   }
//   for(int i=1;i<=n;i++)
//   {
//       if(!vis[i])
//       {
//           ok=false;
//           hasCycle(i);
//           if(ok)
//               cout<<"The Graph Has A Cycle\n";
//           else
//               cout<<"The Graph Don't Have A Cycle\n";
//       }
//   }
//}
//int main()
//{
//   Ahmed_Bahy
////    cin>>t;
//   while(t--)
//       solve();
//}
 
 
// Cycle detection in undirected graph    "connected graph"
//#include <iostream>
//#include <vector>
//#include <cmath>
//#include <algorithm>
//#include <utility>
//#include <map>
//#include <set>
//#include <queue>
//#include <stack>
//#include <bitset>
//#include <iomanip>
//#include <cstring>
//#pragma GCC optimize("-Ofast")
//#pragma GCC optimize("-ffast-math")
//#pragma GCC optimize("-funroll-loops")
//#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,tune=native")
//#define ll long long
//#define ull unsigned long long
//#define Ahmed_Bahy ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//#define Num_of_Digits(n) ((int)log10(n) + 1)
//#define PI 3.1415926535897932384626433832795
//#define MOD 1000000007
//#define read(type) readInt<type>()
//using namespace std;
//const int N=1e6+5,INF=1e9;
//const ll OO=1e118;
//ll t=1;
//int n,m;
//vector<vector<int>>adj_list;
//bitset<N>vis(0);
//bool ok=false;
//void hasCycle(int cur , int par)
//{
//    vis[cur]=1;
//    for(auto i:adj_list[cur])
//    {
//        if(!vis[i])
//            hasCycle(i,cur);
//        else if(i!=par && par!=-1)
//            ok=true;
//    }
//}
//void solve()
//{
//    int u,v;
//    cin>>n>>m;
//    adj_list.resize(n+1);
//    for(int i=0;i<m;i++)
//    {
//        cin>>u>>v;
//        adj_list[u].push_back(v);
//        adj_list[v].push_back(u);
//    }
//    for(int i=1;i<=n;i++)
//    {
//        if(!vis[i])
//        {
//            ok=false;
//            hasCycle(i,-1);
//            if(ok)
//                cout<<"The Graph Has A Cycle\n";
//            else
//                cout<<"The Graph Don't Have A Cycle\n";
//        }
//    }
//}
//int main()
//{
//    Ahmed_Bahy
////    cin>>t;
//    while(t--)
//        solve();
//}
 
 
//CSES Problem Set Counting Rooms
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <iomanip>
#include <cstring>
#pragma GCC target("popcnt")
#pragma GCC optimize("-Ofast")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,tune=native")
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define Ahmed_Bahy ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define Num_of_Digits(n) ((int)log10(n) + 1)
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define popcount(x) __builtin_popcount(x)
#define clz(x) __builtin_clz(x)
#define ctz(x) __builtin_ctz(x)
#define popcountll(x) __builtin_popcountll(x)
#define clzll(x) __builtin_clzll(x)
#define ctzll(x) __builtin_ctzll(x)
const int dr[8] = {0, 0, 1, -1, 1, 1, -1, -1};
const int dc[8] = {1, -1, 0, 0, 1, -1, 1, -1};
using namespace std;
const int N=1e6+5,INF=1e9;
const ll OO=1e18;
const double ESP=1e-12;
ll t=1;
char grid[1001][1001];
bool vis[1001][1001];
int n,m;
void dfs(int r,int c)
{
    vis[r][c]=1;
    for(int i=0;i<4;i++){
        int nr=r+dr[i],nc=c+dc[i];
        if(nr<0 || nr>=n || nc<0 || nc>=m || grid[nr][nc]=='#' || vis[nr][nc])continue;
        dfs(nr,nc);
    }
}
void solve()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>grid[i];
    int ans=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(!vis[i][j] && grid[i][j]=='.'){
                dfs(i,j);
                ans++;
            }
    cout<<ans<<"\n";
}
int main()
{
    Ahmed_Bahy
//    cin>>t;
    while(t--)
        solve();
}
 
