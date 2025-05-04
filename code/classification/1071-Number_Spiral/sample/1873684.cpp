#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll          long long
#define p7          1000000007
#define p9          998244353
#define pb          push_back
#define ff          first
#define ss          second
#define vll         vector<ll>
#define pll         pair<ll,ll>
#define vpll        vector<pll>
#define mll         map<ll,ll>
#define test        ll T;cin>>T;while(T--)
#define ad(a,n)     vll a;a.resize(n);for(ll i=0;i<n;i++)cin>>a[i];
#define as(a,n)     for(ll i=0;i<n;i++){cout<<a[i]<<" ";}cout<<endl;
#define all(x)      x.begin(),x.end()
 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
ll powm(ll x, ll y, ll m = p7) {
    x = x % m; ll res = 1; while (y)
    {if (y & 1)res = res * x; res %= m; y = y >> 1; x = x * x; x %= m;} return res;
}
ll modi(ll a, ll m = p7) {return powm(a, m - 2, m);}
void yesno(bool f) {f ? cout << "YES" << endl : cout << "NO" << endl;}
 
 
void ss99()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
 
 
int32_t main()
{
    ss99();
    test
    {
        ll x, y; cin >> x >> y;
        if (x == y)
        {
            cout << (x * x - x + 1) << endl;
        }
        else if (x > y)
        {
            ll p = x % 2;
            ll st = (x - p) * (x - p) + p;
            //    cout << "st x>y : " << st << endl;
            //cout << "parity : " << p << endl;
            if (p)
                st += (y - 1);
            else
                st -= (y - 1);
            cout << st << endl;
        }
        else
        {
            ll p = 1 - y % 2;
            ll st = (y - p) * (y - p) + p;
            //  cout << "st x<y :" << st << endl;
            if (p)
                st += (x - 1);
            else
                st -= (x - 1);
            cout << st << endl;
        }
    }
    return 0;
}
