#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define S second
#define PB push_back
#define MP make_pair
#define F first
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(A) A.begin(),A.end()
int main(){
	FASTIO;
	ll n,x; cin>>n>>x;
	vector<ll> A(n);
	for(ll i=0;i<n;i++) cin>>A[i];
	ll dp[x+1];
	for(ll i=1;i<=x;i++) dp[i]=INT_MAX;
	dp[0]=0;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=x;j++){
			if(j>=A[i-1]){
				dp[j]=min(dp[j],1+dp[j-A[i-1]]);
			}
			// cout<<dp[i][j]<<" ";
		}
		// cout<<endl;
	}
	if(dp[x]==INT_MAX) dp[x]=-1;
	cout<<dp[x];
 
}