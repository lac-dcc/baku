#include <bits/stdc++.h>
 
using namespace std;
const int MAXK = 22;
long long n, a[MAXK];
int k;
 
int main()
{
	scanf("%lld %d", &n, &k);
	for(int i = 0; i < k; ++i)
		scanf("%lld", &a[i]);
	long long ans = 0;
	for(int i = 1; i < (1 << k); ++i)
	{
		bool ok = true;
		long long prod = 1;
		for(int j = 0; j < k && ok; ++j)
			if(i & (1 << j))
			{
				if(n / prod < a[j])
					ok = false;
				prod *= a[j];
			}
		if(!ok)
			continue;
		if(__builtin_popcount(i) % 2 == 1)
			ans += n / prod;
		else
			ans -= n / prod;
	}
	printf("%lld\n", ans);
}