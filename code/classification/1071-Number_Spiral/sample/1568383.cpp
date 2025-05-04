#include<bits/stdc++.h>
using namespace std;
 
long long int find(long long int r,long long int c)
{   long long int ans=0;
	int m=max(r,c);
	if(m==r)
	{
		ans=(r*r)-(c-1);
	}
	else
	ans=1+((c-1)*(c-1))+(r-1);
	
	return ans;
}
 
 
int main()
{
	int t;
	cin>>t;
	
	for(long long int i=0;i<t;i++)
	{
		long long int y,x;
		cin>>y>>x;
		
		long long int c=max(y,x);
		
		long long int res=0;
		
		if(c%2==0)
		res=find(y,x);
		else
		res=find(x,y);
		
		cout<<res<<"\n";
	}
}
 