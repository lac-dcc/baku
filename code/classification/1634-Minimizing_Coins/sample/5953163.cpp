#include <iostream>
 
using namespace std;
 
const int MAXN = 1e2 + 1;
const int MAXX = 1e6 + 1;
 
int N, X;
int c[MAXN];
int dp[MAXN][MAXX];
 
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
 
  cin >> N >> X;
 
  for(int i = 1; i <= N; i++)
    cin >> c[i];
  
  for(int i = 0; i <= X; i++)
    dp[0][i] = 0x3f3f3f3f;
  
  for(int i = 0; i <= N; i++)
    dp[i][0] = 0;
 
  for(int i = 1; i <= N; i++)
  {
    for(int j = 1; j <= X; j++)
    {
      if(j - c[i] >= 0) {
        dp[i][j] = min(dp[i][j - c[i]] + 1, dp[i - 1][j - c[i]] + 1);
        dp[i][j] = min(dp[i][j], dp[i - 1][j]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  
  cout << (dp[N][X] == 0x3f3f3f3f ? -1 : dp[N][X]) << endl;
 
  return 0;
}