#include <iostream>
#include <algorithm>
#include <map>
 
using namespace std;
int main() {
 
  int n, x;
  cin >> n >> x;
 
  map<int, int> m;
  int temp;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    if (m[x - temp]) {
      cout << m[x - temp] << " " << i + 1 << "\n";
      return 0;
    }
    m[temp] = i + 1;
  }
  cout << "IMPOSSIBLE";
}