// In the name of God
#include <bits/stdc++.h>
using namespace std;
 
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ll long long
#define ull unsigned long long
#define ld long double
#define vi vector<int>
#define si set<int>
#define pii pair<int,int>
#define mii map<int,int>
#define vii vector<pii>
#define sii set<pii>
#define vvi vector<vi>
#define vvii vector<vii>
#define vsi vector<si>
 
#define in(arr,n)     for(int mm=0;mm<n;mm++)cin>>arr[mm];
#define out(arr,n)    for(int mm=0;mm<n;mm++)cout<<arr[mm]<<" ";cout<<endl;
#define narr int arr[n]; in(arr,n)
#define nbrr int brr[n]; in(brr,n)
#define cin1(a)       int a; cin>>a;
#define cin2(a,b)     int a,b; cin>>a>>b;
#define cin3(a,b,c)   int a,b,c; cin>>a>>b>>c;
#define cin4(a,b,c,d) int a,b,c,d; cin>>a>>b>>c>>d;
#define fo(i,a,b)     for(int i=a;i<b;i++)
 
#define all(a) a.begin(), a.end()
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size()) 
#define nl "\n"
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define reset(a, b) memset(a, int(b), sizeof(a))
 
#define INF 1e18
const int MOD = 1e9+7;
const int MOD1 = 998244353;
const int N = 2*1e5+5;
 
vi g[N]; int d[N];
void dfs(int v, int p = 0){
	d[v] = d[p]+1;
	for(auto u:g[v]){
		if(u != p){
			dfs(u,v);
		}
	}
}
 
int diameter(int n){
	dfs(1); int mxN = -1;
	fo(i,1,n+1){
		if(d[i]>d[mxN]){
			mxN = i;
		}
		// d[i] = 0;
	}
	dfs(mxN); sort(d+1,d+n+1); return d[n];
}
 
signed  main(){
	fastio(); cin1(n); int m = n-1;
	while(m--){
		cin2(u,v); g[u].pb(v); g[v].pb(u);
	}
	d[0] = -1;
	cout<<diameter(n)<<nl;
	return 0;
}
//Thank God . . .
