#include<bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define gcd __gcd
#define getl(s) getline(cin, s);
#define setpre(x) fixed << setprecision(x)
#define mset(a) memset(a, 0, sizeof(a))
#define endl '\n'
const int N=2000050,M=1000000007;
const ll INF=1e18+7;
 
ll n, k, a[N], dp[N];
 
int main(){
	ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
//    freopen(".inp","r",stdin);
//    freopen(".out","w",stdout);
	cin>>n>>k;
	for(ll i=0; i<n; i++) cin>>a[i];
	
	memset(dp, 0, sizeof dp);
	dp[0]=1;
	for(ll i=1; i<=k; i++){
		for(ll j=0; j<n; j++){
			if(i>=a[j]) dp[i]+=dp[i-a[j]];
			dp[i]%=M;
		}
	}
	cout<<dp[k];
    return 0;
}	