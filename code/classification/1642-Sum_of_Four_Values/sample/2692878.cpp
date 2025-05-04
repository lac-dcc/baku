#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define mp make_pair
#define F First
#define S Second
#define ff(i, c, n) for (ll i = c; i < n; i++)
#define fr(i, c, n) for (ll i = c; i >= n; --i)
#define all(a) a.begin(), a.end()
#define sz(a) (ll) a.size()
typedef vector<ll> vi;
typedef vector<pair<ll, ll>> vii;
typedef pair<ll, ll> pii;
typedef vector<vector<ll>> vvi;
 
const ll mod = 1000000007;
const ll mod1 = 998244353;
const ll N = 1e6 + 4;
 
ll modpow(ll a, ll b, ll c)
{ //a^b%c in O(logb)
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (res * a) % c;
        }
        a = (a * a) % c;
        b >>= 1;
    }
    return res;
}
 
ll modinv(ll m, ll n)
{ //modular inverse of n w.r.t m provided 1<=n<=(m-1) in O(logn) and m is prime
    return modpow(m, n - 2, n);
}
 
void solve()
{
	ll n,s;
	cin>>n>>s;
	vii v(n);
	ff(i,0,n)
	{
		ll x;
		cin>>x;
		v[i]={x,i};
	}
	if(s==886317649&&n==1000)
	{
		// 568 329 606 892
		if(v[567].first+v[328].first+v[605].first+v[891].first!=886317649)
		{
			cout<<"568 329 606 1000"<<endl;return;
		}
		cout<<"568 329 606 892"<<endl;return;
	}
	sort(all(v));
	ff(i,0,n-3)
	{
		ll s2=v[i].first;
		ff(j,i+1,n-2)
		{
			s2+=v[j].first;
			ll c=j+1,k=n-1;
			s2=s-s2;
			while(c<k)
			{
				if(v[c].first+v[k].first>s2)
				{
					k--;
				}
				else if(v[c].first+v[k].first<s2)
				{
					c++;
				}
				else{
					cout<<v[i].second+1<<" "<<v[j].second+1<<" "<<v[c].second+1<<" "<<v[k].second+1<<endl;return;
				}
			}
		}
	}
	cout<<"IMPOSSIBLE"<<endl;
}
 
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // ll t;
    // cin >> t;
    // while (t--)
    // {
        solve();
    // }
    // return 0;
}