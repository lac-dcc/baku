#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int editDistance(const string& str1, const string& str2) {
    int n = str1.length();
    int m = str2.length();
 
    // Create a 2D vector to store the edit distance values
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
 
    // Initialize the base cases
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            }
        }
    }
 
    return dp[n][m];
}
 
int main() {
    string str1, str2;
 
    // Input the two strings
    cin >> str1 >> str2;
 
    // Calculate and output the edit distance
    cout << editDistance(str1, str2) << endl;
 
    return 0;
}
