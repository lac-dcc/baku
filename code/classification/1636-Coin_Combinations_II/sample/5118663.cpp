#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
const int inf = INT_MAX;
const ll INF = LLONG_MAX;
const double PI = 3.141592653589793;
const ll MOD = 998244353;
const ll mod = 1e9 + 7;
 
#define fr(i, a, b, d) for(ll i = a; i < b; i += d)
#define rf(i, a, b, d) for(ll i = a; i >= b; i -= d)
 
ll max(ll x, ll y){if(x>y) return x;return y;}
ll min(ll x, ll y){if(x<y) return x;return y;}
ll max(ll x, ll y, ll z){return max(x,max(y,z));}
ll min(ll x, ll y, ll z){return min(x,min(y,z));}
 
#define traverse(container, it)\
	for (auto it = container.begin(); it != container.end(); it++)
 
#define pb push_back
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	ll n,x;
	// cin >> T;
	// while(T-->0){
		cin >>n>>x;
        int coin[n];
        vector<ll> dp(1e6+1,0);
		// dp[1]=1;
        fr(i,0,n,1){
            cin>>coin[i];
            // dp[coin[i]]=1;
        }
        dp[0]=1;
		
        for(auto y: coin){
            fr(i,1,x+1,1){
                // cout<<y;
                if(i-y>=0){
                    dp[i]=dp[i]+dp[i-y];
                    dp[i]%=mod;
                }
            }
        }
            cout<<dp[x]<<endl;
		
	// }
	return 0;
}
