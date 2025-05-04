#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
 
int main()
{
	int N;
	cin >> N;
	vector<long long> x(N + 1);
 
	x[0] = 0;
	for (int i = 1; i <= N; i++)
		cin >> x[i], x[i] += x[i - 1];
 
	long long min_left = 0;
	long long max_sum = LLONG_MIN;
	for (int i = 1; i <= N; i++)
	{
		max_sum = max(max_sum, x[i] - min_left);
		min_left = min(min_left, x[i]);
	}
 
	cout << max_sum << endl;
 
	return 0;
}