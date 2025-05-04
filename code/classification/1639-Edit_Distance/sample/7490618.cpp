#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
    // read the input
    string word1, word2;
    cin >> word1 >> word2;
 
    // initialize the dp tables (prev, dp). First row is set.
    int n = word1.size();
    vector<int> prev(n + 1);
    vector<int> dp(n + 1);
    for (int i = 1; i < n + 1; i++)
        prev[i] = prev[i - 1] + 1;
 
    // build the dp table
    for (char ch: word2) {
        dp[0] = prev[0] + 1;
        for (int i = 1; i < n + 1; i++) {
            if (word1[i-1] == ch) {
                dp[i] = prev[i - 1];
                continue;
            }
            int removeChar1 = prev[i] + 1;
            int removeChar2 = dp[i - 1] + 1;
            int replace = prev[i - 1] + 1;
            int remove = min(removeChar2, removeChar1);
            dp[i] = min(replace, remove);
        }
        swap(dp, prev);
        fill(dp.begin(), dp.end(), 0);
    }
 
    cout << prev[n];
 
    return 0;
}
