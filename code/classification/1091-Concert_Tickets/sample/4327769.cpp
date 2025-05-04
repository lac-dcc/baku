#include <bits/stdc++.h>
#define endl '\n'
typedef long long unsigned int llu;
typedef long long ll;
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define Yes cout<<"Yes\n"
#define No cout<<"No\n"
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define all(x) (x).begin(), (x).end()
#define f(i,a,n) for(int i=a;i<n;i++)
#define fr(i,n,a) for(int i=n;i>=a;i--)
#define in0(arr,n) f(i,0,n) cin>>arr[i];
#define in1(arr,n) f(i,1,n+1) cin>>arr[i];
#define print0(arr,n) f(i,0,n) {cout<<arr[i]<<' ';}cout<<endl;
#define print1(arr,n) f(i,1,n+1) {cout<<arr[i]<<' ';}cout<<endl;
#define test int t;cin>>t;f(tc,1,t+1)
const int mod = 1e9 + 7;
using namespace std;
bool prime[10000001];
 
 
/*
 __        __
|  \ |__| |__| |  | \  /
|__/ |  | | \  |__|  \/
 __   __   _     ___   _    __   _   ___ ___
|__| |__| /_\     |   /_\  |__| /_\   |   |
|    | \ /   \ \__|  /   \ |   /   \  |  _|_
 
*/
 
 
ll gcd(ll a, ll b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}
 
ll lcm(ll a,ll b)
{
    return (a / gcd(a, b)) * b;
}
 
ll sumDigit(ll n,ll val=0)
{
    return (n==0)?0:(n%10 + sumDigit(n/10));
}
 
ll isPow2(ll x)
{
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return x ^ (x >> 1);
}
 
bool pal(string s)
{
    int len=s.length();
    f(i,0,len/2)
    {
        if(s[i]!=s[len-i-1]) return false;
    }
    return true;
}
 
void sieve(ll n)
{
    memset(prime, true, sizeof(prime));
    prime[0]=prime[1]=false;
    for (int p = 2; p * p <= n; p++)
    {
        if(prime[p]==true)
        {
            for(int i=p*p; i<=n; i+=p) prime[i] = false;
        }
    }
}
 
void solve()
{
    ll n,m;cin>>n>>m;
    multiset<ll> chk;
    f(i,0,n)
    {
        ll x;cin>>x;
        chk.insert(x);
    }
    vll t(m);
    f(i,0,m)
    {
        cin>>t[i];
    }
    f(i,0,m)
    {
        ll x=t[i];
        auto highValue = chk.upper_bound(x);
        if(highValue == chk.begin())
        {
            cout<<-1<<endl;
        }
        else
        {
            --highValue;
            cout<<(*highValue)<<endl;
            chk.erase(highValue);
        }  
    }   
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    // test
    // {
        solve();
    //}
    return 0;
}
