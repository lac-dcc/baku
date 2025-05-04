#include<iostream>
using namespace std;
 
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	long long T; cin >> T;
	while (T--)
	{
		long long x, y;
		cin >> y >> x;
 
		if (x > y)
		{
			if (x % 2 != 0)
				cout << x * x - y + 1;
			else
			{
				x--; cout << x * x + y;
			}
		}
		else
		{
			if (y % 2 == 0)
				cout << y * y - x + 1;
			else
			{
				y--; cout << y * y + x;
			}
		}
		cout << "\n";
	}
 
	return 0;
}