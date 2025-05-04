//CP on CF
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
 
#define fori(a, n) for(ll i = a; i < n; i++)
#define ford(a, n) for(ll i = a; i > n; i--)
#define forri(j, a, n) for(ll j = a; j < n; j++)
#define forrd(j, a, n) for(ll j = a; j > n; j--)
 
#define all(x) x.begin(),x.end()
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
 
ll mod = 1e9+7;
ll mod1 = 998244353;
 
//gcd based on Euclid's algorithm
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
ll lcm(ll a, ll b)
{
    if(a==0)
        return b;
    if(b==0)
        return a;
    return (a*b)/gcd(a, b);
}
 
bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    for (ll i = 2; i*i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}
 
ll ModPow(ll a, ll b, ll M)
{
    if(M == 1) return 0;
    a %= M;
    ll ans = 1, t = 1;
    while(t <= b)
    {
        if(t&b)
        {
            ans *= a;
            ans %= M;
        }
        t <<= 1;
        a *= a;
        a %= M;
    }
    return ans;
}
 
ll modInverse(ll n, ll p)
{
    return ModPow(n, p - 2, p);
}
 
ll nCrModP(ll n, ll r, ll p)
{
    if (n < r)
        return 0;
    if (r == 0)
        return 1;
 
    ll fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;
 
    return (fac[n] * modInverse(fac[r], p) % p* modInverse(fac[n - r], p) % p)% p;
}
 
//LLONG_MAX
// priority_queue<int>pq;
//(for min priority queue) priority_queue<int,vector<int>,greater<int>>pq;
// use functions like pq.push(*), pq.pop(), pq.top(), pq.empty()
// queue<int>q
//reverse(all(a))
// __gcd(a,b) takes O(log n) where n=max(a,b);
bool compare(vi& a, vi& b)
{
    return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
}
 
bool is_vowel(char c)
{
    c=tolower(c);
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}
 
template <typename T>
T debug(vector<T>& ans)
{
    fori(0,ans.size())
        cout<<ans[i]<<" ";
    cout<<"\n";
}
// call this function like this : cout<< debug<int>(ans) <<endl;
 
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set
 
//------------------------------SOLVE()----------------------------------//
/* THINK THE PROBLEM THOROUGHLY BEFORE STARTING TO CODE PLEASE!! */
void solve()
{
    ll n, k;
    cin>>n>>k;
 
    vll a(k);
    fori(0, k) {
        cin>>a[i];
    }
 
    ll ans = 0;
    for(int i = 1; i < (1<<k); i++) {
        ll cur = 1, active = 0, f = 0;
        for(int j = 0; j < k; j++) {
            if(i&(1<<j)) {
                if(n / cur / a[j] > 0) {
                    cur *= a[j];
                    active++;
                } else {
                    f = 1;
                    break;
                }
            }
        }
        if(!f && active % 2) {
            ans += n / cur;
        } else if(!f) {
            ans -= n / cur;
        }
    }
    cout<<ans;
}
 
//-------------------------------MAIN()----------------------------------//
 
int main()
{
    //io sync makes cin and cout faster
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
 
    int tc;
    tc=1;
    //cin>>tc;
    //int case_tc=1;
    while(tc--)
    {
        solve();
        //cout<<solve();
        //memset(dp, -1, sizeof(dp)); // sets all the values by 0 or -1;
        //cout<<fixed<<setprecision(15)<<ans;
        //getline(cin, str);
    }
 
    return 0;
}