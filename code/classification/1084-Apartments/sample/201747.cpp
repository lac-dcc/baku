#include<iostream>
#include<vector>
#include<algorithm>
 
 
using namespace std;
 
 
int main()
{
	int n, m, k, num;
	cin>>n>>m>>k;
 
	vector<int> demand;
	vector<int> avail;
 
	for(int i = 0; i<n; i++)
	{
		cin>>num;
		demand.push_back(num);
	}
 
	for(int i = 0; i<m; i++)
	{
		cin>>num;
		avail.push_back(num);
	}
 
	sort(demand.begin(), demand.end());
	sort(avail.begin(), avail.end());
 
	int ans = 0;
	int j = 0;
	for(int i = 0; i<n and j<m; i++)
	{
		int least = demand[i]-k;
		int max = demand[i]+k;
 
 
		while(j<m and not(avail[j]>=least) )
		{
			j++;
 
		}
 
		if(j<m)
		{
			if(avail[j]>=least and avail[j]<=max)
			{
				ans+=1;
				j+=1;
			}
		}
		else
			break;
	}
 
	cout<<ans;
}