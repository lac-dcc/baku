#include <bits/stdc++.h>
 
#define ll long long
#define LIM 1000005
#define X first
#define Y second
#define EL cout<<"\n"
 
using namespace std;
 
const int M = 1e9 + 7;
 
int n, x;
int c[LIM], dp[LIM];
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("TASK.INP", "r", stdin);
    freopen("TASK.OUT", "w", stdout);
    #endif
 
    cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> c[i];
 
    sort(c + 1, c + 1 + n);
 
    dp[0] = 1;
 
    for (int i = 1; i <= x; i++)
    	for (int j = 1; j <= n; j++)
    		if (c[j] <= i) 
    			dp[i] = (dp[i] + dp[i - c[j]]) % M;
 
    cout << dp[x];
 
 
 
    return 0;
}
 
    
    