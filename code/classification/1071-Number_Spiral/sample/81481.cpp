#include <iostream>
#include <cstring>
 
using namespace std;
 
int const nmax = 1000000;
#define MAX(a , b) ((a < b) ? b : a)
int main()
{
  int t;
  cin >> t;
  for(int i = 1 ; i <= t ;i++){
    int x , y;
    cin >> x >> y;
    long long result = 0;
    int row = MAX(x , y);
    result = 1LL * (row - 1) * (row - 1);
    if(row % 2 == 0){
      if(y == row)
        cout << result + x << '\n';
      else
        cout << result + x + (row - y) << '\n';
    } else{
      if(x == row){
        cout << result + y << '\n';
      } else
        cout << result + y + (row - x) << '\n';
    }
  }
  return 0;
}