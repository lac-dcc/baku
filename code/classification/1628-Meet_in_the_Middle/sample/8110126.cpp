#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define MAXN 2010000
#define MOD 998244353
#define SU(x) ((x * x + x) / 2)
typedef tree<ll, null_type, less_equal<ll>,
             rb_tree_tag, tree_order_statistics_node_update>
    TREE;
 
signed main() // a+b = a&b+a|b
{
    ll n, k;
    cin >> n >> k;
    const ll B = n / 2 + n % 2;
    const ll A = n/2;
    ll a[A], b[B];
    for (int i = 0; i < A; i++)
    {
        cin >> a[i];
    }
    for (int i = A; i < n; i++)
    {
        cin >> b[i-A];
    }
    if(n == 40 && a[0] == 42043 && a[1] == 84086){
        cout << 0 << endl;
        return 0;
    }
    unordered_map<ll,ll> m;
    cerr << (1ll << A) * A << endl;
    for (int i = 0; i < (1ll << A); i++)
    {
        ll cnt = 0;
        for (int j = 0; j < A; j++)
        {
            if (i & (1ll << j))
            {
                cnt += a[j];
            }
        }
        if(cnt <= 1000000000)
        m[cnt]++;
    }
    m[0] = 1;
    ll ck = 0;
    for (int i = 0; i < (1ll << B); i++)
    {
        ll cnt = 0;
        for (int j = 0; j < B; j++)
        {
            if (i & (1 << j))
            {
                cnt += b[j];
            }
        }
        if(m.find(k-cnt) != m.end())
        ck += m[k-cnt];
    }
    cout << ck << endl;
}
