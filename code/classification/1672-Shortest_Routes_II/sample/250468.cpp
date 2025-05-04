//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
 
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define ll long long
 
using namespace std;
 
 
int tc;
void file(){
	#ifndef ONLINE_JUDGE
    	freopen("tst.txt", "r", stdin);
	#endif	
}
const int N=1e6+5,MOD=1e9+7;
 
int n,m,q;
 
int main()
{	
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 	//file();
 
 	scanf("%d %d %d",&n,&m,&q);
 	std::vector<vector<pair<int,int>>> g(n+1);
 	std::vector<std::vector<ll>> ans(n+1,std::vector<ll>(n+1,1e18));
 	for(int i=0,a,b,c;i<m;i++){
 		scanf("%d %d %d",&a,&b,&c);
 		ans[a][b]=min(ans[a][b],(ll)c);
 		ans[b][a]=min(ans[b][a],(ll)c);
 	}
 	for(int i=1;i<=n;i++)ans[i][i]=0;
 	for(int i=1;i<=n;i++){
 		for(int j=1;j<=n;j++){
 			for(int k=1;k<=n;k++){
 				ans[j][k]=min(ans[j][k],ans[j][i]+ans[i][k]);
 			}
 		}
 	}
 	while(q--){
 		int a,b;
 		scanf("%d %d",&a,&b);
 		
 		printf("%lld\n",ans[a][b]>=1e18?-1:ans[a][b] );
 		
 	}
}