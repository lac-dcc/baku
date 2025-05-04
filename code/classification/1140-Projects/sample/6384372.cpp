#include<bits/stdc++.h>
 
using namespace std;
 
#define read() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define day() time_t now = time(0);char* x = ctime(&now);cerr<<"Right Now Is : "<<x<<"\n"
 
#define int long long
#define ii pair<int,int>
#define X first
#define Y second 
 
const long long MAX = (int)1e6 + 5;
const long long INF = (int)1e9;
const long long MOD = (int)1e9 + 7;
 
struct node{
	int l,r,val;
};
 
node a[MAX];
int n;
int dp[MAX];
int res = 0;
vector<ii> adj[MAX];
 
signed main(){
	
	read();
	
	cin >> n;
	
	vector<int> rt;
	for(int i = 1,l,r,val;i <= n;i++){
		cin >> l >> r >> val;
		rt.push_back(l);
		rt.push_back(r);
		a[i] = {l,r,val};
	}
	
	sort(rt.begin(),rt.end());
	rt.erase(unique(rt.begin(),rt.end()),rt.end());
	
	for(int i = 1;i <= n;i++){
		a[i].l = lower_bound(rt.begin(),rt.end(),a[i].l) - rt.begin() + 1;
		a[i].r = lower_bound(rt.begin(),rt.end(),a[i].r) - rt.begin() + 1;
		adj[a[i].r].push_back({a[i].l,a[i].val});
	}
 
	for(int i = 1;i <= 2 * n;i++){
		dp[i] = dp[i - 1];
		for(auto e : adj[i]){
			int l = e.X;
			int val = e.Y;
			dp[i] = max(dp[i],dp[l - 1] + val);
		}
		res = max(res,dp[i]);
	}
	
	cout << res;
}
 
 
 
