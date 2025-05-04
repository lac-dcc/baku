#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define RollNo_001_Since_2008         \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#pragma GCC optimize("O2")
#define ll long long int
#define all(v) (v).begin(), (v).end()
#define sum(v) accumulate(all(v), 0ll)
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> os1;
typedef tree<ll,null_type,greater_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> os2;
 
const int N = 1e5 + 10;
vector<bool> isPrime(N, 1);
void sieve()
{
    isPrime[0] = isPrime[1] = false;
    for (ll i = 0; i < N; i++)
    {
        if (isPrime[i] == true)
        {
            for (ll j = 2 * i; j < N; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}
ll fastpow(ll a, ll b)
{
    ll ans = 1;
    ll n = 1000000007;
    while (b > 0)
    {
        if ((b & 1) != 0)
            ans = (ans * (a % n)) % n;
        a = ((a % n) * (a % n)) % n;
        b = b >> 1;
    }
    return ans;
}
bool cmp(pair<ll, ll> &a, pair<ll, ll> &b)
{
    return a.second > b.second;
}
 
void d1(vector<ll> &v)
{
    for (auto val : v)
        cout << val << " ";
    cout << endl;
}
void take(vector<ll> &v, ll &n)
{
    for (ll i = 0; i < n; i++)
    {
        ll ele;
        cin >> ele;
        v.push_back(ele);
    }
}
//---------------------------------------------------------
long long binpow(long long a, long long b)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
void solve()
{   
ll n;cin>>n;
ll sum;cin>>sum;
vector<ll> v;
take(v,n);
multimap<ll,ll> mst;
for(ll i=0;i<n;i++) mst.insert({sum-v[i],i});
// for(auto it:mst) cout<<it.first<<" "<<it.second<<endl;
 
for(ll i=0;i<n;i++){
    auto it=mst.find(v[i]);
    if(it!=mst.end() && it->second!=i){
        cout<<it->second+1<<" "<<i+1;
        return;
    }
}
cout<<"IMPOSSIBLE";
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //   freopen("output.txt","w",stdout);
#endif
    // clock_t tStart = clock();
 
    RollNo_001_Since_2008;
    // sieve();
 
    double t = 1;
    // cin >> t;
 
    while (t--)
        solve();
 
    // printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}