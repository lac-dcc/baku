#include <bits/stdc++.h>
using namespace std;
 
 
int editDis(string &word1, string &word2, int n1, int n2, vector<vector<int>> &dp)
{
 
    if (n1 == 0)
        return n2;
    if (n2 == 0)
        return n1;
 
    if (dp[n1][n2] != -1)
    {
        return dp[n1][n2];
    }
    if (word1[n1 - 1] == word2[n2 - 1])
    {
        dp[n1][n2] = editDis(word1, word2, n1 - 1, n2 - 1,dp);
        return dp[n1][n2];
    }
 
    dp[n1][n2] = 1 + min(editDis(word1, word2, n1, n2 - 1,dp),
                         min(editDis(word1, word2, n1 - 1, n2,dp),
                             editDis(word1, word2, n1 - 1, n2 - 1,dp)));
    return dp[n1][n2];
}
 
int main()
{
 
    string s, p;
    cin >> s >> p;
    
    vector<vector<int>> dp(s.size()+1, vector<int> (p.size()+1,-1));
 
    int ans = editDis(s, p, s.size(), p.size(),dp);
    cout<<ans<<endl;
 
    return 0;
}
