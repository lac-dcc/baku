#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
ll INF = 1LL << 62;
const ll MOD = 1e9 + 7;
ll arr[100] = { 0 };
ll nums[1000001] = { 0 };
 
 
 
int main()
{
	ll output, n, x, a, sum, number;
	
	arr[0] = 0;
	cin >> n >> x;
	for (long i = 0; i < n; i++)
	{
		cin >> a;
		arr[i] = a;
	}
 
	nums[0] = 0;
	for (long i = 1; i <= x; i++)
	{
		nums[i] = INF;
		for (long k = 0; k < n; k++)
		{	
			if (i >= arr[k])
			{
				number = nums[i - arr[k]];
				nums[i] = min(number + 1, nums[i]);
			}
		}
	}
	if (nums[x] == INF)
	{
		cout << "-1" << endl;
	}
	else
	{
		cout << nums[x] << endl;
	}
 
}
