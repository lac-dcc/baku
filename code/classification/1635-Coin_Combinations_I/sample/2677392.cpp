#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int maxN = 100;
const int maxX = 1e6;
const ll MOD = 1e9+7;
 
int N, X, c[maxN];
ll dp[maxX+1];
 
int main()
{
    cin >> N >> X;
 
    for(int i = 0; i < N; i++)
        cin >> c[i];
 
    dp[0] = 1;
    for(int i = 0; i < X; i++)
    {
        //dp[i] = 1;
        for(int j = 0; j < N; j++)
            if(i+c[j] <= X)
                dp[i+c[j]] = (dp[i+c[j]] + dp[i]) % MOD;
    }
 
    cout << dp[X] << "\n";
}