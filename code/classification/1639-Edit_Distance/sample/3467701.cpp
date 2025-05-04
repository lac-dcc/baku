#include <bits/stdc++.h>
using namespace std;
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    string A, B;
    cin >> A >> B;
    int a = A.size();
    int b = B.size();
 
    vector dp(a+1, vector<int>(b+1, 0));
 
    for(int i = 0;i<=a; ++i){
        for(int j = 0;j<=b; ++j){
            if(i == 0 || j == 0){
                dp[i][j] = i + j;
                continue;
            }
            if(A[i-1] == B[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
            }
        }
    }
    cout << dp[a][b] << '\n';
    return 0;
}
