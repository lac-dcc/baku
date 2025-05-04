#include <bits/stdc++.h>
 
void setmin(int& a, int b) {
    if (b < a) a = b;
}
 
int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
 
    string S, T; cin >> S >> T;
    int N = int(S.size());
    int M = int(T.size());
    std::vector<std::vector<int>> dp(N+1, vector<int>(M+1, N+M));
    dp[0][0] = 0;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            // add
            if (j < M) setmin(dp[i][j+1], dp[i][j] + 1);
            // remove
            if (i < N) setmin(dp[i+1][j], dp[i][j] + 1);
            // replace
            if (i < N && j < M) setmin(dp[i+1][j+1], dp[i][j] + int(S[i] != T[j]));
        }
    }
    cout << dp[N][M] << '\n';
 
    return 0;
}
 
// dp[i][j] = minimum # of operations to change S[0...i) to T[0...j)
