#include<iostream>
 
using namespace std;
 
int DP[5001][5001];
 
string s1, s2;
 
int solve(int i1, int i2){
    if(DP[i1][i2] >= 0){
        return DP[i1][i2];
    }
 
    if(i1 >= s1.length()){
        DP[i1][i2] = s2.length()-i2;
        return DP[i1][i2];
    }
 
    if(i2 >= s2.length()){
        DP[i1][i2] = s1.length()-i1;
        return DP[i1][i2];
    }
 
    int ans = 1000000;
    // Same letter => skip possible
    if(s1[i1] == s2[i2]) ans = min(ans, solve(i1+1,i2+1));
 
    // Add letter to either string and match, or alternatively remove one letter
    ans = min(ans, 1 + solve(i1+1,i2));
    ans = min(ans, 1 + solve(i1,i2+1));
 
    // Replace one letter and match
    ans = min(ans, 1 + solve(i1+1,i2+1));
 
    DP[i1][i2] = ans;
    return ans;
}
 
int main(int argc, char const *argv[])
{
    cin >> s1 >> s2;
 
    for (int i = 0; i <= s1.length(); i++)
    {
        for (int j = 0; j <= s2.length(); j++)
        {
            DP[i][j] = -1;
        }
    }
 
    cout << solve(0,0) << endl;
 
    /*
    for (int i = 0; i <= s1.length(); i++)
    {
        for (int j = 0; j <= s2.length(); j++)
        {
            cout << DP[i][j] << "\t";
        }
        cout << endl;
    }
    */
    return 0;
}
