#include <iostream> 
#include <algorithm>
#include <set>
#include <utility> 
#include <vector>
std::vector <std::pair <int, int> > a; 
std::multiset <int> S; 
int n, k; 
 
bool comp(std::pair <int, int> a, std::pair <int, int> b) {
  return (a.second < b.second);
}
 
int main () {
  std::cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    std::pair <int, int> movie; 
    std::cin >> movie.first >> movie.second;
    a.push_back(movie); 
  }
  std::sort(a.begin(), a.end(), comp); 
  for (int i = 1; i <= k; i++) {
    S.insert(0); 
  }           
  int ans = 0; 
  for (int i = 0; i < n; i++) {
    std::multiset <int>::iterator it = S.upper_bound(a[i].first); 
    if (it != S.begin()) {
      ans++;
      it--; 
      S.erase(it); 
      S.insert(a[i].second); 
    }
  }
  std::cout << ans; 
  return 0; 
}