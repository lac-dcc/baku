#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;cin>>n;
	vector<long int> vec(n);
	for(int i=0;i<n;i++)
	{
		cin>>vec[i];
	}
	long int max_sum=INT_MIN;
	long int sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=vec[i];
		max_sum=max(max_sum,sum);
		if(sum<=0)
		sum=0;
	}
	cout<<max_sum<<endl;
}
