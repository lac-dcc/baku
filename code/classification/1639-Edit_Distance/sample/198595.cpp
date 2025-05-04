#include<bits/stdc++.h>
using namespace std;
    
    vector<vector<int>> dp(5001, vector<int>(5001, -1));
    int minDistance(const string& a, const string& b, int m, int n) {
        if(m < 0 && n < 0) {
            return 0;
        }
        if(m < 0)
            return n + 1;
        if(n < 0)
            return m + 1;
        if(dp[m][n] != -1)
            return dp[m][n];
        auto& res = dp[m][n];
        if(a[m] == b[n])
            return res = minDistance(a,b,m-1,n-1);
        res = minDistance(a, b, m-1, n-1);
        res = min(res, min(minDistance(a, b, m-1, n), minDistance(a, b, m, n-1))) + 1;
        return res;
    }
    int minDistance(const string& word1, const string& word2) {
        return minDistance(word1, word2, word1.length() - 1, word2.length() - 1);
    }
 
 
    int main() {
        string a, b;
        cin >> a >> b;
        cout << minDistance(a, b);
        return 0;
    }