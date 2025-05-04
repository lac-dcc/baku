/*
     বিসমিল্লাহ্
*/
 
#include <bits/stdc++.h>
 
using namespace std;
#define FastIO         ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define int            long long int
#define F              first
#define S              second
#define pb             push_back
#define mp             make_pair
#define si             set <int>
#define vi             vector <int>
// #define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define nl             "\n"
#define INF            1000000000
#define INF18          1e18
#define sz(x)          ((int) x.size())
#define all(p)         p.begin(), p.end()
#define double         long double
#define que_max        priority_queue <int>
#define que_min        priority_queue <int, vi, greater<int>>
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)       for(auto x : a) cout << x << " "; cout << endl
#define print1(a)      for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl
 
//COIN CHANGE PROBLEM
#define MAX_N 101
#define MAX_X 1000010
#define EMPTY_VALUE 0
int const  mod =  1e9+7;
 
 
//------------------------Start Here-----------------------//
 
 
int coin[MAX_N];
// int dp[MAX_X];//It stores the count of taken coin
int n;// Number of total Coin
 
int CoinChange( int TargetWeight )
{
	vector<int>dp(TargetWeight+10,0);
	dp[0] = 1;
 
	for( int i = 0 ; i < n ; i++ )
	{
		for( int j = 1 ; j <= TargetWeight ; j++ )
		{
			if( j-coin[i] >= 0 )
			{
				dp[j] = (dp[j]+dp[j-coin[i]])%mod;
			}
		}
	}
	return dp[TargetWeight];
}
 
void solve() {
	int x;
	cin>>n>>x;
	for( int i = 0 ; i < n ; i++ )
	{
		cin>>coin[i];
	}
	int ans = CoinChange(x);
	if( ans != INF )
	{
		cout<<ans<<nl;
	}
	else
	{
		cout<<"-1"<<nl;
	}
	
 
}
 
 
//------------------------Main-----------------------//
int32_t main()
{
	FastIO;
/*#ifndef ONLINE_JUDGE
	freopen("input.txt",  "r",  stdin);
	freopen("output.txt", "w", stdout);
#endif*/
 
	//clock_t z = clock();
 
 
	int t = 1;
	// cin >> t;
	while (t--) solve();
 
 
	//cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
	
	return 0;
}