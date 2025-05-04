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
#define fi first
#define se second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
 
typedef  long long int ll;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
 
#define nl '\n';
#define pb push_back
#define rep(x,s,e) for(ll x = s ; x < e ; ++x)
 
 
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
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fi); cerr << ","; _print(p.se); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
void dfs(vector<vector<char>>& vect,vector<vector<bool>>& visited,int i,int j);
int N,M;
int main(){
 
#ifndef ONLINE_JUDGE
        freopen("fin.txt" , "r" , stdin);
        freopen("fout.txt" , "w" , stdout);
        freopen("eror.txt" , "w" ,stderr);
#endif
 
fastio();
        int n,m,count=0; cin>>n>>m;
        vector<vector<char>> vect(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>vect[i][j];
            }
        }
        N = n; M = m;
        vector<vector<bool>> visited(n,vector<bool>(m,0));
 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vect[i][j]=='.' && visited[i][j]==0){
                   // visited[i][j] = 1;
                    count++;
                    dfs(vect,visited,i,j);
                }
               // count++;
            }
        }
 
        cout<<count<<endl;
return 0;
}
 
void dfs(vector<vector<char>>& vect,vector<vector<bool>>& visited,int i,int j){
 
     if(i<0 || j<0) return;
     if(i>=N || j>=M) return;
 
     if(vect[i][j]=='.' && visited[i][j]==0){
          
          visited[i][j] = 1;
    dfs(vect,visited,i+1,j);
    dfs(vect,visited,i-1,j);
    dfs(vect,visited,i,j+1);
    dfs(vect,visited,i,j-1);
   }else{
      return;
   }
}
 
