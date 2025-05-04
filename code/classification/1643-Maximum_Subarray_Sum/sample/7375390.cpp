#include <bits/stdc++.h>
 
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
 
#define endl "\n"
#define ll long long int
 
using namespace std;
 
vector<ll> v;
ll max_of_this(ll l, ll mid, ll r)
{
    ll sum = 0;
    ll left_sum = LLONG_MIN;
    for (ll i = mid; i >= l; i--)
    {
        sum += v[i];
        if (sum > left_sum)
            left_sum = sum;
    }
    sum = 0;
    ll right_sum = LLONG_MIN;
    for (ll i = mid + 1; i <= r; i++)
    {
        sum += v[i];
        if (sum > right_sum)
            right_sum = sum;
    }
    return left_sum + right_sum;
}
ll max_sum(ll l, ll r)
{
    if (l == r)
        return v[r];
    if (r < l)
        return LLONG_MIN;
    ll mid = (r + l) / 2;
    return max(max_sum(l, mid), max(max_sum(mid + 1, r), max_of_this(l, mid, r)));
}
 
int main()
{
    fastio;
    ll n;
    cin >> n;
    v.push_back(0);
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        v.push_back(x);
    }
    cout << max_sum(1, n) << endl;
    return 0;
}