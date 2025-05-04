#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
#define all(x) (x).begin(),(x).end()
const int INF=1000000000+5;
const int N=2e5+5;
const ll oo=1e18+5;
const ll mod=1e9+7;
 
void add_self(int& a,int b){
	a+=b;
	if(a>=mod) a-=mod;
}
 
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,x;
	cin>>n>>x;
	vector<ll> c(n);
	for(ll& x:c) cin>>x;
	vector<ll> dp(x+1,oo);
	dp[0]=0;
	for(int sum=1;sum<=x;++sum){
		for(int i=0;i<n;++i){
			int num=c[i];
			if(sum>=num){
				dp[sum]=min(dp[sum],dp[sum-num]+1);;
			}
		}
	}
	if(dp[x]==oo) dp[x]=-1;
	cout<<dp[x];
	return 0;
}