#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
 
int main()
{
	int n, a, b;
	cin >> n;
	vector<vector<int>> x(2 * n, vector<int>(2));
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		x[i] = { a,1 };;
		x[n + i] = { b,0 };
 
	}
	sort(x.begin(), x.end());
	int ans = 0;
	int current = 0;
 
	for (int i = 0; i < 2*n; i++) {
		if (x[i][1] == 1) {
			current++;
		}
		else current--;
		ans = max(current, ans);
	}
	cout << ans;
}
