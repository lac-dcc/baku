#include <iostream>
 
#define MOD 1000000007
 
int main()
{
	// note that the number j occurs n / j times in the sum
	uint64_t n;
	std::cin >> n;
 
	uint64_t sum = 0;
	
	for (uint64_t i = 1; i <= n; i = n / (n / i) + 1)
	{
		uint64_t k = n / i;
 
		uint64_t a = n / k; // We now want to sum from i to a. This is a*(a+1)/2 - i*(i-1)/2 = a^2 + a - i^2 + i / 2 = (a+i)(a-i+1)/2
 
		uint64_t x = (a + i), y = (a - i + 1);
		if (x % 2 == 0) x = x / 2;
		else y = y / 2;
 
		sum = (sum + (k % MOD) * (((x % MOD) * (y % MOD)) % MOD)) % MOD;
	}
 
	std::cout << sum << std::endl;
	std::system("pause");
}
