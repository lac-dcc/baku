#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define double long double
#define pii pair<int, int>
#define N 1e5+5
int32_t mod = 1000000007;
 
void solveCase()
{
	int n;
	cin >> n;
	vector<pair<int, bool>> v;
	int a, b;
	while(n--)
	{
		cin >> a >> b;
		v.push_back({a, true});
		v.push_back({b, false});
	}
	int ans = -1, curr = 0;
	sort(v.begin(), v.end());
	for(int i=0; i< (int)v.size(); i++)
	{
		if(v[i].second)
			curr++;
		else
			curr--;
		ans = max(ans, curr);
	}
	
	cout << ans ;
	
	
}
 
int32_t main()
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    // int t = 0;
    // cin >> t;
    // while (t--)
        solveCase();
}
