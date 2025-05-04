/**
 *    author:  Ujjwal Tripathi
 *    created: 05.07.2021 23:41:58
**/
 
    
#include<bits/stdc++.h>
using namespace std;
 
#define ar array<int, 2>
#define int long long
#define in insert
#define pb push_back
#define pii pair<int,int>
#define vt vector
#define P_Q(x) priority_queue<x>
#define p_q(x) priority_queue<x, vector<x>, greater<x>>
#define For(i, n) for(int i = 0; i < n; i++)
#define Rev(i, n) for(int i = n-1; i >= 0; i--)
#define FOR(i, n) for(int i = 1; i <= n; i++)
#define REV(i, n) for(int i = n; i >= 1; i--)
#define Rep(i,a,b) for(int i = a; i <= b; i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int) (x).size()
 
// Maximum priority queue
template <typename T>
using mxpq = priority_queue<T>;
 
// Minimum priority queue
template <typename T>
using mnpq = priority_queue<T, vt<T>, greater<T>>;
 
 
// x | (x + 1) sets lowest unset bit of x
// x & (x - 1) unsets lowest set bit of x
 
const int mod = 1e9L + 7;
const int INF = 1e18L + 5;
const int mxN = 2e5 + 1;
 
 int n,m;
 vt<pair<int,pair<int,int>>> g;
 vt<int> dist;
 vt<int> par;
 void bellman_ford()
 {
    //dist[1]=0;
    int x;
    for(int i=0;i<n;i++)
    {
       x=-1;
       for(auto e:g)
       {
         int u=e.first;
         int v=e.second.first;
         int d=e.second.second;
        // cout<<u<<" "<<v<<" "<<d<<endl;
         if( dist[v]>dist[u]+d)
         {
            dist[v]=dist[u]+d;
            x=v;
            par[v]=u;
         }
       }
       //cout<<x<<endl;
    }
    if(x==-1)
    {
        cout<<"NO"<<endl;
        return;
    }
    else
    {
        cout<<"YES"<<endl;
       // cout<<x<<endl;
        int y=x;
        for(int i=0;i<n;i++)
        {
            y=par[y];
        }
         //cout<<y<<endl;
        x=y;
        vt<int> path;
        // for (int cur=y; ; cur=par[cur])
        // {
        //     path.push_back (cur);
        //     if (cur == y && path.size() > 1)
        //         break;
        // }
        while(par[y]!=x)
        {
           path.pb(y);
           y=par[y];
        }
        path.push_back(y);
        path.push_back(x);
        reverse(all(path));
        for(auto x:path)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
 }
//auto align ctrl+alt+f.
// remember to read no of test_cases
void solve()
{
   cin>>n>>m;
   for(int i=0;i<m;i++)
   {
     int x,y,z;
     cin>>x>>y>>z;
     g.pb({x,{y,z}});
   }
   dist.resize(n+1);
   par.resize(n+1);
   
   bellman_ford();
   return;
}
 
signed main()
{
  ios::sync_with_stdio(0);  cin.tie(0);
  int t = 1;
  // cin >> t;
  FOR(tt, t) solve();
  return 0;
}
