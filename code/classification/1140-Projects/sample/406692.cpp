#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define rando mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define fi first
#define se second
#define debug(x) cerr << " - " << #x << ": " << x << endl;
#define debugs(x, y) cerr << " - " << #x << ": " << x << " " << #y << ": " << y << endl;
#define debugii(x) cerr << " - " << #x << ": " << x.fi<<","<<x.se << endl;
#define sep() cerr << "--------------------" << endl;
#define all(x) (x).begin(),(x).end()
#define sz(x) (ll)x.size()
#define ld long double
#define ll long long
#define int ll
#define ii pair<int,int>
#define v vector<int>
#define vii vector<ii>
#define vv vector<vector<ii> >
#define mp make_pair
#define INF 1000000000
#define pb push_back
#define EPS 1e-9
const int MOD = 1000000007; // 998244353
int A[200002],B[200002],p[200002],dp[400002],h,idx;
map<int,int> to_idx;
pair<ii,int> tab[200002];
vv vec;
int32_t main(){
	boost;
	//freopen(".in","r",stdin);
	int n;
	cin>>n;
	v g;
	for (int i = 0; i < n; ++i){
		cin>>tab[i].fi.fi>>tab[i].fi.se>>tab[i].se;
		to_idx[tab[i].fi.fi];
		to_idx[tab[i].fi.se];
	}
	for(auto &it:to_idx)it.se=h++;
	vec.resize(h);
	for (int i = 0; i < n; ++i)
		vec[to_idx[tab[i].fi.fi]].pb({to_idx[tab[i].fi.se],tab[i].se});
	for (int i = 0; i < h; ++i)
	{
		dp[i+1]=max(dp[i+1],dp[i]);
		for(auto it:vec[i])
			dp[it.fi+1]=max(dp[it.fi+1],dp[i]+it.se);
	}
	cout<<dp[h]<<"\n";
	return 0;
}
//long long
//array bounds
//special cases
//binary search
