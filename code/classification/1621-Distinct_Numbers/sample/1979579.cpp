#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
using namespace std;
 
long long int n , val;
int con;
set<long long int>s;
 
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> val;
		s.insert(val);
	}
	cout << s.size();
	return 0;
}
