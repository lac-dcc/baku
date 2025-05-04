#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
const ll LL_INF = (ll)1e18 + 10;
const int MAXN = (int)5e2 + 10;
 
ll graph[MAXN][MAXN];
ll dist[MAXN][MAXN];
int n, m;
 
void floyd_warshall() {
  for (int v = 1; v <= n; v++) {
    for (int w = 1; w <= n; w++) {
      dist[v][w] = graph[v][w];
    }
  }
 
  for (int k = 1; k <= n; k++) {
    for (int a = 1; a <= n; a++) {
      for (int b = 1; b <= n; b++) {
        dist[a][b] = min(dist[a][b], dist[a][k] + dist[k][b]);
      }
    }
  }
}
 
int main() {
  int q, a, b;
  ll c;
  scanf("%d %d %d", &n, &m, &q);
  for (int v = 1; v <= n; v++) {
    for (int w = 1; w <= n; w++) {
      graph[v][w] = LL_INF;
    }
    graph[v][v] = 0;
  }
  while (m--) {
    scanf("%d %d %lld", &a, &b, &c);
    int best_edge = min(graph[a][b], c);
    graph[a][b] = graph[b][a] = best_edge;
  }
 
  floyd_warshall();
 
  while (q--) {
    scanf("%d %d", &a, &b);
    if (dist[a][b] < LL_INF) {
      printf("%lld\n", dist[a][b]);
    } else {
      printf("-1\n");
    }
  }
  return 0;
}
