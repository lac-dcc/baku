#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <queue>
#include <stack>
using namespace std;
#define ll long long
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef pair<double,double> pd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<vector<ll>> vll;
typedef vector<vector<int> > vv;
typedef vector<vector<double> > vvd;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<pd> vpd;
#define mod 1000000007
#define mod1 998244353
#define pii 3.14159265358979323846
#define pb push_back
#define fi first
#define se second
#define for_n(i,n) for(int i = 0; i < n; i++)
#define for_se(i,st,n) for(int i = st; i < n; i++)
#define for_rn(i,n) for(int i = n; i >= 0; i--)
#define for_rsn(i,st,en) for(int i = st; i >= en; i--)
 
#define sz(xy) ((int)(xy).size())
#define printYes cout<<"Yes"<<endl;
#define printNo cout<<"No"<<endl;
#define printMin1 cout<<"-1"<<endl;
#define read(n, arr)             \
    for (ll i = 0; i < n; i++) \
    {                          \
        ll k;                  \
        cin >> k;              \
        arr.pb(k);               \
    }
#define FAST_IO    \
    ios_base::sync_with_stdio(false);\
    cin.tie(NULL);
 
#define sortAll(v) sort(begin(v),end(v))
#define reverseAll(v) reverse(begin(v),end(v))
#define newL "\n"
 
ll checkPrime(ll n){
 
    if(n==2 or n==3) return 1;
    if(n == 1 or n%2 == 0 or n%3 == 0) return 0;
 
    for(ll i=5;i*i<=n;i+=6){
        if(n%i == 0 or (n%(i+2) == 0))
            return 0;
    }
    return 1;
}
 
ll power(ll base, ll exp){
 
    if(exp == 0)
        return 1;
    
    ll expH = power(base,exp/2);
 
    if(exp%2)
        return base*expH*expH;
    else
        return expH*expH;
 
}
vector<ll> sieve(ll n){
 
    ll prime[n+1];
    for(int i=2;i<=n;i++)
        prime[i] = 1;
 
    for(ll i=2;i*i<=n;i++){
        if(prime[i]){
            for(ll j=i*i;j<=n;j+=i)
                prime[j] = 0;
        }
    }
 
    vector<ll> primeR;
 
    for(ll i=2;i<=n;i++)
        if(prime[i]) primeR.push_back(i);
    
    return primeR;
}
 
ll findSqrt(ll x) 
{
    ll low = 1, high =x, ans = 0;
 
    while(low<=high){
        ll mid = (low+high)/2;
        if(mid*mid<=x)
            ans = mid,low = mid+1;
        else
            high = mid-1;
    }
        
    return ans;
}
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);   
}
ll max_element(vector<ll> &a){
   return *max_element(begin(a),end(a));
}
ll min_element(vector<ll> &a){
    return *min_element(begin(a),end(a));
}
ll sumArr(vector<ll> &a){
    ll sum = 0;
    for(auto x:a)
        sum+=x;
    return sum;
}
int ceilInt(int a, int b)
{
    return (a-1)/b+1;
}
 
int minWays(int n, vector<int> &dp){
 
    if(n == 0)
        return 0;
    
    if(dp[n]!=-1)
        return dp[n];
 
    int tmp = n;
    int ans = INT_MAX;
 
    while(tmp!=0){
 
        int rem = tmp%10;
        tmp/=10;
 
        if(rem == 0)
            continue;
        
        ans = min(ans,1+minWays(n-rem,dp));
 
    }
 
    return dp[n] = ans;
 
}
signed main(){
    
    FAST_IO
    int t;
    t=1;
    //cin>>t;
    while(t--){
        
        int n,tot;
        cin>>n>>tot;
 
        vector<int> price,page;
 
        read(n,price);
        read(n,page);
 
        vector<int> prev(tot+1,0);
 
        for(int i=0;i<n;i++){
 
            vector<int> curr(tot+1,0);
 
            for(int j=0;j<=tot;j++){
 
                int notPick = prev[j];
                int pick = 0;
 
                if(j>=price[i])
                    pick = prev[j-price[i]]+page[i];
                
                curr[j] = max(pick,notPick);
 
            }
            prev = curr;
        }
        
        cout<<prev[tot]<<newL;
	}
}
