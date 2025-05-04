#include <algorithm>
#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
  int n, m, k, cont = 0, jj = 0;
  int aux;
  vector<int> v1, v2;
 
  cin >> n >> m >> k;
 
  for (int ii = 0; ii < n; ii++) {
    cin >> aux;
    v1.push_back(aux);
  }
 
  for (int ii = 0; ii < m; ii++) {
    cin >> aux;
    v2.push_back(aux);
  }
 
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());
 
  for (int ii = 0; ii < n; ii++) {
    while(jj < m) {
      if (v1[ii] > v2[jj] + k)
        jj++;
      else if (v1[ii] < v2[jj] - k)
        break;
      else{
        jj++;
        cont++;
        break;
      }  
    }
  }
 
  cout << cont;
}
