#include "bits/stdc++.h"
using namespace std;
#define int int64_t
typedef array<int, 2> pii;
 
int32_t main(){
 int n, x; cin >> n >> x;
 vector<pii> v(n);
 for(int i = 0; i < n; ++i){cin >> v[i][0]; v[i][1] = i+1;}
 sort(v.begin(), v.end());
 for(int i = 0; i < n; ++i){
  for(int j = i+1; j < n; ++j){
   int l = n-1;
   for(int k = j+1; k < n && l > k; ++k){
    int s = v[i][0] + v[j][0] + v[k][0] + v[l][0];
    while(s > x && l > k) s -= v[l][0], s += v[--l][0];
    if(s == x && l > k){
     cout << v[i][1] << " " << v[j][1] << " " << v[k][1] << " " << v[l][1] << endl;
     exit(0);
    }
   }
  }
 }
 cout << "IMPOSSIBLE" << endl;
}
