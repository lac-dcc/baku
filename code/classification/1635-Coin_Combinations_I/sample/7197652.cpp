#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>   
using namespace std;
#define int long long
#define Fo(x, y, i) for(int i = x; i < y; i++)
#define NFo(x, y, i) for(int i = x; i > y; i--)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const int INF = 1e18;
const int NINF = (-1)*1e18;
const int MOD = 1e9+7;
int power(int x, int y, int p){if(x==0)return 0;int res = 1;x = x % p;
while (y > 0){if (y & 1) res = (res * x) % p; y = y >> 1; x = (x * x) % p;}return res;}
 
int gcd(int a, int b){if(a == 0) return b; return gcd(b % a, a);}
 
int modInverse(int n, int p){return power(n, p - 2, p);}
 
int ncr(int n, int r , int modd){if(r>n){return 0;}if(r>n-r){r = n-r;}int ans = 1;
for(int i = 1; i<=r ; i++){ans *= (n-i+1);ans%= modd;ans *= modInverse(i, modd);ans %= modd;}return ans;}
 
int lcm(int a, int b){ return (a*b)/gcd(a,b);}
 
bool is_prime( int n){if(n==1)return false; int i=2;for(i=2;i*i<=n;i++){if(n%i==0){return false;}}return true;}
//------------------------------------------------------------------------------------------------------------
 
 
 
 
void solve(){
    int n,x;
    cin>>n>>x;
    vector<int> arr(n);
    Fo(0,n,i){
        cin>>arr[i];
    }
    vector<int> dp(x+1, 0);
    dp[0]=1;
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(i-arr[j]>=0){
                dp[i]=(dp[i]+dp[i-arr[j]])%MOD;
            }
        }
    }
    // if(dp[x]==INF) cout<<"-1";
    cout<<dp[x]%MOD;
 
 
 
    
 
 
 
 
 
 
 
   
}
 
 
int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    fast_cin();
    // int t;
    // cin >> t;
    // while(t--) {
    //     solve();
    // }
    solve();
    return 0;
}
