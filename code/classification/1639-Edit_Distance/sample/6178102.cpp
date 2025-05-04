//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <limits>
 
using namespace std;
 
typedef long long LL;
//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI = acos(-1.0);
const int INF = (int)1000000007;
const LL MOD = (LL)1000000007;//10^9+7
const LL INF2 = (LL)100000000000000000;//10^18
 
int main() {
	string s, t; cin >> s >> t;
	int n = s.size(); int m = t.size();
	vector<vector<int>> dp(n+1, vector<int>(m+1,INF));
	dp[0][0] = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]+1);
			int c = 0;
 
			if (s[i] != t[j]) {
				c++;
			}
			dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + c);
			
			dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
		}
	}
 
	int ans = INF;
	for (int j = 0; j <= m; j++) {
		ans = min(ans, dp[n][j] + (m - j));
	}
	cout << ans << endl;
	return 0;
}