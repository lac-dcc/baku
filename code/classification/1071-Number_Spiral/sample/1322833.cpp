#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long x,y;
		cin>>x;
		cin>>y;
		if(x<y)
		{
			long long ans;
			if(y%2==0)
			{
				ans=(y-1)*(y-1)+x;
			}
			else
			{
				ans=(y*y)-x+1;
			}
			cout<<ans<<endl;
		}
		else
		{
			long long ans;
			if(x%2==0)
			{
				
				ans=(x*x)-y+1;
	     	}
	     	else
	     	{
	     		ans=(x-1)*(x-1)+y;
			 }
			 cout<<ans<<endl;
	}
	
}
}
