// ----- In the name of ALLAH, the Most Gracious, the Most Merciful -----
 
#include<bits/stdc++.h>
using namespace std;
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
#define NINJA ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k;i<n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define dloop(i,n) for(int i=n-1;i>=0;i--)
#define iii tuple<int,int,int>
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define int long long
#define ld long double
#define pb push_back
#define endl "\n"
#define setbits __builtin_popcountll
#define mp map<int,int>
#define F first
#define S second
#define sz(v) (int)v.size()
#define mod 1000000007
#define inf (int)1e18
 
const int mxn = 1010;
string a[mxn];
bool vis[mxn][mxn];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int n,m;
 
void dfs(int x, int y){
	vis[x][y] = 1;
	fo(i,4){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx < n and nx >=0 and ny < m and ny >= 0 and a[nx][ny]!='#' and !vis[nx][ny]) dfs(nx,ny);
	}
}
 
int32_t main(){
	NINJA;
	cin >> n >> m;
	fo(i,n) cin >> a[i];
	int cnt =0 ;
	fo(i,n){
		fo(j,m){
			if(!vis[i][j] and a[i][j]=='.'){
				dfs(i,j);
				cnt++;
			}
		}
	}
	cout << cnt << endl;
 
 
	return 0;
}
