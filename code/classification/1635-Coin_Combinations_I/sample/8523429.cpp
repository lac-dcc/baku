#include <bits/stdc++.h>
using namespace std;
#define inta long long int
#define pb push_back
#define ff first
#define ss second
#define vi vector<inta>
#define pf push_front
#define popb pop_back
#define popf pop_front
#define all(a) a.begin(), a.end()
#define mp make_pair
#define mod 1000000007
#define nl '\n'
inta gcd(inta a, inta b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
inta lcm(inta a, inta b)
{
    return (a / gcd(a, b)) * b;
}
bool compare(pair<inta, inta> &p1, pair<inta, inta> &p2)
{
    if (p1.first != p2.first)
        return p1.first > p2.first;
    return p1.second < p2.second;
}
inta max(inta a, inta b)
{
    if (a > b)
        return a;
    return b;
}
inta min(inta a, inta b)
{
    if (a < b)
        return a;
    return b;
}
inta computeXOR(inta n)
{
    if (n % 4 == 0)
        return n;
    if (n % 4 == 1)
        return 1;
    if (n % 4 == 2)
        return n + 1;
    return 0;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inta uid(inta l, inta r) { return uniform_int_distribution<inta>(l, r)(rng); }
#define fast_io                  \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define out(v)                         \
    for (inta i = 0; i < v.size(); i++) \
    {                                  \
        cout << v[i] << " ";           \
    }                                  \
    cout << nl;
#define pre(pref, v)                   \
    for (inta i = 0; i < v.size(); i++) \
    {                                  \
        pref.push_back(v[i]);          \
        if (i >= 1)                    \
            pref[i] += pref[i - 1];    \
    }
#define suf(suff, v)                        \
    for (inta i = 0; i < v.size(); i++)      \
    {                                       \
        suff.push_back(v[i]);               \
    }                                       \
    for (inta i = v.size() - 2; i >= 0; i--) \
    {                                       \
        suff[i] += suff[i + 1];             \
    }
#define read(v, n)              \
    for (inta i = 0; i < n; i++) \
    {                           \
        inta p;                  \
        cin >> p;               \
        v.push_back(p);         \
    }
    inta f(inta sum,vi &cost,vector<inta>&dp){
        if(sum<0){
            return 0;
        
 
        }
        if(sum==0){
            return 1;
        }
        if(dp[sum]!=-1){
            return dp[sum]%mod;
        }
        inta ans = 0;
        for(inta i = 0;i<cost.size();i++){
            // if(sum>=cost[i]){
                ans +=f(sum-cost[i],cost,dp)%mod;
            // }
        }
        return dp[sum] =  ans%mod;
    }
void solve()
{
    inta n, sum;
    cin >> n >> sum;
    vi cost;
    read(cost, n);
    vector<inta>dp(sum+1,-1);
    inta ans = f(sum,cost,dp);
    
    cout<<ans<<nl;
}
int main()
{
    fast_io;
    solve();
 
    return 0;
}
