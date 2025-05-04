#include <bits/stdc++.h>
#include <map>
#define mod 1e9
using namespace std;
typedef long long ll;
 
const int maximo = 5005;
int movements[maximo][maximo];
 
int main() {
	string str1, str2;
	cin >> str1 >> str2;
 
  for (int i=0;i<str2.length()+1;i++) {
    movements[0][i] = i;
	}
	for (int i=0;i<str1.length()+1; i++) {
    movements[i][0] = i;
  }
 
  for (int i=1;i<str1.length()+1; i++) {
    for (int j=1;j<str2.length()+1; j++) {
      movements[i][j] = mod;
      movements[i][j] = min({movements[i-1][j-1] + (str1[i-1] != str2[j-1]), movements[i-1][j]+1, movements[i][j-1]+1});
    }
  }
 
  
	cout << movements[str1.length()][str2.length()] << endl;
 
  return 0;
}