#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define pb push_back
#define mp make_pair
#define sp setprecision
#define mn INT_MIN
#define mx INT_MAX
#define mem(a,b)     memset(a,b,sizeof(a))
#define F first
#define S second
#define gcd __gcd
#define all(a) a.begin(), a.end()
#define fr(i,j,n)    for(ll i=j;i<n;i++)
#define frr(i,n,j)    for(ll i=n;i>=j;i--)
const long mod=pow(10,9)+7;
const double pi=3.141592653589793238;
//to remove dublicate elements from a vector
void remove(std::vector<int>&v)
{
  auto end = v.end();
  for (auto it = v.begin(); it != end; ++it) {
    end = std::remove(it + 1, end, *it);
  }
 
  v.erase(end, v.end());
} 
 
ll exponentMod(ll A, ll B, ll C)  
{  
    if (A == 0)  
        return 0;  
    if (B == 0)  
        return 1;  
    ll y;  
    if (B % 2 == 0) {  
        y = exponentMod(A, B / 2, C);  
        y = (y * y) % C;  
    }  
    else {  
        y = A % C;  
        y = (y * exponentMod(A, B - 1, C) % C) % C;  
    } 
    return (ll)((y + C) % C);  
} 
void solve()
{
   int n, x;
   cin >> n >> x;
   vector<int> coins(n);
 
   for(int i = 0; i < n; i++) {
    cin >> coins[i];
   }
 
   int dp[x + 1];
 
   for(int i = 0; i <= x; i++) dp[i] = 0;
 
   dp[0] = 1;
   
   for(int i = 1; i <= x; i++) {
    for(int j = 0; j < n; j++) {
        if(i - coins[j] >= 0) {
            dp[i] += dp[i - coins[j]];
        }
 
        dp[i] %= mod;
    }
   }
 
   cout<<dp[x];
 
}
int main()
{
    fast
    #ifndef ONLINE_JUDGE
    freopen("inp.txt","r",stdin);
    freopen("opt.txt","w",stdout);
    #endif
 
    int t=1;
    //cin>>t;
    while(t--)
    {
      solve();
    }
    
  return 0;
}
