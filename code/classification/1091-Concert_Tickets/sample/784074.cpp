#include <bits/stdc++.h>
#include <functional>
#include <set>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
 
  int N, M;
  cin >> N >> M;
 
  multiset<int, greater<int>> tickets;
 
  for (int i = 0; i < N; ++i) {
    int tick_cost;
    cin >> tick_cost;
    
    tickets.insert(tick_cost);
  }
 
  for (int i = 0; i < M; ++i) {
    int cust_max;
    cin >> cust_max;
 
    auto lower = tickets.lower_bound(cust_max);
 
    if (lower != tickets.end()) {
      cout << *lower << '\n';
      tickets.erase(lower);
    } else {
      cout << "-1\n";
    }
  }
 
 
  return 0;
}
