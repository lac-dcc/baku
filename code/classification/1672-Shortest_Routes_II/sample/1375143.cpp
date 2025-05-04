#include <iostream>
#include <climits>
#include <algorithm>
 
using namespace std;
 
const long long INF = 1ll << 50ll;
 
int main()
{
  int n, m, q;
  cin >> n >> m >> q;
  long long arr[n][n];
  for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
          arr[i][j] = INF;
      }
      arr[i][i] = 0;
  }
  for (int i = 0; i < m; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      a--;
      b--;
      if (c < arr[a][b]) {
          arr[a][b] = c;
          arr[b][a] = c;
      }
  }
  for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
              arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
          }
      }
  }
  for (int i = 0; i < q; i++) {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      if (arr[a][b] == INF) {
          arr[a][b] = -1;
      }
      cout << endl << arr[a][b] << endl;
  }
  return 0;
}
