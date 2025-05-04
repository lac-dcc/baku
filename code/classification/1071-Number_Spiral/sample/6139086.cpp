#include <bits/stdc++.h>
using namespace std;
int main()
{
  long t, y, x;
  cin >> t;
 
  while (t--)
  {
    cin >> y >> x;
    int num = 0;
    if (y >= x)
    {
      if (y % 2 == 0)
      {
        cout << (y * y) - x + 1 << endl;
      }
      else
      {
        cout << (y * y) - (2 * y) + x + 1 << endl;
      }
    }
    else
    {
      if (x % 2 == 0)
      {
        cout << (x * x) - (2 * x) + y + 1 << endl;
      }
      else
      {
        cout << (x * x) - y + 1 << endl;
      }
    }
  }
}
