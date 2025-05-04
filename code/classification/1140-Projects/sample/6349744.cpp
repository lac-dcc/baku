#include <bits/stdc++.h>
#include <complex>
#include <queue>
#include <stack>
#include <iomanip>
#include <string>
#include <unordered_set>
#include <list>
#include <cmath>
#include <chrono>
#include <map>
#include <iostream>
#include <set>
#include <random>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <fstream>
 
using namespace std;
 
#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma")
#pragma GCC optimize("unroll-loops")
 
#define ll  long long int
#define ull  unsigned long long
#define ld long double
#define lcm(a,b) a*b/__gcd(a,b)
#define gcd(a,b) __gcd(a,b)
#define YES() cout<<"YES\n";
#define NO() cout<<"NO\n";
#define Yes() cout<<"Yes\n";
#define No() cout<<"No\n";
#define no() cout<<"no\n";
#define yes() cout<<"yes\n";
#define out(x) cout<<x<<"\n";return;
#define sz(x) ((ll)(x).size())
#define endline "\n";
#define tcs cout<<"Case #"<<tc<<": ";
 
 
//vectors & pairs
#define all(a) a.begin(),a.end()
#define pb(x) push_back(x)
#define eb(x,y) emplace_back(x,y)
#define vi  vector<int>
#define vll  vector<ll>
#define vull  vector<ull>
#define vf vector<float> 
#define vd vector<double>
#define vld vector<ld>
#define vs vector<string>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll,ll>>
#define vpi vector<pair<int,int>>
#define vvb vector<vector<bool>>
#define vps vector<pair<string,string>>
#define vb vector<bool> 
#define pll pair<ll,ll> 
#define pi pair<int,int>
#define pld pair<ld,ld>
#define pd pair<double,double> 
#define vpd vector<pd>
#define vpld vector<pld>
#define mp make_pair
#define sortVA(a) sort(a.begin(),a.end())
#define sortVD(a) sort(a.rbegin(),a.rend())
 
//map
#define f first
#define s second
 
//constants
double PIE = 3.1415926536;
int MOD = 1000000009;
int MAX = (1e9 + 5);
int MIN = -(1e9 + 5);
ll INF = INT64_MAX;
 
//loop
#define forsn(i,s,e)  for(i=(int)s; i< (int)e; i++)
#define rforsn(i,s,e) for(i=(int)e; i>=(int)s; i--)
#define forn(i,s) for(ll i = 0; i < s; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define vff(a) for(auto x: a)
#define read(a) for(auto &x: a) cin>>x;
#define put(a) for(auto &x: a) cout<<x<<" "; cout<<endline;
 
// global variables
ll i,j;
ll poww(ll a,ll n,ll m)
{
    long long ans = 1;
    long long mul = a;
    while (n != 0)
    {
        if (n % 2)
        {
            ans = (ans * mul) % m;
        }
        mul = (mul * mul) % m;
        n /= 2;
    }
    return ans;
}
//helper functions
ll ceil_div(ll x, ll y){
    return (x + y - 1) / y;
}
void mod(ll &a)
{
    a=((a+MOD)%MOD + MOD)%MOD;
}
//coding starts here
bool comp(vll &A,vll &B)
{
    return A[1]<B[1];
}
void test_cases(ll tc){
    ll n;
    cin>>n;
    vvll temp(n,vll(3));
    forn(i,n)
    {
        cin>>temp[i][1]>>temp[i][0]>>temp[i][2];
    }
    sort(temp.begin(),temp.end());
    vll dp(n);
    dp[0]=temp[0][2];
 
    forsn(i,1,n)
    {
        vll t = {temp[i][1]-1,INT32_MAX,0};
        int ind = upper_bound(temp.begin(),temp.end(),t)-temp.begin()-1;
        if(ind==-1)
        {
            dp[i]= max(temp[i][2],dp[i-1]);
        }
        else if(ind <n && temp[ind][1]<temp[i][1])
        {
            dp[i] = max({dp[i-1],temp[i][2]+dp[ind],dp[i]});
        }
    }
    // put(dp);
    cout<<dp[n-1]<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T=1;
    //cin>>T;
    for (ll tc = 1; tc <=T; tc++)
    {
        test_cases(tc);
    }
    
    return 0;
}
