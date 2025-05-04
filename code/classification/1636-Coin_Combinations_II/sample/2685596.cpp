// Vivek Rai
// Blazer_007
 
#include <bits/stdc++.h>
using namespace std;
 
#define pb          push_back
#define endl        '\n'
#define sz(x)       (int)x.size()
#define all(a)      begin(a),end(a)
 
using ll = long long int;
using vi = vector<int>;
using vl = vector<ll>;
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using mi = map<int,int>;
using ml = map<ll,ll>;
 
const int hell = 1e9 + 7;
const int mod  = 998244353;
const int N = 1e6 + 6;
 
template <typename T>
istream &operator>>(istream &in, vector<T> &arr)
{
    for(int i = 0 ; i < arr.size() ; i++)
        cin >> arr[i];
    return in;
}
 
template <typename T>
ostream &operator<<(ostream &os, vector<T> arr)
{
    for(int i = 0 ; i < arr.size() ; i++)
        cout << arr[i] << " ";
    cout << endl;
    return os;
}
 
int n, x;
ll dp[ N ];
 
int DP(vi& coins, int idx, int req_sum, vector<vi>& dp)
{
    // Not Working
    if (req_sum < 0 || idx >= sz(coins))
        return 0;
    if (req_sum == 0)
        return 1;
    if (dp[idx][req_sum] != -1)
        return dp[idx][req_sum];
    dp[idx][req_sum] = 0;
    return dp[idx][req_sum] = DP(coins, idx, req_sum - coins[idx], dp) + DP(coins, idx + 1, req_sum, dp);
}
 
void solve()
{
    cin >> n >> x;
    vi coins(n);
    cin >> coins;
    dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int weight = 0; weight <= x; weight++) {
			if(weight - coins[i - 1] >= 0) {
				dp[weight] += dp[weight - coins[i - 1]];
				dp[weight] %= hell;
			}
		}
	}
	cout << dp[x] << '\n';
}
 
signed main()
{
 
#ifndef ONLINE_JUDGE
    freopen("F:/Code/input.txt", "r", stdin);
    freopen("F:/Code/output.txt", "w", stdout);
#endif
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int testcase = 1;
    // cin >> testcase;
    while (testcase--)
    {
        solve();
    }
 
    return 0;
}
