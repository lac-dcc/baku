#pragma GCC optimize("Ofast")
//#pragma GCC target("fma")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define FAST_IO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define int long long
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define memset(a,val) memset(a,val,sizeof a)
 
int32_t main(){
	FAST_IO;
	int n,m;
	cin>>m>>n;
	vector<int> c(m);
	for(int i=0;i<m;++i){
		cin>>c[i];
	}
	int dp[n+1];
	for(int i=0;i<=n;++i){
		dp[i] = 0;
	}
	dp[0] = 1;
    for(int  i=0;i<c.size();++i){
    	for(int j=c[i];j<=n;++j){
    		dp[j] = (dp[j] + dp[j-c[i]])%mod;
    	}
    }
    cout<<dp[n]<<endl;
	return 0;
}
