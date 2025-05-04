#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
 
#define int long long
 
int n, target, ans = 0;
 
vector<int>arr;
 
int a[45];
 
void dfs2(int index, int sum)
{
	if(sum > target) return;
	
	if(index >= n + 1)
	{
		ans += upper_bound(arr.begin(), arr.end(), target - sum) - lower_bound(arr.begin(), arr.end(), target - sum);
		
		return;
	}
	
	dfs2(index+1, sum+a[index]);
	dfs2(index+1, sum);
	return;
}
 
void dfs1(int index, int sum)
{
	if(sum > target) return;
	
	if(index >= n/2 + 1)
	{
		arr.push_back(sum);
		return;
	}
	
	dfs1(index+1, sum+a[index]);
	
	dfs1(index+1, sum);
	
	return;
}
 
void solve()
{
	 cin >> n >> target;
	 
	 // 5  {1 2} {3 4 5}
	 
	 // 6 {1 2 3} {4 5 6}
	 
	 for(int i=1;i<=n;i++) cin >> a[i];
	 
	dfs1(1, 0);
	
	sort(arr.begin(), arr.end());
	
	dfs2(n/2 + 1, 0);
	
	cout << ans << "\n";
	
	return;
}
 
 
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	solve();
	
	return 0;
}
