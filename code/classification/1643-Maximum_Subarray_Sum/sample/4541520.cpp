#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
int n;
vector<int> v(n);
 
int solve()
{
    int b{(int)-2e32}, s{0};
    for(int i{0}; i < n; ++i)
    {
        s = max(v[i],s+v[i]);
        b = max(b,s);
    }
    return b;
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> n;
 
    v.resize(n);
 
    for(int i{0}; i < n; ++i)
    {
        int a; cin >> a;
        v[i] = a;
    }
 
    cout << solve() << '\n';
 
}
