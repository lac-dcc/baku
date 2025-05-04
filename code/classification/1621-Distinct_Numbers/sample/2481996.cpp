#include <bits/stdc++.h>
using namespace std;
 
int main() {
   int n;
   cin >> n;
   vector<int> a(n); // a: array
   for(int& v : a) // v: value
      cin >> v;
   sort(a.begin(),a.end());
   int nbd = 1; // nbd: nb distinct
   for(int i=1;i<n;i++)
      if(a[i]!=a[i-1])
         nbd++;
   cout << nbd << endl;
}