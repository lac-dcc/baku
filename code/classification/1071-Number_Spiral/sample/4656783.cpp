#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  long long t;
  cin >> t;
 
  while(t--){
    long long x, y;
    cin >> y >> x;
 
    long long n = 2 * ((x-1)/2) + 1, ans;
    if(y <= x){
      if(x % 2 == 1)
        ans = n * n + 1 - y;
      else
        ans = n * n + y;
    }
    else{
        long long m = 2*(y / 2);
        if(y % 2 == 1)
          ans = m * m + x;
        else
          ans = m * m - (x - 1);
    }
 
    cout << ans << endl;
  }
}