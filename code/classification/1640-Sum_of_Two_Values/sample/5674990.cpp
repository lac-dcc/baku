#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
ll a[1000001],p,n,ans,b[1000001];
 
int main ()
{
    ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
 
	int t=1;
	
	
	
	//cin >>t;
	while (t--)
	{
		cin >>n>>ans;
		for (int i=1;i<=n;i++)
		{
			cin >>a[i];
			b[i]=a[i];
		}
		
		sort (b+1,b+n+1);
		
		int i=1,p1=0;
		int j=n,p2=0;
		
		while (i<j)
		{
			if (b[j]+b[i]==ans)
			{
				p=1;
				p1=i;
				p2=j;
				break;
			}
			else
			if (b[j]+b[i]>ans)
			{
				j--;
			}
			else
			if (b[j]+b[i]<ans)
			{
				i++;
			}
		}
		int q1=0,q2=0;
		
		if (p!=1)
		cout <<"IMPOSSIBLE";
	    else
	    {
	    	for (int i=1;i<=n;i++)
	    	{
	    		if (a[i]==b[p1] && q1==0)
	    		{
	    			q1=i;
				}
				else
				if (a[i]==b[p2] && q2==0)
				{
					q2=i;
				}
			}
			
			cout <<q1<<" "<<q2;
			
		}
	}
	
	
}
 
 
 
 
 