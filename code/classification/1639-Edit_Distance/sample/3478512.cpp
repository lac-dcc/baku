#include <bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
 
#define int long long
#define endl '\n' // Remove if Interactive Question
#define mod 1000000007
#define inf 1e18
#define vi vector<int>
#define vvi vector<vector<int>>
#define pi pair<int, int>
#define vpi vector<pi>
#define mii map<int,int>
#define REP(i,x,y) for(int i = x;i < y;i++)
#define F first
#define S second
#define EB emplace_back
#define PRES(c,x) ((c).find(x) != (c).end())
 
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<std::string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;
 
void c_p_c()
{
	clock_t begin = clock();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
void c_p_c2()
{
	clock_t begin = clock();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
 
void solve()
{
	string s1, s2;
	cin >> s1 >> s2;
	int na = s1.size();
	int nb = s2.size();
	vector<vector<int>> dp(na+1, vector<int>(nb+1, 1e9));
	dp[0][0] = 0;
	for(int i = 0; i <= na; i++) {
		for(int j = 0; j <= nb; j++) {
			if(i) dp[i][j] = min(dp[i][j], 1 + dp[i-1][j]); // erase operation
			if(j) dp[i][j] = min(dp[i][j], 1 + dp[i][j-1]); // add operation
			if(i && j) dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (s1[i-1] != s2[j-1])); // change or no-change operation
		}
	}
	cout << dp[na][nb] << endl;
}
 
int32_t main()
{
	c_p_c();
 
	int t = 1;
	// cin>>t;
	for(int i = 0; i < t; i++)
	{
		solve();
	}
 
	c_p_c2();
}
