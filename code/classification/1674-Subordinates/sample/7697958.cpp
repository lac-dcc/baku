#include <iostream>
#include <vector>
using namespace std;
 
const int MAXN = 2e5 + 5;
 
vector<int> subordinates[MAXN];
int numSubordinates[MAXN];
 
void dfs(int employee) {
numSubordinates[employee] = 1; // Initialize with self
for (int subordinate : subordinates[employee]) {
dfs(subordinate);
numSubordinates[employee] += numSubordinates[subordinate];
}
}
 
int main() {
int n;
cin >> n;
 
for (int i = 2; i <= n; i++) {
int boss;
cin >> boss;
subordinates[boss].push_back(i);
}
 
dfs(1);
 
for (int i = 1; i <= n; i++) {
cout << numSubordinates[i] - 1 << " "; // Exclude the employee itself
}
 
return 0;
}
