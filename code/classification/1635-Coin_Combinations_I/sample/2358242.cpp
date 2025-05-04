/**
 *    author:  Tanbin_Hasan
 *    created: 17.06.2021 23:17:39
**/
#include <bits/stdc++.h>
 
using namespace std ;
 
vector<int64_t> val(1000001) ;
bitset<1000001> mark ;
int64_t TotalWay(vector<int64_t> &coin , int64_t x) {
  if (x < 0) {
    return 0 ;
  }
  if (!x) {
    return 1 ;
  }
  if (mark[x]) {
    return val[x] ;
  }
  int64_t way = 0 ;
  for (auto &i : coin) {
    if (x - i >= 0) {
      way = ((way % 1000000007) + TotalWay(coin , x - i) % 1000000007) % 1000000007 ;
    }
  }
  mark[x] = 1 ;
  return val[x] = way ;
} 
 
int main(void) {
  ios::sync_with_stdio(false) ; cin.tie(0) ;
  int64_t n , x ;
  cin >> n >> x ;
  vector<int64_t> coin(n) ;
  for (auto &i : coin) {
    cin >> i ;
  }
  cout << TotalWay(coin , x) ;
  return 0 ;
}