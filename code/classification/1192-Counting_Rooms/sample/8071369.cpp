#include<bits/stdc++.h>
 
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
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
 
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
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
 
int n, m;
vector<vector<char>> v(1000,vector<char>(1000));
vector<vector<int>> vis(1000,vector<int>(1000,0));
void dfs(int i,int j){
    vis[i][j]=1;
    if(i-1>=0 && v[i-1][j]=='.' && vis[i-1][j]==0){
        dfs(i-1,j);
    }
    if(i+1<n && v[i+1][j]=='.' && vis[i+1][j]==0){
        dfs(i+1,j);
    }
    if(j-1>=0 && v[i][j-1]=='.' && vis[i][j-1]==0){
        dfs(i,j-1);
    }
    if(j+1<m && v[i][j+1]=='.' && vis[i][j+1]==0){
        dfs(i,j+1);
    }
}
 
void solve(){
	cin >> n >> m;
    debug(n);
    debug(m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    int rooms=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]=='.' && vis[i][j]==0){
                dfs(i,j);
                rooms++;
            }
        }
    } 
    cout<<rooms;
 
}
 
int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("Error.txt", "w", stderr);
// #endif
	fastio();
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
 
}
