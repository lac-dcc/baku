#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> price(n + 1), pages(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> price[i]; 
    }
    for(int i = 1; i <= n; i++) {
        cin >> pages[i];
    }
 
    // dp[n][k] ->  pages can be bought from n books an k money   
    
    int dp[n + 1][k + 1];
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            if(i == 0 or j == 0) {
                dp[i][j] = 0;
            } else {
                int opt1 = (i == 1) ? 0 : dp[i - 1][j]; 
                int opt2 = (price[i] > j) ? 0 : pages[i] + dp[i - 1][j - price[i]];
                dp[i][j] = max(opt1, opt2);
            }
        }
    }
    cout << dp[n][k] << "\n";
 
    return 0;
}