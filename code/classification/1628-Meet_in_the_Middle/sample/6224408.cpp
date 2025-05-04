/**              _         ___                       _
 *              | |    _  /  _|                     | |                        _
 *              | |   |_| | |  _____     ____    ___| |__    __ _____  _____  | |   _   _  ____  _____  ____
 *    author:   | |    _ [   ]/  _  \   /  _ \  /  _  |\ \  / //  _  \|  _  \[   ] | | | ||  __|/  _  \|  __|
 *              | L__ | | | | | ____|   | |_\ \ | |_| | \ \/ / | ____|| | | | | |_ | |_| || /   | ____|| /
 *              L____||_| |_| \_____|   \____\_\\_____/  \__/  \_____||_| |_| |___|\_____/|_|   \_____||_|
 *
 *    Life is an adventure. Be adventurous.
 *
 *    created: 07.Jun.2023
 *
**/
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n, x;
  cin >> n >> x;
    
  vector<int> v(n);
  for(int i = 0; i < n; ++i){
    cin >> v[i];
  }
    
  auto subset = [&](int l, int r) -> vector<long long>{
    int len = r - l + 1;
        
    vector<long long> res;
    for(int i = 0; i < (1 << len); ++i){
      long long sum = 0;
      for(int j = 0; j < len; ++j){
        if(i & (1 << j)) sum += v[l + j]; 
      }
      res.push_back(sum);
    }
        
    return res;
  };
    
  vector<long long> left = subset(0, n / 2 - 1);
  vector<long long> right = subset(n / 2, n - 1); 
  sort(all(left));
  sort(all(right));
    
  long long ans = 0;
  for(auto it : left){
    int l = lower_bound(all(right), x - it) - right.begin();
    int r = upper_bound(all(right), x - it) - right.begin();
    ans += r - l;
  }
    
  cout << ans << '\n';
 
  return 0;
}
 
/**
 *        "To stop trying is never the solution."
 *        "You are not alone. Smiling<3 is with you."
 *        "Failure is another blessing. Only by accepting it calmly can it bring growth."
**/
 
// Be awesome !
// fighting~
// I will fulfill my dreams!
