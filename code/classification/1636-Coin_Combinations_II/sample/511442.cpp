#include<iostream>
#include<vector>
#include<algorithm>
 
using namespace std;
int ways[1000005];
int n;
 
#define MOD int(1e9+7)
vector<int> coins;
#define INF 1e9
 
 
 
int main()
{
	int x, temp; cin>>n>>x;
	
 
	for(int i = 0; i<n; i++)
	{
		cin>>temp; coins.push_back(temp);
	}
 
	vector<int> ways(x+1, 0);
	
	ways[0] = 1;
	
	vector<int> curWays = ways;
 
 
 
	for(int index = 0; index < n; ++index)
	{
		int curCoin = coins[index];
		
		for(int val = 1; val <= x; ++ val)
		{
			int withWays = 0;
			int withOutWays = ways[val];
 
			if(curCoin <= val)
			{
				withWays = curWays[val - curCoin];
			}
 
			curWays[val] = (withWays + withOutWays) % MOD;
		}
		ways = curWays;
	}
	cout<<ways[x];
 
	return 0;
}