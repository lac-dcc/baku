#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
 
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll y, x;
		cin>>y>>x;
		ll total, ans;
		if(y>= x)
		{
			x--;
			if(y%2 == 0)
			{
				total = y*y;
				ans = total - x;
			}
			else
			{
				total = (y-1)*(y-1);
				total++;
				ans = total + x;
			}
		}
		else
		{
			y--;
			if(x%2 == 0)
			{
				total = (x-1)*(x-1);
				total++;
				ans = total + y;
			}
			else
			{
				total = x*x;
				ans = total - y;
			}
		}
		cout<<ans<<"\n";
	}
}
