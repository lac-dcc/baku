#include <iostream>
using namespace std;
 
int main() {
  long long t;
  long long x;
  long long y;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> y;
    cin >> x;
    if (y > x) {
      if (y % 2 == 0) {
	cout << (y * y - x + 1) << " ";
      }
      else {
	cout << ((y - 1) * (y - 1)  + x) << " ";
      }
    }
    else {
      if (x % 2 == 1) {
	cout << (x * x - y + 1) << " ";
      }
      else {
	cout << ((x - 1) * (x - 1)  + y) << " ";
      }
    }
  }
}
    