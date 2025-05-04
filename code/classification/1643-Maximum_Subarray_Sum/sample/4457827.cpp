#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pll pair<ll, ll>
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n, mx = LLONG_MIN;
    cin>>n;
    ll i, x, sum = 0;
    for (i = 1; i<=n; i++){
        cin>>x;
        sum += x;
        mx = max(mx, sum);
        if (sum < 0) sum = 0;
    }
    cout<<mx;
}