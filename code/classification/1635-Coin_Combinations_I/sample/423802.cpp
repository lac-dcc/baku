#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
int main()
{	cin.tie(NULL);
	int n,x;
	cin>>n>>x;
	int coins[n];
	for(int i=0;i<n;i++)
	cin>>coins[i];
	//ll count[x+1]={0};
	vector<ll> count(x + 1, 0); 
	ll m=1000000007;
	count[0]=1;
	for(int i=1;i<=x;i++)
	{	for(int p=0;p<n;p++)
		{if(i-coins[p]>=0)
		count[i]=(count[i]+count[i-coins[p]])%m;
		}
	}
	cout<<count[x]<<"\n";
}
 
