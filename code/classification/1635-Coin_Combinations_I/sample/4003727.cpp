#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
 
 
int main() {
   fast_io;
   ll t,n,m,x,i,j,k,q;
   //cin >> t;
   t = 1;
   while(t--)
   {
        cin >> n >> x;
        vector<int> v(n);
        int dp[x+1];
        fr(0,n)
            cin >> v[i];
        dp[0] = 1;
		for (int i= 1; i <= x; i++)
		{
			dp[i] = 0; 
			for (int coin_value: v)
				if (coin_value <= i)
					dp[i]=(dp[i] + dp[i-coin_value])%mod;
		}
		cout << dp[x];
    }
    return 0;
}
	
 