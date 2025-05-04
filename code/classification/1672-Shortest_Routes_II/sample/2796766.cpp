#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M = 500;
const int inf = 1e18;
vector<pair<int,int>> graph[M];
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,m,q; cin>>n>>m>>q;
	int dp[502][502];
	for(int i = 1; i < 502; ++i){
		for(int j = 1; j < 502; ++j){
			dp[i][j] = inf;
		}
	}
	for(int i = 1; i < 502; ++i){
		dp[i][i] = 0;
	}
	for(int i = 0; i < m; ++i){
		int a,b,c; cin>>a>>b>>c;
		dp[a][b] = dp[b][a] = min(dp[a][b],c);
	}
 
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			for(int k = 1; k <= n; ++k){
				dp[j][k] = min(dp[j][k],dp[j][i] + dp[i][k]);
			}
		}
	}
	for(int i = 0; i < q; ++i){
		int a,b; cin>>a>>b;
		if(dp[a][b] == inf){
			cout<<-1<<"\n";
			continue;
		}
		cout<<dp[a][b]<<"\n";
	}
	return 0;
}
