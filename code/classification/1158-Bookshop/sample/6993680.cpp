#include <iostream>
 
using namespace std;
 
const char ENDL = '\n';
 
void ans()
{
	int n;
	int x;
	cin >> n >> x;
	int h[n];
	int s[n];
	for (int i = 0; i < n; i++)
	{
		cin >> h[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	int lim = x + 1;
	int cnts[lim];
	fill(cnts, cnts + lim, 0);
	for (int i = 0; i < n; i++)
	{
		int cur[lim];
		for (int j = 0; j < lim; j++)
		{
			cur[j] = cnts[j];
		}
		for (int j = 0; j < lim; j++)
		{
			if (j + h[i] < lim)
			{
				cnts[j + h[i]] = max(cnts[j + h[i]], cur[j] + s[i]);
			}
		}
	}
	int res = cnts[lim - 1];
	cout << res << ENDL;
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ans();
	return 0;
}
