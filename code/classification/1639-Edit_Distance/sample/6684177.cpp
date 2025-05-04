#include <bits/stdc++.h>
#include <ostream>
using namespace std;
 
#define F first
#define S second
#define PB push_back
#define MP make_pair
long long M=1e9+7;
typedef long long ll;
set<string> st;
 
// typedef vector<int> vi;
// typedef pair<int,int> pi;
// typedef map<int,int> m;
// typedef stack<int> st;
 
ll MEX(vector<ll> v)
{
    sort(v.begin(), v.end());
    ll mex = 0;
    for (ll i = 0; i < v.size(); i++)
    {
        if (mex == v[i])
            mex += 1;
    }
    return mex;
}
void solve()
{
    ll i, c = 1, mx=1, n, k;
    cin >> n;
    vector<ll>v;
    i=1;
    while(n%i==0)
    {
        i++;v.push_back(i);
    }
    
    cout<<i-1<<"\n";
}
 
ll find(ll n, ll m, string &a, string &b, vector<vector<ll>> &dp)
{
    if(n<0)return m+1;
    if(m<0)return n+1;
    if(dp[n][m]!=-1)return dp[n][m];
    ll ans=0;
    if(a[n]==b[m])ans=find(n-1,m-1,a,b,dp);
    else
    {
        ans=min(find(n-1,m-1,a,b,dp)+1,min(find(n-1,m,a,b,dp)+1,find(n,m-1,a,b,dp)+1));
    }
    return dp[n][m]=ans;
}
 
int main()
{
    string a,b;cin>>a>>b;
    ll n=a.size(),m=b.size();
    vector<vector<ll>> dp(n+1,vector<ll>(m+1,-1));
    ll ans = find(n-1,m-1,a,b,dp);
    cout<<ans;
    return 0;
}
