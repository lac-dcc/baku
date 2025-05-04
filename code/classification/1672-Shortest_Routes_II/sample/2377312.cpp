// Ac
#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;
#define mod 1000000007
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i,a,b) for(int i=a;i<b;i++)
#define endl "\n"
#define PI 3.14159265358979323846  /* pi */
#define is_pot(n) (n&& !(n&(n-1)))
#define all(v)  ((v).begin()),((v).end())
#define degreesToRadians(angleDegrees) (angleDegrees * PI / 180.0) // Converts degrees to radians.
#define radiansToDegrees(angleRadians) (angleRadians * 180.0 / PI) // Converts radians to degrees.
#define int long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define epsilon 1e-9
typedef long long ll;
typedef long double ld;
 
int dx[]={1, 0, -1, 0};
int dy[]={0, 1, 0, -1};
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
void solve()
{
	int n, m, q;
	cin>>n>>m>>q;
 
	vector<vector<int>> dis(n+1, vector<int>(n+1, 1e17));
 
	rep(i, m)
	{
		int a, b, c;
		cin>>a>>b>>c;
		dis[a][b]=min(dis[a][b], c);
		dis[b][a]=min(dis[b][a], c);
	}
 
	for(int i=1;i<=n;i++)
		dis[i][i]=0;
 
	for (int k = 1; k <= n; ++k) 
	{
    	for (int i = 1; i <= n; ++i) 
    	{
        	for (int j = 1; j <= n; ++j) 
        	{
            	if (dis[i][k] < 1e17 && dis[k][j] < 1e17)
                	dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]), dis[j][i]=dis[i][j]; 
        	}
    	}
	}
	while(q--)
	{
		int a, b;
		cin>>a>>b;
		if(dis[a][b]<1e17 || dis[b][a]<1e17)
			cout<<min(dis[a][b], dis[b][a])<<endl;
		else
			cout<<-1<<endl;
	}
}
 
signed main() {
 
   	fastio
 
    	// int t;cin>>t;while(t--)
	    solve();
 
 
return 0;
}
