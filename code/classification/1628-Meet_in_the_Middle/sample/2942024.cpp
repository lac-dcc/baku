#include <bits/stdc++.h>
#define faster ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ff first
#define ss second
#define ll long long
using namespace std;
 
typedef pair<int, int> ii;
 
const int maxn = 41;
const int maxN = 2e6 + 7;
 
int n, m;
int W[maxn], V[maxn];
 
vector<ll> a;
vector<ll> b;
int T[maxN];
 
void sinha ( int pos, int w)
{
    if ( w > m )
        return;
    if ( pos > n / 2 )
    {
        a.push_back ( w );
        return;
    }
    sinha ( pos + 1, w);
    sinha ( pos + 1, w + W[pos]);
}
 
void sinhb ( int pos, int w)
{
    if ( w > m )
        return;
    if ( pos > n )
    {
        b.push_back (w);
        return;
    }
    sinhb ( pos + 1, w);
    sinhb ( pos + 1, w + W[pos]);
}
 
void solve()
{
    sinha ( 1, 0);
    sinhb ( n / 2 + 1, 0);
    sort ( b.begin(), b.end() );
    ll res = 0;
    for ( int i = 0; i < a.size(); ++i )
    {
        int vp = lower_bound(b.begin(),b.end(),m - a[i]) - b.begin();
        int vt = upper_bound ( b.begin(), b.end(), m - a[i]) - b.begin();
        --vt;
        res += vt - vp + 1;
    }
    cout << res;
}
 
void input()
{
    cin >> n >> m;
    for ( int i = 1; i <= n; ++i )
        cin >> W[i];
}
 
signed main()
{
    faster;
    input();
    solve();
}
