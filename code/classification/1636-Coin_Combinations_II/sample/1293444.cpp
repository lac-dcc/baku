#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <array>
#include <cmath>
using namespace std;
typedef long long ll;
const int M = 1e9 + 7;
 
int main() {
    int n, x;
    cin >> n >> x;
    int coins[n];
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
 
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
 
    for (int j = 0; j < n; j++) {
        for (int i = 1; i <= x; i++) {
            if (coins[j] <= i) {
                dp[i] = (dp[i] + dp[i - coins[j]]) % M;
            }
        }
    }
 
    cout << dp[x] << endl;
}