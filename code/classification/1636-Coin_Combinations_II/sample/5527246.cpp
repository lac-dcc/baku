/*
 ▄████▄   █    ██  ██▀███    ██████ ▓█████ ▓█████▄     ███▄    █  ██▓ ███▄    █  ▄▄▄██▀▀▀▄▄▄
▒██▀ ▀█   ██  ▓██▒▓██ ▒ ██▒▒██    ▒ ▓█   ▀ ▒██▀ ██▌    ██ ▀█   █ ▓██▒ ██ ▀█   █    ▒██  ▒████▄
▒▓█    ▄ ▓██  ▒██░▓██ ░▄█ ▒░ ▓██▄   ▒███   ░██   █▌   ▓██  ▀█ ██▒▒██▒▓██  ▀█ ██▒   ░██  ▒██  ▀█▄
▒▓▓▄ ▄██▒▓▓█  ░██░▒██▀▀█▄    ▒   ██▒▒▓█  ▄ ░▓█▄   ▌   ▓██▒  ▐▌██▒░██░▓██▒  ▐▌██▒▓██▄██▓ ░██▄▄▄▄██
▒ ▓███▀ ░▒▒█████▓ ░██▓ ▒██▒▒██████▒▒░▒████▒░▒████▓    ▒██░   ▓██░░██░▒██░   ▓██░ ▓███▒   ▓█   ▓██▒
░ ░▒ ▒  ░░▒▓▒ ▒ ▒ ░ ▒▓ ░▒▓░▒ ▒▓▒ ▒ ░░░ ▒░ ░ ▒▒▓  ▒    ░ ▒░   ▒ ▒ ░▓  ░ ▒░   ▒ ▒  ▒▓▒▒░   ▒▒   ▓▒█░
  ░  ▒   ░░▒░ ░ ░   ░▒ ░ ▒░░ ░▒  ░ ░ ░ ░  ░ ░ ▒  ▒    ░ ░░   ░ ▒░ ▒ ░░ ░░   ░ ▒░ ▒ ░▒░    ▒   ▒▒ ░
░         ░░░ ░ ░   ░░   ░ ░  ░  ░     ░    ░ ░  ░       ░   ░ ░  ▒ ░   ░   ░ ░  ░ ░ ░    ░   ▒
░ ░         ░        ░           ░     ░  ░   ░                ░  ░           ░  ░   ░        ░  ░
░                                           ░
*/
 
#include <bits/stdc++.h>
using namespace std;
 
#define nl "\n"
#define ll long long int
#define INF int(1e9)
#define LINF 1e18
 
#pragma GCC optimize("O3")
//#pragma GCC target("sse4")
 
const int MOD = 1e9 + 7;
 
void solve(int tc)
{
	ll n, x;
	cin >> n >> x;
	ll a[n];
	for (ll &x : a)
		cin >> x;
	sort(a, a + n);
	vector<ll> dp(x + 1);
	dp[0] = 1;
	for (auto &v : a)
	{
		for (int i = 0; i <= x; i++)
		{
			if (i + v > x)
				break;
			dp[i + v] += dp[i];
			dp[i + v] %= MOD;
		}
	}
	cout << dp[x] << nl;
}
 
int main()
{
	// #ifndef ONLINE_JUDGE
	//     freopen("input.txt", "r", stdin);
	//     freopen("output.txt", "w", stdout);
	// #endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T = 1;
	// cin >> T;
	for (int t = 1; t <= T; t++)
	{
		// cout << "Case #" << t << ": ";
		solve(t);
	}
}
