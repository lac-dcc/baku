#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
#define print(A) for(auto item: A) cout << item << " "; cout << endl;
#define pb push_back
#define vvi vector<vector<int>>
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<pair<int,int>>
#define vl vector<long long int>
#define vvl vector<vector<long long int>>
#define MOD 1000000007
#define INF_INT 1000000001
#define MAX_N 1000001
 
int main() {
    string a, b;
    cin >> a >> b;
 
    int n = a.length();
    int m = b.length();
 
    vvi dp(n+1, vi(m+1, INF_INT));
    for(int i = 0; i <= m; i++) dp[0][i] = i;
    for(int i = 0; i <= n; i++) dp[i][0] = i;
 
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
            dp[i][j] = min(dp[i][j], 1+dp[i-1][j]);
            dp[i][j] = min(dp[i][j], 1+dp[i][j-1]);
            dp[i][j] = min(dp[i][j], 1+dp[i-1][j-1]);
        }
    }
  
    cout << dp[n][m] << "\n";
    return 0;
}
 