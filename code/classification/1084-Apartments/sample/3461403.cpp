#include <iostream>
#include <algorithm>
#define MAX 200001
using namespace std;
int n, m, k;
int p[MAX], ap[MAX];
bool used[MAX];
int solve(){
  int l = 1, r = 1;
  int res = 0;
  while(l <= n && r <= m){
    if(abs(p[l] - ap[r]) <= k){
      l++, r++;
      res++;
    } else{
      if(p[l] - ap[r] > k){
        r++;
      } else{
        l++;
      }
    }
  }
  return res;
}
int main(){
  cin >> n >> m >> k;
  for(int i = 1; i <= n; i++) cin >> p[i];
  for(int i = 1; i <= m; i++) cin >> ap[i];
  sort(ap + 1, ap + m + 1);
  sort(p + 1, p + n + 1);
  cout << solve() << '\n';
}