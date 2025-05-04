#include<iostream>
using namespace std;
 
int main()
{
 
	int t;
	long int x,y;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>x>>y;
		if(x>=y)
		{
			if(x%2==1)
			{
				cout<<x*x-2*(x-1)+y-1<<'\n';
			}
			else cout<<x*x-y+1<<'\n';
		}
		else
		{
			if(y%2==1)cout<<y*y-x+1<<'\n';
			else cout<<y*y-2*(y-1)+x-1<<'\n';
		}
	}
	return 0;
}
