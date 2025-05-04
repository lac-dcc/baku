//بسم الله الرحمن الرحيم
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pi 3.14159265358979323846
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
#define For(start,end,step) for(ll i=start;i<=end;i+=step)
#define For2(start,end,step) for(ll j=start;j<=end;j+=step)
#define mult(x,y) x*(y-1)
#define ALL(x) x.begin(), x.end()
using namespace std;
using namespace __gnu_pbds;
const ll mod=1e9+7;
bool prime(ll n)
{
for(int i=2;i*i<=n;i++)if(n%i==0)return 0;
return 1;
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll po(ll x,ll y)
{
    if(y==0) return 1;
    ll ret=po(x,y/2);
    ret=(ret*ret);
    if(y&1)
        return (x*ret);
    return ret;
}
ll sigma(ll s,ll e,ll num_elements)
{
    ll res1=s+e;
    ll res=(((s+e)/2)*(num_elements));
    if(res1%2)res+=num_elements/2;
    return res;
}
ll mod_inverse(ll x)
{
    return po(x,mod-2);
}
string to_lower_case(string s)
{
    for(int i=0;i<s.size();i++)
    {
        if(int(s[i])<97)
        {
            s[i]=char(int(s[i])+32);
        }
    }
    return s;
}
string to_upper_case(string s)
{
    for(int i=0;i<s.size();i++)
    {
        if(int(s[i])>=97)
        {
            s[i]=char(int(s[i])-32);
        }
    }
    return s;
}
ll GP(ll base,ll power,ll step)
{
    return (po(base,power+step)+mod-1)%mod*mod_inverse(po(base,step)-1)%mod;
}
ll fact(ll x)
{
    if(x<2)return 1;
    return x*fact(x-1)%mod;
}
ll ncr(ll x,ll y)
{
    return fact(x)*mod_inverse(fact(y)*fact(x-y)%mod)%mod;
}
bool valid(ll x,ll y,ll n,ll m)
{
    return(x>=0&&y>=0&&x<n&&y<m);
}
int dx[8]= {0,0,1,-1,-1,1,1,-1};
int dy[8]= {-1,1,0,0,-1,1,-1,1};
 
const int N=2e5+5;
const int M=3e6+5;
 
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    ll prefix_sum[n];
    for(int i=0;i<n;i++)
    {
        cin>>prefix_sum[i];
        if(i>0)
        {
            prefix_sum[i]+=prefix_sum[i-1];
        }
    }
    ll mn=0;
    ll mx=-1e18;
    for(int i=0;i<n;i++)
    {
        mx=max(mx,prefix_sum[i]-mn);
        mn=min(mn,prefix_sum[i]);
    }
    cout<<mx;
}