#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
 
 
 
 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
 
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
vector<int> v[200001];
  pair<int,int> func(int curr)
   {  
           queue<pair<int,int>> q;
           q.push({curr,0});
           vector<int> vis(200001,0);
           pair<int,int> u;
          while(!q.empty())
          {    
                u=q.front();
               int node=q.front().first;
               int dist=q.front().second;
               vis[node]=1;
               q.pop();
               for(int child:v[node])
               {
                   if(vis[child]==0)
                   {
                       q.push({child,dist+1});
                   }
               }
          }
 
          return u;
 
   }
 
int main()
{
#ifndef ONLINE_JUDGE
 freopen("input1.txt", "r", stdin);
 freopen("output1.txt", "w", stdout);
 freopen("Error.txt", "w", stderr);
#endif
      
 
            int n;
            cin>>n;
              
            for(int i=0;i<n-1;i++)
            {
                  int x,y;
                  cin>>x>>y;
                  v[x].push_back(y);
                  v[y].push_back(x);
            }
            
            pair<int,int> p=func(1);
            pair<int,int> p1=func(p.first);
 
            cout<<p1.second;
             
             
             
                 
             
        
          
          
}
