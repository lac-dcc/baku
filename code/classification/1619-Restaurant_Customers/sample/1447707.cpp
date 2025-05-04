#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long i64;
 
int main() {
  int n;
  scanf("%d", &n);
  n *= 2;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i += 2) {
    scanf("%d%d", &v[i].first, &v[i + 1].first);
    v[i].second = 1;
    v[i + 1].second = -1;
  }
  sort(v.begin(), v.end());
  int clients_num = 0, client_max = 0;
  for (int i = 0; i < n; i++) {
    clients_num += v[i].second;
    if (client_max < clients_num) {
      client_max = clients_num;
    }
  }
  printf("%d\n", client_max);
  return 0;
}
