#include <iostream>
 
using namespace std;
 
long long search(long long x, long long y);
int main()
{
	int n;
	cin >> n;
	long long *result = new long long[n];
	for (int i = 0; i < n; i++)
	{
		long long x, y;
		cin >> y >> x;
		result[i] = search(x, y);
	}	
	for (int i = 0; i < n; i++)
		cout << result[i] << endl;
	delete[]result;
	return 0;
}
long long search(long long x, long long y) {
	if (x > y) {
		if (x % 2 == 0)
			return (x - 1) * (x - 1) + y;
		else
			return x * x - y + 1;
	}
	else {
		if (y % 2 == 0)
			return y * y - x + 1;
		else
			return (y - 1)*(y - 1) + x;
	}
	
}